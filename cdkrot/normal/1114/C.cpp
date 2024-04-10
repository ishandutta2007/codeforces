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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int64_t n = input<int64_t>();
    int64_t b = input<int64_t>();

    int64_t ans = TYPEMAX(int64_t);

    auto f = [&](int64_t x, int cnt) {
        int64_t ans_this = 0;

        int64_t xx = 1;
        while (true) {
            if (xx > n / x)
                break;
            
            xx *= x;
            ans_this += n / xx;
        }

        ans = min(ans, ans_this / cnt);
    };
    
    for (int64_t i = 2; i * i <= b; ++i) {
        int cnt = 0;
        
        while (b % i == 0) {
            b /= i;
            ++cnt;
        }

        if (cnt)
            f(i, cnt);
    }

    if (b != 1)
        f(b, 1);

    cout << ans << "\n";
    
    return 0;
}