#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

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

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


// Given a graph (whose edges are specified via AddEdge), it computes an
// Eulerian path (or cycle) starting from a certain vertex.
// 
// If the graph is disconnected, the Eulerian path (or cycle) will traverse
// only the connected component of the initial vertex.
// If an Eulerian cycle exists, it will be returned.
// If an Eulerian path exists, it will be returned.
// See the description of GetEulerianTour for the precise behavior.
//
// The graph can be directed or undirected
// The graph can contain both self-loops and multiple edges.
// The vertices are indexed 0, 1, ..., V-1.
// For directed graphs the algorithm is easier (the structures reverse_edge,
// used_edge are not used for directed graphs).
class EulerianPath {
  public:
    EulerianPath(int V, bool is_directed) :
            V(V),
            is_directed(is_directed),
            aa(V),
            iterator_position(V, 0),
            reverse_edge(V), 
            used_edge(V) {}

    // Add edge u-v (directed is is_directed is set to true) to the graph.
    void AddEdge(int u, int v) {
        if (is_directed) aa[u].push_back(v);
        else {
            aa[u].push_back(v);
            used_edge[u].push_back(false);
            if (u != v) {
                aa[v].push_back(u);
                used_edge[v].push_back(false);
                reverse_edge[v].push_back(aa[u].size()-1);
            }
            reverse_edge[u].push_back(aa[v].size()-1);
        }
    }

    // Returns a vector containing the vertices of a Eulerian path (or
    // cycle) starting from v (if it exists).
    // More precisely it returns a sequence P[...] of vertices such that:
    //  1. P[0] = v
    //  2. The graph contains the edge P[i] - P[i+1].
    //  3. Each edge (of the connected component) is present exactly once
    //     as P[i] - P[i+1].
    // ACHTUNG: If there is not such a P[..] (i.e., it is not possible to
    //          traverse all edges of the connected component) the the behavior
    //          is undefined.
    //          Of course, it is possible to check in linear time whether such
    //          a P[...] exists (depending on the parity of the degrees in the
    //          undirected case, and on the differences between in-degree and
    //          out-degree in the directed case).
    //
    // Examples:
    // If the graph is 0->1, 1->2, 2->0; and the initial vertex is 0,
    // the function returns {0, 1, 2, 0}.
    //
    // If the graph is 0->1, 1->2; and the initial vertex is 0,
    // the function returns {0, 1, 2}.
    //
    // If the graph is 0->0, 0->1, 1->2, 1->2, 2->1; and the initial vertex is 0,
    // the function returns {0, 0, 1, 2, 1, 2}.
    //
    // ACHTUNG: This function can be called only once (per connected component).
    //          If you need to call it more than once on the same connected
    //          component, remember to reset iterator_position, used_edge,
    //          tmp_path, final_path.
    vector<int> GetEulerianPath(int v) {
        dfs(v);
        reverse(final_path.begin(), final_path.end());
        return final_path;
    }

  private:
    void dfs(int v) {
        // tmp_path.push_back(v);
        int& i = iterator_position[v];
        while (i < (int)aa[v].size()) {
            if (!is_directed and used_edge[v][i]) {
                i++;
                continue;
            }
            int a = aa[v][i];
            if (!is_directed) {
                used_edge[v][i] = true;
                used_edge[a][reverse_edge[v][i]] = true;
            }
            i++;
            dfs(a);
        }
        final_path.push_back(v);
        // tmp_path.pop_back();
    }
    
    int V;
    bool is_directed;
    vector<vector<int>> aa;
    vector<int> iterator_position;
    vector<vector<int>> reverse_edge;
    vector<vector<bool>> used_edge;

    vector<int> tmp_path, final_path;
};



vector<int> aa[1<<20];
int val[1<<20];
bool visited[1<<20];

void dfs(int v) {
    visited[v] = true;
    for (int a: aa[v]) {
        if (visited[a]) continue;
        dfs(a);
    }
}

LL to_num(int a, int b) { return a + (((LL)b)<<21); }



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!


    int N;
    cin >> N;
    for (int i = 1; i < 2*N; i += 2) {
        cin >> val[i] >> val[i+1];
    }

    for (int k = 20; k >= 0; k--) {
        for (int i = 1; i <= 2*N; i++) val[i] &= (1<<k)-1;
        for (int i = 0; i < (1<<k); i++) {
            aa[i].clear();
            visited[i] = false;
        }
        for (int i = 1; i <= 2*N; i += 2) {
            aa[val[i]].push_back(val[i+1]);
            aa[val[i+1]].push_back(val[i]);
        }
        int cc = 0;
        int z;
        bool works = true;
        for (int i = 0; i < (1<<k); i++) {
            if (!aa[i].empty() and !visited[i]) {
                z = i;
                dfs(i);
                cc++;
            }
            if (aa[i].size()%2) works = false;
        }
        works &= cc == 1;
        if (!works) continue;

        EulerianPath G(1<<k, false);
        for (int i = 1; i <= 2*N; i += 2) G.AddEdge(val[i], val[i+1]);

        vector<int> final_path = G.GetEulerianPath(z);
        unordered_map<LL, vector<int>> nums;
        for (int i = 1; i < 2*N; i += 2) {
            nums[to_num(val[i], val[i+1])].push_back(i);
        }
        cout << k << "\n";
        for (int i = 0; i < SZ(final_path)-1; i++) {
            int a = final_path[i], b = final_path[i+1];
            if (!nums[to_num(a, b)].empty()) {
                int id = nums[to_num(a, b)].back();
                nums[to_num(a, b)].pop_back();
                cout << id << " " << id+1 << " ";
            } else {
                int id = nums[to_num(b, a)].back();
                nums[to_num(b, a)].pop_back();
                cout << id+1 << " " << id << " ";
            }
        }
        cout << "\n";
        return 0;
        
    }
}