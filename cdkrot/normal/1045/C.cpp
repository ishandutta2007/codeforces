// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;
using std::queue;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int v, u;
        v = input<int>() - 1;
        u  = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int N = n;
    vector<vector<int>> tree(N);

    vector<int> depth(n, -1);
    vector<int> up(n, -1);

    vector<pair<int, int>> edge_stack;
    auto unroll = [&](int tm) {
        set<int> mentioned;

        while (edge_stack.size() > tm) {
            mentioned.insert(edge_stack.back().first);
            mentioned.insert(edge_stack.back().second);
            edge_stack.pop_back();
        }

        int v = N++;
        tree.push_back(vector<int> {});
        
        for (int u: mentioned) {
            tree[v].push_back(u);
            tree[u].push_back(v);
        }
    };
    
    std::function<void(int, int)> dfs = [&](int v, int p) {
        depth[v] = (p == -1 ? 0 : depth[p] + 1);
        up[v] = depth[v];

        for (int u: graph[v])
            if (u != p) {
                if (depth[u] == -1) { // new
                    int tm = SZ(edge_stack);
                    edge_stack.emplace_back(v, u);
                    
                    dfs(u, v);
                    up[v] = min(up[v], up[u]);

                    if (up[u] >= depth[v])
                        unroll(tm); // kukareku!
                } else if (depth[u] < depth[v]) { // going up
                    edge_stack.emplace_back(v, u);
                    up[v] = min(up[v], depth[u]);
                }
            }   
    };

    dfs(0, -1);

    vector<int> dep(N, -1);
    int LOG = 0;
    while ((1 << LOG) < N)
        ++LOG;

    #define up up_
    vector<vector<int>> up(LOG + 1, vector<int>(N, -1));
    
    std::function<void(int, int)> dfs2 = [&](int v, int p) {
        dep[v] = (p == v ? 0 : dep[p] + 1);
        up[0][v] = p;
        
        for (int l = 1; l <= LOG; ++l)
            up[l][v] = up[l - 1][up[l - 1][v]];

        for (int u: tree[v])
            if (u != p)
                dfs2(u, v);
    };

    dfs2(0, 0);

    for (int i = 0; i < q; ++i) {
        int a = input<int>() - 1;
        int b = input<int>() - 1;

        if (not (dep[a] >= dep[b]))
            swap(a, b);

        int ans = 0;
        for (int i = LOG; i >= 0; --i)
            if (dep[a] - (1 << i) >= dep[b])
                a = up[i][a], ans += (1 << i);

        if (a != b) {
            for (int i = LOG; i >= 0; --i)
                if (up[i][a] != up[i][b])
                    a = up[i][a], b = up[i][b], ans += (2 << i);

            ans += 2;
        }

        cout << ans / 2 << "\n";
    }
    
    return 0;
}