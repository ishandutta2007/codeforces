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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 200200;
vector<int> aa[MAXN];
vector<LL> ww[MAXN];

bool visited[MAXN];
LL ot[MAXN];
void dfs(int v) {
    // dbg(v, ot[v]);
    visited[v] = true;
    for (int i = 0; i < SZ(aa[v]); i++) {
        int a = aa[v][i];
        LL w = ww[v][i];
        if (visited[a]) continue;
        ot[a] = ot[v] + w;
        dfs(a);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--, v--;
        aa[u].push_back(v);
        ww[u].push_back(l);
    }
    auto scc = FindSCC(n, aa);
    for (int v = 0; v < n; v++) if (!visited[v]) dfs(v);
    
    vector<int> comp(n);
    vector<LL> gg(n, 0);
    for (int i = 0; i < SZ(scc); i++) for (int v: scc[i]) comp[v] = i;
    for (int v = 0; v < n; v++) {
        for (int i = 0; i < SZ(aa[v]); i++) {
            int a = aa[v][i];
            LL w = ww[v][i];
            LL d = ot[a] - ot[v];
            if (comp[v] != comp[a]) continue;
            int c = comp[v];
            gg[c] = __gcd(gg[c], llabs(w-d));
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v;
        LL s, t;
        cin >> v >> s >> t;
        v--;
        LL g = __gcd(gg[comp[v]], t);
        if (s % g) cout << "NO\n";
        else cout << "YES\n";
    }
    
}