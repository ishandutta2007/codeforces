// Dmitry _kun_ Sayutin (2020)

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
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n), rgraph(n);

    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;

        graph[v].push_back(u);
        rgraph[u].push_back(v);
    }

    vector<int> dp(n, TYPEMAX(int));
    dp[0] = 0;

    std::deque<int> q;
    q.push_front(0);
    while (not q.empty()) {
        int v = q.front();
        q.pop_front();

        const auto& direct = (dp[v] % 2 == 0 ? graph : rgraph);
        const auto& revers = (dp[v] % 2 == 1 ? graph : rgraph);
        
        for (int u: direct[v])
            if (dp[u] > dp[v]) {
                dp[u] = dp[v];
                q.push_front(u);
            }
        for (int u: revers[v])
            if (dp[u] > dp[v] + 1) {
                dp[u] = dp[v] + 1;
                q.push_back(u);
            }
    }

    const int LOG = 30;
    int dpgo[n][LOG];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < LOG; ++j)
            dpgo[i][j] = TYPEMAX(int);

    dpgo[0][0] = 0;

    std::set<tuple<int, int, int>> queue;
    queue.emplace(dpgo[0][0], 0, 0);

    while (not queue.empty()) {
        int v = get<1>(*queue.begin());
        int lvl = dp[v] + get<2>(*queue.begin());
        queue.erase(queue.begin());

        const auto& direct = (lvl % 2 == 0 ? graph : rgraph);
        const auto& revers = (lvl % 2 == 1 ? graph : rgraph);
        
        for (int u: direct[v]) {
            if (lvl >= dp[u] + LOG)
                continue;

            if (dpgo[u][lvl - dp[u]] > dpgo[v][lvl - dp[v]] + 1) {
                queue.erase(make_tuple(dpgo[u][lvl - dp[u]], u, lvl - dp[u]));
                
                dpgo[u][lvl - dp[u]] = dpgo[v][lvl - dp[v]] + 1;

                queue.insert(make_tuple(dpgo[u][lvl - dp[u]], u, lvl - dp[u]));
            }
        }

        for (int u: revers[v]) {
            if (lvl + 1 >= dp[u] + LOG)
                continue;
            
            if (dpgo[u][lvl + 1 - dp[u]] > dpgo[v][lvl - dp[v]] + 1) {
                queue.erase(make_tuple(dpgo[u][lvl + 1 - dp[u]], u, lvl + 1 - dp[u]));
                
                dpgo[u][lvl + 1 - dp[u]] = dpgo[v][lvl - dp[v]] + 1;

                queue.insert(make_tuple(dpgo[u][lvl + 1 - dp[u]], u, lvl + 1 - dp[u]));
            }
        }        
    }

    const int mod = 998244353;
    int pbest = -1;
    for (int i = 0; i < LOG; ++i)
        if (dpgo[n - 1][i] != TYPEMAX(int)) {
            if (pbest == -1) {
                pbest = i;

                if (dp[n - 1] >= LOG)
                    break;
                continue;
            }

            auto L = dpgo[n - 1][pbest] + (int64_t(1) << (dp[n - 1] + pbest)) - 1;
            auto R = dpgo[n - 1][i    ] + (int64_t(1) << (dp[n - 1] +     i)) - 1;

            if (L > R)
                pbest = i;
        }

    int pw = 1;
    for (int num = 0; num < dp[n - 1] + pbest; ++num)
        pw = (pw + pw) % mod;
    --pw;
    
    cout << (dpgo[n - 1][pbest] + pw) % mod << "\n";
    
    return 0;
}