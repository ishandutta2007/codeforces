// 2018, Sayutin Dmitry.

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define pb push_back
#define eb emplace_back

#define int int64_t

struct edge_t {
    int to;
    int flow;
    int cap;
    int next;
};

int push(vector<int>& head, vector<edge_t>& edges, vector<int>& dist, int v, int snk, int lim) {
    if (v == snk)
        return lim;
    
    while (head[v] != -1) {
        auto& e = edges[head[v]];
        
        int tmp;
        if (e.flow < e.cap and dist[e.to] == dist[v] + 1 and (tmp = push(head, edges, dist, e.to, snk, min(lim, e.cap - e.flow))) != 0) {
            e.flow += tmp;
            edges[head[v] ^ 1].flow -= tmp;
            return tmp;
        } else {
            head[v] = e.next;
        }
    }
    
    return 0;
}

int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int m = input<int>();

    vector<int> head(2 + n + m, -1);
    vector<edge_t> edges;
    int S = 0;
    int T = 1;
    int OFFV = 2;
    int OFFE = 2 + n;

    int INF = 1e15;
    
    auto add_edge = [&](int a, int b, int cap) {
        edges.push_back(edge_t {b, 0, cap, head[a]});
        head[a] = SZ(edges) - 1;

        edges.push_back(edge_t {a, 0, 0, head[b]});
        head[b] = SZ(edges) - 1;
    };

    for (int i = 0; i != n; ++i) {
        add_edge(OFFV + i, T, input<int>());
    }

    int64_t BASE = 0;
    for (int i = 0; i != m; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;
        int w = input<int>();

        add_edge(OFFE + i, OFFV + v, INF);
        add_edge(OFFE + i, OFFV + u, INF);

        BASE -= w;
        add_edge(S, OFFE + i, w);
    }

    while (true) {
        vector<int> dist(SZ(head), TYPEMAX(int));
        dist[S] = 0;
        
        std::queue<int> q;
        q.push(S);
        
        while (not q.empty()) {
            int v = q.front();
            q.pop();
            
            for (int e = head[v]; e != -1; e = edges[e].next)
                if (edges[e].flow < edges[e].cap and dist[edges[e].to] > dist[v] + 1) {
                    dist[edges[e].to] = dist[v] + 1;
                    q.push(edges[e].to);
                }
        }
        
        if (dist[T] == TYPEMAX(int))
            break;
        
        auto head_copy = head;
        int tmp;
        while ((tmp = push(head_copy, edges, dist, S, T, TYPEMAX(int))) != 0) {
            BASE += tmp;
        }
    }

    cout << -BASE << "\n";
    
    return 0;
}