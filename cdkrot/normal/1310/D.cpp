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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    
#ifdef LOCAL
    std::mt19937 rnd(31031999);
#else
    uint64_t seed = (uint64_t)(new char());
    std::mt19937 rnd(seed ^ 228);
#endif

    int64_t ans = TYPEMAX(int64_t);
    while (clock() <= (clock_t)(2.8 * CLOCKS_PER_SEC)) {
        vector<char> colors(n);
        for (int i = 0; i < n; ++i)
            colors[i] = rnd() % 2;

        int64_t inf = TYPEMAX(int64_t) / 3;
        vector<int64_t> dp(n, inf);
        dp[0] = 0;

        for (int it = 0; it < k; ++it) {
            vector<int64_t> new_dp(n, inf);

            for (int v = 0; v < n; ++v)
                for (int u = 0; u < n; ++u)
                    if (colors[v] != colors[u])
                        new_dp[v] = min(new_dp[v], dp[u] + graph[v][u]);

            dp = std::move(new_dp);
        }

        ans = min(ans, dp[0]);
    }

    cout << ans << "\n";
    
    return 0;
}