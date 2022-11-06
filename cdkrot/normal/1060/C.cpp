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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int m = input<int>();

    vector<int> a(n), b(m);
    input_seq(ALL(a));
    input_seq(ALL(b));

    int64_t x = input<int64_t>();

    vector<int> a_by_len(n + 1, TYPEMAX(int));
    vector<int> b_by_len(m + 1, TYPEMAX(int));
    
    for (int i = 0; i != n; ++i) {
        int sm = 0;
        
        for (int j = i; j != n; ++j) {
            sm += a[j];
            a_by_len[j - i + 1] = min(a_by_len[j - i + 1], sm);
        }
    }

    for (int i = 0; i != m; ++i) {
        int sm = 0;
        
        for (int j = i; j != m; ++j) {
            sm += b[j];
            b_by_len[j - i + 1] = min(b_by_len[j - i + 1], sm);
        }
    }

    int64_t ans = 0;
    for (int a_len = 1; a_len <= n; ++a_len)
        for (int b_len = 1; b_len <= m; ++b_len)
            if (a_by_len[a_len] * int64_t(b_by_len[b_len]) <= x)
                ans = max(ans, int64_t(a_len) * b_len);

    cout << ans << "\n";

    
    return 0;
}