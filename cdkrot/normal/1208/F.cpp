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

struct m2 {
    int fmax;
    int smax;
};

m2 operator+(m2 a, m2 b) {
    m2 res;

    res.fmax = max(a.fmax, b.fmax);

    if (res.fmax == a.fmax)
        res.smax = max(a.smax, b.fmax);
    else
        res.smax = max(a.fmax, b.smax);

    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<int> arr(n);
    vector<m2> conv(1 << 21);
    
    for (int i = 0; i != n; ++i) {
        int val = input<int>();
        arr[i] = val;
        
        conv[val] = (conv[val] + m2 {i, -1});
    }

    for (int bit = 0; bit != 21; ++bit)
        for (int i = 0; i != (1 << 21); ++i)
            if (not (i & (1 << bit)))
                conv[i] = conv[i] + conv[i | (1 << bit)];
    
    int ans = 0;
#define a arr
    for (int i = 0; i + 2 != n; ++i) {
        int bits = ((1 << 21) - 1) - a[i];

        int ans_this = 0;
        for (int bt = 20; bt >= 0; --bt)
            if (bits & (1 << bt)) {
                ans_this += (1 << bt);

                if (conv[ans_this].smax > i) {}
                else
                    ans_this -= (1 << bt);
            }

        ans = max(ans, ans_this | a[i]);
    }

    cout << ans << "\n";
    
    return 0;
}