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

pair<int, int> mod = {1000 * 1000 * 1000 + 7, 1000 * 1000 * 1000 + 9};

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    a.first += b.first;
    a.second += b.second;

    if (a.first >= mod.first)
        a.first -= mod.first;
    if (a.second >= mod.second)
        a.second -= mod.second;

    return a;
}

pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
    a.first -= b.first;
    a.second -= b.second;

    if (a.first < 0)
        a.first += mod.first;
    if (a.second < 0)
        a.second += mod.second;

    return a;
}

pair<int, int> mult(pair<int, int> a, pair<int, int> b) {
    return make_pair<int, int>(int64_t(a.first) * b.first % mod.first, int64_t(a.second) * b.second % mod.second);
}

int64_t solve(string s) {
    // size_t rand = (size_t)(new char());
    
    // int p = 3 + (rand % 10000);
    // vector<pair<int, int>> pw(SZ(s) + 10);

    // pw[0] = {1, 1};
    // for (int i = 1; i < SZ(pw); ++i)
    //     pw[i] = mult(make_pair(p, p), pw[i - 1]);

    // string s2 = s;
    // std::reverse(ALL(s2));
    // for (int i = 0; i != SZ(s); ++i)
    //     s2[i] = '0' + ((s2[i] - '0') ^ 1);
    
    // vector<pair<int, int>> hash(SZ(s) + 1);
    // vector<pair<int, int>> hash2(SZ(s) + 1);
    // for (int i = 0; i != SZ(s); ++i) {
    //     hash[i + 1] = add(mult(hash[i], pw[1]), make_pair(s[i] - '0' + 1, s[i] - '0' + 1));
    //     hash2[i + 1] = add(mult(hash2[i], pw[1]), make_pair(s2[i] - '0' + 1, s2[i] - '0' + 1));
    // }

    // auto get_hash = [&](int l, int r) {
    //     return sub(hash[r + 1], mult(hash[l], pw[r - l + 1]));
    // };

    // auto get_hash2 = [&](int l, int r) {
    //     r = SZ(s) - 1 - r;
    //     l = SZ(s) - 1 - l;
    //     swap(l, r);
    //     return sub(hash2[r + 1], mult(hash2[l], pw[r - l + 1]));
    // };

    vector<int> minr(SZ(s), TYPEMAX(int));

    // for (int a = 0; a < SZ(s); ++a) {
    //     int lo = 0;
    //     int hi = min(a, SZ(s) - a - 1) + 1;

    //     while (hi - lo > 1) {
    //         int mi = lo + (hi - lo) / 2;

    //         if (get_hash(a - mi, a - 1) == get_hash2(a + 1, a + mi))
    //             lo = mi;
    //         else
    //             hi = mi;    
    //     }

    //     if (lo == min(a, SZ(s) - a - 1)) {}
    //     else {
    //         minr[a - hi] = min(minr[a - hi], a + hi);
    //     }
    // }

    for (int i = 0; i != SZ(s); ++i)
        for (int k = 1; i - k >= 0 and i + k < SZ(s) and k <= 15; ++k) {
            auto b1 = s[i];
            auto b2 = s[i - k];
            auto b3 = s[i + k];
            if (b1 == b2 and b2 == b3)
                minr[i - k] = min(minr[i - k], i + k);
        }
    
    int64_t ans = 0;
    int rr = TYPEMAX(int);
    for (int l = SZ(s) - 1; l >= 0; --l) {
        rr = min(rr, minr[l]);

        if (rr != TYPEMAX(int))
            ans += SZ(s) - rr;
    }

    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    // for (int msk = 0; msk != (1 << 5); ++msk) {
    //     for (int i = 0; i != 5; ++i)
    //         for (int k = 1; i - k >= 0 and i + k < 5; ++k) {
    //             bool b1 = !!(msk & (1 << i));
    //             bool b2 = !!(msk & (1 << (i - k)));
    //             bool b3 = !!(msk & (1 << (i + k)));
    //             if (b1 == b2 and b2 == b3)
    //                 goto next;
    //         }

    //     cout << msk << std::endl;
        
    // next:;
    // }
    
    cout << solve(input<string>()) << "\n";
    
    return 0;
}