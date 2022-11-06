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
    for (int t = input<int>(); t; --t) {
        int n, l;
        cin >> n >> l;

        vector<int> a(n);
        input_seq(ALL(a));
        a.insert(a.begin(), 0);
        a.push_back(l);

        int p1 = 0, p2 = SZ(a) - 1;
        double t1 = 0, t2 = 0;

        while (p1 + 1 != p2) {
            double t1_prime = t1 + (a[p1 + 1] - a[p1]) / double(p1 + 1);
            double t2_prime = t2 + (a[p2] - a[p2 - 1]) / double(SZ(a) - p2);

            if (t1_prime < t2_prime)
                ++p1, t1 = t1_prime;
            else
                --p2, t2 = t2_prime;
        }

        auto v1 = p1 + 1;
        auto v2 = SZ(a) - p2;
        cout << std::fixed;
        cout.precision(12);
        cout << double(a[p2] - a[p1] + v1 * t1 + v2 * t2) / (v1 + v2) << "\n";
    }

    return 0;
}