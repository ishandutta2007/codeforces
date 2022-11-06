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

struct obj {
    int x1;
    int x2;
    int y1;
    int y2;
};

obj operator+(obj a, obj b) {
    return obj {max(a.x1, b.x1), min(a.x2, b.x2), max(a.y1, b.y1), min(a.y2, b.y2)};
}

const int inf = 1.5e9;
obj neutral = {-inf, +inf, -inf, +inf};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<obj> in(n);
    for (auto& elem: in)
        cin >> elem.x1 >> elem.y1 >> elem.x2 >> elem.y2;

    vector<obj> pref(n), suf(n);

    pref[0] = in[0];
    for (int i = 1; i != n; ++i)
        pref[i] = (pref[i - 1] + in[i]);

    suf[n - 1] = in[n - 1];
    for (int i = n - 2; i >= 0; --i)
        suf[i] = (suf[i + 1] + in[i]);

    for (int i = 0; i != n; ++i) {
        obj res = neutral;
        if (i != 0)
            res = res + pref[i - 1];
        if (i != n - 1)
            res = res + suf[i + 1];

        if (res.x1 <= res.x2 and res.y1 <= res.y2) {
            cout << res.x1 << " " << res.y1 << "\n";
            return 0;
        }
    }

    assert(false);
    
    return 0;
}