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
    
    vector<vector<int>> data(m);
    for (int i = 0; i != n; ++i) {
        int pos = input<int>() - 1;
        int val = input<int>();

        data[pos].push_back(val);
    }

    sort(ALL(data), [&](vector<int>& a, vector<int>& b) {
            return (SZ(a) > SZ(b));
        });

    for (int i = 0; i != m; ++i) {
        sort(RALL(data[i]));
        for (int j = 1; j < SZ(data[i]); ++j)
            data[i][j] += data[i][j - 1];
    }

    int ans = 0;
    for (int cnt = n; cnt > 0; --cnt) {
        int ans_this = 0;
        for (int i = 0; i < m and SZ(data[i]) >= cnt; ++i)
            ans_this += max(0, data[i][cnt - 1]);

        ans = max(ans, ans_this);
    }

    cout << ans << "\n";
    
    return 0;
}