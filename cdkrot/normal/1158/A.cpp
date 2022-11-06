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
    vector<int> a(n), b(m);
    input_seq(ALL(a));
    input_seq(ALL(b));
    
    if (*std::max_element(ALL(a)) > *std::min_element(ALL(b))) {
        cout << "-1\n";
        return 0;
    }

    int64_t ans = m * std::accumulate(ALL(a), int64_t(0));
    sort(ALL(a));
    sort(ALL(b));

    if (a.back() == b[0]) {
        for (int i = 0; i != m; ++i)
            ans += b[i] - a.back();
    } else {
        for (int i = 0; i != m - 1; ++i)
            ans += b[i] - a.back();
        
        ans += b.back() - a[SZ(a) - 2];
    }
    
    cout << ans << "\n";
    
    return 0;
}