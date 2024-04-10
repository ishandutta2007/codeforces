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



const int MAXN = 22;
int N;
bool val[1<<MAXN];

// Take a graph in adjacency list form and computes the strongly connected
// components. Instead of calling directly this class, the user should
// use the wrapper function FindSCC.
// The graph vertices must be numbered from 0 to V-1.
// The graph can contain both self-loops and multiple edges.
struct StronglyConnectedComponents {
    StronglyConnectedComponents(int V) :
            V(V),
            current_time(0),
            opening_time(V, NOT_VISITED),
            on_stack(V, false),
            low_link(V),
            res(0) {
        for (int v = 0; v < V; v++) {
            if (opening_time[v] == NOT_VISITED) {
                FindStrongComponents(v);
            }
        }
    }
    const static int NOT_VISITED = -1;
    int V;
    //const vector<int>* aa;  // edges of the graph.
    int current_time;
    vector<int> opening_time;
    vector<bool> on_stack; // Whether the vertex is currently on stack.
    vector<int> low_link;  // The lowest opening time of a vertex reachable from
                           // v through vertices that are not its ancestors.
    int res;
    vector<int> current_stack;

    void FindStrongComponents(int v) {
        opening_time[v] = low_link[v] = current_time;
        current_time++;
        on_stack[v] = true;
        current_stack.push_back(v);
        for (int i = 0; i < N; i++) {
            if (v&(1<<i)) continue;
            int a = v^(1<<i);
            if (opening_time[a] == NOT_VISITED) {
                FindStrongComponents(a);
                low_link[v] = min(low_link[v], low_link[a]);
            } else if (on_stack[a]) {
                low_link[v] = min(low_link[v], low_link[a]);
            }
        }
        if (val[((1<<N)-1)^v]) {
            int a = ((1<<N)-1)^v;
            if (opening_time[a] == NOT_VISITED) {
                FindStrongComponents(a);
                low_link[v] = min(low_link[v], low_link[a]);
            } else if (on_stack[a]) {
                low_link[v] = min(low_link[v], low_link[a]);
            }
        }
        if (low_link[v] == opening_time[v]) {
            bool is_full = false;
            while (1) {
                int u = current_stack.back();
                current_stack.pop_back();
                on_stack[u] = false;
                is_full |= val[u];
                // components.back().push_back(u);
                if (u == v) break;
            }
            if (is_full) res++;
        }
    }
};
const int StronglyConnectedComponents::NOT_VISITED;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        val[x] = true;
    }
    // const vector<vector<int>>& vec = StronglyConnectedComponents(1<<N).GetComponents();
    // int res = 0;
    // for (auto& comp : vec) {
    //     for (int x : comp) {
    //         if (val[x]) {
    //             res++;
    //             break;
    //         }
    //     }
    // }
    cout << StronglyConnectedComponents(1<<N).res << "\n";
}