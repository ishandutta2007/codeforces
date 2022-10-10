// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;
const int N = 25;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

template<size_t N, typename T>
class max_flow {
public:
    class edge {
    public:
        int to;
        T cap, flow;

        edge() = default;

        edge(int _to, T _cap) : to(_to), cap(_cap), flow(T()) {} 
    };

    max_flow() {
        edges.reserve(2 * N);
    }

    void clear() {
        for (int i = 0; i < N; ++i) {
            g[i].clear();
        }
        edges.clear();
    }

    void reset_flow() {
        for (int i = 0; i < (int)edges.size(); ++i) {
            edges[i].flow = T();
        }
    }

    void add_edge(int from, int to, int cap) {
        g[from].push_back((int)edges.size());
        edges.push_back(edge(to, cap));
        g[to].push_back((int)edges.size());
        edges.push_back(edge(from, 0));
    }

    bool bfs(int s, int t) {
        memset(d, -1, sizeof(d));

        d[s] = 0;
        q[0] = s;
        int head = 0, tail = 1;
        while (head < tail) {
            int v = q[head++];
            for (auto i : g[v]) {
                auto&[to, cap, flow] = edges[i];
                if (d[to] == -1 && flow < cap) {
                    d[to] = d[v] + 1;
                    q[tail++] = to;
                }
            }
        }

        return d[t] != -1;
    }

    T dfs(int v, int t, T curPushed) {
        if (curPushed == T() || v == t) {
            return curPushed;
        }

        for (; ptr[v] < (int)g[v].size(); ++ptr[v]) {
            int i = g[v][ptr[v]];
            auto&[to, cap, flow] = edges[i];
            if (d[to] != d[v] + 1 || cap == flow) {
                continue;
            }
            T pushed = dfs(to, t, std::min(curPushed, cap - flow));
            if (pushed != T()) {
                edges[i].flow += pushed;
                edges[i ^ 1].flow -= pushed;
                return pushed;
            }
        }

        return 0;
    }

    T find_max_flow(int s, int t) {
        T flow = T();

        while (bfs(s, t)) {
            memset(ptr, 0, sizeof(ptr));

            while (true) {
                T pushed = dfs(s, t, std::numeric_limits<T>::max());
                if (pushed == T()) {
                    break;
                }
                flow += pushed;
            }
        }

        return flow;
    }

    std::vector<int> g[N];
    std::vector<edge> edges;
    int d[N], q[N], ptr[N];
};

int n, m;
char a[N][N];
int d[N][N][N][N];
 
int fx1[N * N], fy1[N * N], s1[N * N];
int fx2[N * N], fy2[N * N], s2[N * N];
 
bool isCorrect(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
 
void bfs(int sx, int sy) {
    memset(d[sx][sy], -1, sizeof(d[sx][sy]));
    if (a[sx][sy] == '#') {
        return;
    }
 
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(sx, sy));
    d[sx][sy][sx][sy] = 0;
 
    while (!q.empty()) {
        auto[x, y] = q.front();
        q.pop();
 
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
 
            if (isCorrect(newX, newY) && a[newX][newY] != '#' && d[sx][sy][newX][newY] == -1) {
                d[sx][sy][newX][newY] = d[sx][sy][x][y] + 1;
                q.push(std::make_pair(newX, newY));
            }
        }
    }
}

max_flow<N * N * 4 + 2, int> dinic;
int males, females;
bool check(ll x) {
    int allV = males + females + 2 * n * m + 2;
    // max_flow<N * N * 4 + 2, int> dinic;
    dinic.clear();
    int s = allV - 1, t = allV - 2;
 
    for (int i = 0; i < males; ++i) {
        dinic.add_edge(s, i, 1);
    }
    for (int i = 0; i < females; ++i) {
        dinic.add_edge(males + i, t, 1);
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                continue;
            }
 
            int code = m * i + j;
            dinic.add_edge(males + females + code, males + females + code + n * m, 1);
        }
    }
 
    for (int id = 0; id < males; ++id) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '#') {
                    continue;
                }
 
                int dist = d[i][j][fx1[id]][fy1[id]];
                if (dist == -1 || 1ll * dist * s1[id] > x) {
                    continue;
                }
 
                int code = i * m + j;
                dinic.add_edge(id, males + females + code, 1);
            }
        }
    }
 
    for (int id = 0; id < females; ++id) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '#') {
                    continue;
                }
 
                int dist = d[i][j][fx2[id]][fy2[id]];
                if (dist == -1 || 1ll * dist * s2[id] > x) {
                    continue;
                }
 
                int code = i * m + j;
                dinic.add_edge(males + females + code + n * m, males + id, 1);
            }
        }
    }
 
    return dinic.find_max_flow(s, t) == males;
}
 
void run() {
    scanf("%d%d%d%d", &n, &m, &males, &females);
 
    if (abs(males - females) != 1) {
        printf("-1\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        scanf("\n%s", a[i]);
    }
 
    if (males < females) {
        ++males;
        for (int i = 0; i < males; ++i) {
            scanf("%d%d%d", &fx1[i], &fy1[i], &s1[i]);
            --fx1[i];
            --fy1[i];
        }
        for (int i = 0; i < females; ++i) {
            scanf("%d%d%d", &fx2[i], &fy2[i], &s2[i]);
            --fx2[i];
            --fy2[i];
        }
    } else {
        ++females;
        for (int i = 0; i < 1; ++i) {
            scanf("%d%d%d", &fx2[i], &fy2[i], &s2[i]);
            --fx2[i];
            --fy2[i];
        }
        for (int i = 0; i < males; ++i) {
            scanf("%d%d%d", &fx1[i], &fy1[i], &s1[i]);
            --fx1[i];
            --fy1[i];
        }
        for (int i = 1; i < females; ++i) {
            scanf("%d%d%d", &fx2[i], &fy2[i], &s2[i]);
            --fx2[i];
            --fy2[i];
        }
    }
 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bfs(i, j);
        }
    }
 
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         std::cout << d[0][0][i][j] << ' ';
    //     }
    //     std::cout << '\n';
    // }
 
    ll l = -1, r = (ll)1e18;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
 
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
 
    if (r == (ll)1e18) {
        printf("-1\n");
        return;
    }
    printf("%lld\n", r);
}
 
int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);
 
    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();
 
    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif
 
    return 0;
}