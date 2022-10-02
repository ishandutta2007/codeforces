#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

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


const int MAXN = 120000;
vector<int> aa[MAXN];
int U[MAXN];
int scomp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N, M, H;
    cin >> N >> M >> H;
    for (int i = 0; i < N; i++) cin >> U[i];
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if ((U[a]+1)%H == U[b]) aa[a].push_back(b);
        if ((U[b]+1)%H == U[a]) aa[b].push_back(a);
    }
    int chosen = -1;
    int res = N;
    auto scc = FindSCC(N, aa);
    // dbg_var(scc);
    for (int i = 0; i < (int)scc.size(); i++) for (int v : scc[i]) scomp[v] = i;
    for (int i = 0; i < (int)scc.size(); i++) {
        bool sink = true;
        for (int v : scc[i]) for (int a : aa[v]) {
            if (scomp[a] != i) {
                sink = false;
                break;
            }
        }
        if (sink and res >= (int)scc[i].size()) {
            res = min(res, (int)scc[i].size());
            chosen = i;
        }
    }
    cout << res << "\n";
    for (int v : scc[chosen]) cout << v+1 << " ";
}