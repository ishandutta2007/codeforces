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
    int n, k;
    cin >> n >> k;

    vector<vector<int64_t>> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i].resize(input<int>());
        input_seq(ALL(arr[i]));

        arr[i].resize(min(SZ(arr[i]), k));
    }

    int64_t ans = 0;

    vector<pair<int64_t, int>> items(n);
    for (int i = 0; i < n; ++i) {
        items[i].second = SZ(arr[i]);
        items[i].first = std::accumulate(ALL(arr[i]), int64_t(0));
    }

    vector<int64_t> maxprofit(k + 1, TYPEMIN(int64_t));
    maxprofit[0] = 0;

    auto add_item = [&](int i) {
        for (int pos = k; pos >= items[i].second; --pos)
            if (maxprofit[pos - items[i].second] != TYPEMIN(int64_t))
                maxprofit[pos] = max(maxprofit[pos], maxprofit[pos - items[i].second] + items[i].first);
    };
    
    std::function<void(int, int)> go = [&](int l, int r) {
        if (l == r) {
            int64_t sm = 0;
            for (int i = 0; i < SZ(arr[l]); ++i) {
                sm += arr[l][i];

                if (maxprofit[k - (i + 1)] != TYPEMIN(int64_t))
                    ans = max(ans, maxprofit[k - (i + 1)] + sm);
            }

            return;
        }

        auto state = maxprofit;
        int m = (l + r) / 2;
        for (int i = l; i <= m; ++i)
            add_item(i);

        go(m + 1, r);

        maxprofit = state;
        for (int i = m + 1; i <= r; ++i)
            add_item(i);
        go(l, m);

        maxprofit = state;
    };

    go(0, n - 1);
    cout << ans << "\n";
    return 0;
}