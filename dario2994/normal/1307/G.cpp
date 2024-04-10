#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

// Returns a random integer from the range [l, r].
LL randint(LL l, LL r) {
	#if DEBUG && !ONLINE_JUDGE
	static mt19937_64 gen; // Deterministic on the local machine.
	#else
	static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
	#endif
	return uniform_int_distribution<LL>(l, r)(gen);
}

template <typename Iterator>
string print_iterable(Iterator begin, Iterator end, string bef, string aft,
        function<string(typename iterator_traits<Iterator>::value_type)>* f = nullptr) {
    stringstream res;
    res << bef;
    bool is_first = true;
    for (Iterator it = begin; it != end; ++it) {
        if (!is_first) res << ", ";
        if (f != nullptr) res << (*f)(*it);
        else res << *it;
        is_first = false;
    }
    res << aft;
    return res.str();
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

#define _define_print_container(Container, bef, aft)        \
template <typename T>                                       \
ostream& operator <<(ostream& out, const Container<T>& v) { \
    out << print_iterable(v.begin(), v.end(), bef, aft);    \
    return out;                                             \
}                                                           \

_define_print_container(vector, "[", "]");
_define_print_container(set, "{", "}");
_define_print_container(unordered_set, "{", "}");
_define_print_container(multiset, "{", "}");
_define_print_container(unordered_multiset, "{", "}");
_define_print_container(deque, "[", "]");

#define _define_print_dictionary(Dictionary, bef, aft)                      \
template <typename T1, typename T2>                                         \
ostream& operator <<(ostream& out, const Dictionary<T1, T2>& v) {           \
    out << print_iterable(v.begin(), v.end(), bef, aft);                    \
    return out;                                                             \
}                                                                           \

_define_print_dictionary(map, "{", "}");
_define_print_dictionary(unordered_map, "{", "}");

#define _define_print_container_adaptor(Adaptor, OP)                        \
template <typename T>                                                       \
ostream& operator <<(ostream& out, Adaptor<T> a) {                          \
    vector<T> v;                                                            \
    while (!a.empty()) v.push_back(a.OP()), a.pop();                        \
    out << v;                                                               \
    return out;                                                             \
}                                                                           \

_define_print_container_adaptor(stack, top)
_define_print_container_adaptor(queue, front)
_define_print_container_adaptor(priority_queue, top)

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
    #define dbg_arr(x, len) \
    clog << #x << ": " << print_iterable(x, x+len, "[", "]") << endl;
    #define dbg_arr1(x, len) \
    clog << #x << ": " << print_iterable(x+1, x+len+1, "[", "]") << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
    #define dbg_arr1(x, len)
#endif


// Implementation of the Edmonds-Karp algorithm for the maximum flow of minimum
// cost. Dijkstra algorithm with potentials is used to find shortest paths.
//
// Complexity: MlogN*min(FLOW, NM) (behaves better in practice).
// In its league (i.e., among the augmenting-path based algorithms) this is
// rather fast (it performs similarly to the implementation in the KACTL
// notebook), but there are much faster algorithms for the problem.
// The adaptation of the push-relabel algorithm is considered the best for the
// minimum cost max flow problem and it is *much* faster than the algorithm
// implemented here. A working implementation can be found at
//  github.com/dacin21/dacin21_codebook/blob/master/flow/mincost_PRonly.cpp

#include <vector>
#include <queue>
#include <limits>
using namespace std;

// This class accepts a graph (costructed calling AddEdge) and then solves
// the maximum flow of minimum cost problem for any source and sink.
// Both directed and undirected graphs are supported. In case of undirected
// graphs, each edge must be added twice.
// The template parameter T is the type of both the capacities and the costs.
//
// The cost of the edges must be nonnegative. If negative cost edges are present
// two steps must be performed before executing the algorithm:
//  1. Saturate all negative cycles (using SPFA).
//  2. Compute the initial potentials with an algo different from Dijkstra.
//
// To compute the maximum flow of minimum cost call
// GetMinCostMaxFlow(source, sink).
// If you are also interested in the actual flow values, look at the
// flow variable in each edge with positive capacity. The edges are stored
// in a vector (named edges) and those with null capacity are the residual
// graph edges.

template <typename T>
struct MinCostMaxFlow {
    const T INF = numeric_limits<T>::max()/2;
    struct Edge {
        int u, v;
        T cap, flow, cost, pos_cost;
        // pos_cost stands for positive cost (actually nonnegative).
        // It is defined as cost + pot[u] - pot[v] where pot is an appropriate
        // potential (which changes after each augmenting-path is found.
        Edge() {}
        Edge(int u, int v, T cap, T cost):
                u(u), v(v), cap(cap), flow(0), cost(cost), pos_cost(cost) {}
    };
    
    int N;
    vector<Edge> edges; // The "inverse" edge of edges[i] is edges[i^1].
    vector<vector<int>> aa; // Stores the index of the edge in the edges vector.
    // dist is the distance with respect to pos_cost (computed using Dijkstra).
    // previous[v] is the index of the edge from the father of v to v in the
    // shortest paths tree.
    vector<T> dist;
    vector<int> previous;
  
    MinCostMaxFlow(int N): N(N), edges(0), aa(N), dist(N), previous(N) {}

    void AddEdge(int u, int v, T cap, T cost) {
        if (u != v) {
            edges.push_back(Edge(u, v, cap, cost));
            aa[u].push_back(edges.size() - 1);
            // The inverse edge has 0 capacity and opposite cost.
            edges.push_back(Edge(v, u, 0, -cost));
            aa[v].push_back(edges.size() - 1);
        }
    }

    // Computes all distances from source (in the residual graph) and stores
    // them in dist.
    // It returns true if sink is reachable from source.
    bool Dijkstra(int source, int sink) {
        typedef pair<T, int> PI;
        priority_queue<PI, vector<PI>, greater<PI>> q;
        q.push({0, source});
        fill(dist.begin(), dist.end(), INF);
        dist[source] = 0;
        while(!q.empty()) {
            PI pp = q.top(); q.pop();
            int u = pp.second;
            int d = pp.first;
            if (d > dist[u]) continue;
            for (int k : aa[u]) {
                Edge &e = edges[k];
                if (e.flow < e.cap && dist[e.v] > dist[e.u] + e.pos_cost) {
                    previous[e.v] = k;
                    dist[e.v] = dist[e.u] + e.pos_cost;
                    q.push({dist[e.v], e.v});
                }
            }
        }
        return dist[sink] != INF;
    }

    // Returns the pair {flow, cost}.
    // Assumption: source != sink
    vector<T> GetAllCosts(int source, int sink) {
        for (Edge& e : edges) e.flow = 0, e.pos_cost = e.cost;
        T flow = 0;
        T cost = 0;
        vector<T> costs = {0};
        while (Dijkstra(source, sink)) {
            T path_cap = INF;
            for (int v = sink; v != source; v = edges[previous[v]].u) {
                path_cap = min(path_cap,
                               edges[previous[v]].cap - edges[previous[v]].flow);
            }
            flow += path_cap;
            for (int v = sink; v != source; v = edges[previous[v]].u) {
                edges[previous[v]].flow += path_cap;
                edges[previous[v]^1].flow -= path_cap;
                cost += edges[previous[v]].cost * path_cap;
            }
            // for (int v = 0; v < N; v++) pot[v] += dist[v];
            for (Edge& e : edges) e.pos_cost += dist[e.u] - dist[e.v];

            costs.push_back(cost);
        }
        return costs;
    }
};

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!


    int n, m;
    cin >> n >> m;

    MinCostMaxFlow<int> mcmf(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mcmf.AddEdge(u, v, 1, w);
    }

    vector<int> c = mcmf.GetAllCosts(1, n);

    int q;
    cin >> q;
    cout.precision(10);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        double best = 1e20;
        for (int i = 1; i < SZ(c); i++) best = min(best, ((double)c[i] + x) / i);
        cout << fixed << best << "\n";
    }
}