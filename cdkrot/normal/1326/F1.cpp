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

const int max_n = 18;

struct dp_state {
    vector<int64_t> vals[max_n];
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<int> gr(n);

    for (int i = 0; i < n; ++i) {
        string s = input<string>();
        for (int j = 0; j < n; ++j)
            if (s[j] == '1')
                gr[i] |= (1 << j);
    }

    vector<dp_state> dp(1 << n);
    for (int m = 1; m < (1 << n); ++m) {
        for (int i = 0; i < n; ++i)
            if (m & (1 << i)) {
                dp[m].vals[i].resize(1 << (__builtin_popcount(m)-1));

                if (__builtin_popcount(m) == 1)
                    dp[m].vals[i][0] = 1;
            }

        if (__builtin_popcount(m) == 1)
            continue;
        
        for (int last = 0; last < n; ++last)
            if (m & (1 << last))
                for (int prev = 0; prev < n; ++prev)
                    if (m & (1 << prev) and prev != last) {
                        int pstate = m ^ (1 << last);

                        for (int i = 0; i < SZ(dp[pstate].vals[prev]); ++i) {
                            dp[m].vals[last][2 * i + !!(gr[last] & (1 << prev))] += dp[pstate].vals[prev][i];
                        }
                    }
    }

    vector<int64_t> ans(1 << (n - 1));
    for (int v = 0; v < n; ++v)
        for (int x = 0; x < SZ(dp.back().vals[v]); ++x)
            ans[x] += dp.back().vals[v][x];

    for (auto elem: ans)
        cout << elem << " ";
    cout << "\n";
    
    return 0;
}