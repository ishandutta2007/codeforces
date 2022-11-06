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

const int max_n = 2e5;
int dp[max_n][2];

void upd_m2(pair<int, int>& a, int x) {
    if (x > a.first)
        a.second = a.first, a.first = x;
    else if (x > a.second)
        a.second = x;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int ans = 0;
    std::function<void(int, int)> dfs = [&](int v, int p) {
        for (auto go: graph[v])
            if (go != p) {
                dfs(go, v);
            }

        int ans_unpainted = 0;
        pair<int, int> best2 = {0, 0};

        pair<int, int> best2_painted = {0, 0};
        
        for (auto u: graph[v])
            if (u != p) {
                ans_unpainted += 1;
                upd_m2(best2, max(dp[u][0], dp[u][1]) - 1);

                upd_m2(best2_painted, dp[u][0]);
            }

        ans = max(ans, (p != -1) + ans_unpainted + best2.first + best2.second);
        ans = max(ans, 1 + best2_painted.first + best2_painted.second);

        dp[v][1] = 1 + best2_painted.first; // i'm painted.
        dp[v][0] = ans_unpainted + best2.first;
    };

    dfs(0, -1);
    cout << ans << "\n";

    return 0;
}