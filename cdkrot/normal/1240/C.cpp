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
    for (int q = input<int>(); q != 0; --q) {
        int n = input<int>();
        int k = input<int>();

        vector<vector<pair<int, int>>> graph(n);
        for (int i = 1; i < n; ++i) {
            int v = input<int>() - 1;
            int u = input<int>() - 1;
            int w = input<int>();
            graph[v].emplace_back(u, w);
            graph[u].emplace_back(v, w);
        }

        std::function<pair<int64_t, int64_t>(int, int)> dfs = [&](int v, int p) {
            vector<int64_t> ch;
            int64_t base = 0;

            for (auto u: graph[v])
                if (u.first != p) {
                    auto rs = dfs(u.first, v);

                    base += rs.first;
                    ch.emplace_back(max(int64_t(0), rs.second + u.second - rs.first));
                }

            if (SZ(ch) >= k)
                std::nth_element(ch.begin(), ch.begin() + (k - 1), ch.end(), std::greater<int>());
            
            pair<int64_t, int64_t> res = {base, base};
            for (int kk: {k, k - 1}) {
                int64_t& pans = (kk == k ? res.first : res.second);

                for (int i = 0; i < kk and i < SZ(ch); ++i)
                    pans += ch[i];
            }

            return res;
        };

        auto rs = dfs(0, -1);
        cout << max(rs.first, rs.second) << "\n";
    }

    return 0;
}