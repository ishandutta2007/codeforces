#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

// Take a graph in adjacency list form and computes the strongly connected
// components. Instead of calling directly this class, the user should
// use the wrapper function FindSCC.
// The graph vertices must be numbered from 0 to V-1.
// The graph can contain both self-loops and multiple edges.
class StronglyConnectedComponents {
  public:
    StronglyConnectedComponents(int V, const vector<int> aa[]) :
            V(V),
            aa(aa),
            current_time(0),
            opening_time(V, NOT_VISITED),
            on_stack(V, false),
            low_link(V) {
        for (int v = 0; v < V; v++) {
            if (opening_time[v] == NOT_VISITED) {
                FindStrongComponents(v);
            }
        }
    }
    
    vector<vector<int>> GetComponents() {
        // ACHTUNG: The components are in REVERSED topological order.
        return components;
    }

  private:
    const static int NOT_VISITED = -1;
    int V;
    const vector<int>* aa;  // edges of the graph.
    int current_time;
    vector<int> opening_time;
    vector<bool> on_stack; // Whether the vertex is currently on stack.
    vector<int> low_link;  // The lowest opening time of a vertex reachable from
                           // v through vertices that are not its ancestors.
    vector<vector<int>> components;
    vector<int> current_stack;

    void FindStrongComponents(int v) {
        opening_time[v] = low_link[v] = current_time;
        current_time++;
        on_stack[v] = true;
        current_stack.push_back(v);
        for (int a : aa[v]) {
            if (opening_time[a] == NOT_VISITED) {
                FindStrongComponents(a);
                low_link[v] = min(low_link[v], low_link[a]);
            } else if (on_stack[a]) {
                low_link[v] = min(low_link[v], low_link[a]);
            }
        }
        if (low_link[v] == opening_time[v]) {
            components.emplace_back();
            while (1) {
                int u = current_stack.back();
                current_stack.pop_back();
                on_stack[u] = false;
                components.back().push_back(u);
                if (u == v) break;
            }
        }
    }
};
const int StronglyConnectedComponents::NOT_VISITED;

// Simple wrapper function to use instead of the above class.
// Returns the strongly connected components in topological order.
vector<vector<int>> FindSCC(int V, const vector<int> aa[]) {
    StronglyConnectedComponents scc(V, aa);
    auto components = scc.GetComponents();
    reverse(components.begin(), components.end());
    return components;
}


// Given a list of and-linked disjunctive clauses with no more than two
// variables each, decides whether the expression can be evaluated true with
// a proper choice of the variables' values. If that is the case, such an
// assignment of values is produced.
// The expression has the form:
//      (x_i or x_j) and (x_u or !x_v) and (!x_w) ...
// To define the expression the following method are available:
//      AssignVariable, AddImplication, AddClause (clause = disjunctive clause).
// After having called such method, you can call IsSatisfiable and
// GetAssignment to get the satisfiabily and eventual solution of the problem.
// For example, the problem
//      (x or !y) and (!x) and (y or !z) and (z or x) and (y -> x)
// is described by the following calls (x -> 0, y -> 1, z -> 2):
//      TwoSatisfiability(3) // 3 variables
//      AddClause(0, true, 1, false) // x or !y
//      AssignVariable(0, false) // !x
//      AddClause(1, true, 2, false) // y or !z
//      AddClause(2, true, 0, true) // z or x
//      AddImplication(1, true, 0, true) // y -> x
// Such a problem is not satisfiable and therefore a call to IsSatisfiable
// would return false.
class TwoSatisfiability {
  public:
    TwoSatisfiability(int variables_num) :
            variables_num(variables_num),
            aa(new vector<int>[2 * variables_num]()),
            computed(false),
            satisfiable(true),
            assignment(variables_num) {}

    // Add a disjunctive clause, namely
    //      (variable1 == value1) or (variable2 == value2)
    // Both AssignVariable and AddImplication rely on this method.
    void AddClause(int variable1, bool value1, int variable2, bool value2) {
        aa[2*variable1 + !value1].push_back(2*variable2+value2);
        aa[2*variable2 + !value2].push_back(2*variable1+value1);
    }

    // Set a variable to the given value. Specifically it adds the clause
    //      variable == value
    // If the variable was set previously it is NOT overwritten and if the
    // values are different the problem is considered unsatisfiable.
    void AssignVariable(int variable, bool value) {
        AddClause(variable, value, variable, value);
    }

    // Add an implication clause, namely
    //      (variable1 == value1) --> (variable2 == value2)
    void AddImplication(int variable1, bool value1, int variable2, bool value2) {
        AddClause(variable1, !value1, variable2, value2);
    }

    // Returns whether the problem is satisfiable.
    bool IsSatisfiable() {
        ComputeAnswer();
        return satisfiable;
    }

    // Returns a possible assignment satisfying the problem.
    // Precondition: The problem must be satisfiable.
    vector<bool> GetAssignment() {
        ComputeAnswer();
        assert(satisfiable);
        return assignment;
    }
  private:
    // Number of variables. Variables labels are 0-based.
    int variables_num;
    // The edges of the inference graph of the clauses.
    // The proposition (var_id == false) is identified by the vertex 2*var_id
    // whereas the proposition (var_id == true) has index 2*var_id+1.
    // An edge from u to v means that if u holds then v holds.
    vector<int>* aa;
    bool computed;  // Whether the answer has already been computed.
    bool satisfiable;  // Whether the problem is satisfiable.
    vector<bool> assignment; // The value assigned to each variable.

    void ComputeAnswer() {
        if (computed) return;
        computed = true;
        const vector<vector<int>>& scc = FindSCC(variables_num*2, aa);
        vector<int> var2comp(2*variables_num);
        for (int i = 0; i < (int)scc.size(); i++) {
            for (int var : scc[i]) var2comp[var] = i;
        }
        for (int i = 0; i < variables_num; i++) {
            if (var2comp[2*i] == var2comp[2*i+1]) {
                satisfiable = false;
                return;
            }
            assignment[i] = var2comp[2*i] < var2comp[2*i+1];
        }
        satisfiable = true;
    }
};

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 2e5 + 100;
vector<int> aa[MAXN];
vector<int> tt[MAXN];
int ans[MAXN];

bool dfs(int v) {
    for (int i = 0; i < SZ(aa[v]); i++) {
        int a = aa[v][i];
        int t = tt[v][i];
        if (ans[a] == -1) {
            ans[a] = ans[v] ^ t;
            if (!dfs(a)) return false;
        }
        if (ans[a] != (ans[v]^t)) return false;
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> edges(n-1);
    vector<int> vals(n-1);

    auto add_edge = [&](int x, int y, int v) {
        aa[x].push_back(y);
        aa[y].push_back(x);
        tt[x].push_back(v);
        tt[y].push_back(v);
    };
    
    for (int i = 0; i < n-1; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        edges[i] = {x, y};
        vals[i] = v;
        if (v >= 0) {
            if (__builtin_popcount(v)%2 == 0) add_edge(x, y, 0);
            else add_edge(x, y, 1);
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        add_edge(a, b, p);
    }

    bool works = true;
    for (int i = 1; i <= n; i++) ans[i] = -1;
    for (int v = 1; v <= n; v++) {
        if (ans[v] == -1) {
            ans[v] = 0;
            works &= dfs(v);
        }
    }
    
    for (int i = 1; i <= n; i++) aa[i].clear(), tt[i]. clear();
    if (!works) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n-1; i++) {
            int a = edges[i].first, b = edges[i].second;
            cout << a << " " << b << " ";
            if (vals[i] >= 0) cout << vals[i] << "\n";
            else cout << (ans[edges[i].first]^ans[edges[i].second]) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!


    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}