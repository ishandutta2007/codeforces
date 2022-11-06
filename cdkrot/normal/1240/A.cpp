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
    for (int q = input<int>(); q !=0; -- q) {
        int n = input<int>();

        vector<int> pr(n);
        input_seq(ALL(pr));
        sort(RALL(pr));

        int x, a, y, b;
        cin >> x >> a >> y >> b;

        int64_t tg = input<int64_t>();
        
        int lo = 0;
        int hi = n + 1;
        while (hi - lo > 1) {
            int mi = lo + (hi - lo) / 2;

            int nab = mi / (int64_t(a) * b / std::__gcd(a, b));
            int na = mi / a - nab;
            int nb = mi / b - nab;

            int64_t cst = 0;
            int ptr = 0;
            for (int i = 0; i < nab; ++i)
                cst += (pr[ptr++] / 100) * (x + y);

            if (x > y) {
                for (int i = 0; i < na; ++i)
                    cst += (pr[ptr++] / 100) * (x);

                for (int i = 0; i < nb; ++i)
                    cst += (pr[ptr++] / 100) * (y);
            } else {
                for (int i = 0; i < nb; ++i)
                    cst += (pr[ptr++] / 100) * (y);

                for (int i = 0; i < na; ++i)
                    cst += (pr[ptr++] / 100) * (x);
            }

            if (cst >= tg)
                hi = mi;
            else
                lo = mi;
                    
        }

        cout << (hi == n + 1 ? -1 : hi) << "\n";
        
    }

    return 0;
}