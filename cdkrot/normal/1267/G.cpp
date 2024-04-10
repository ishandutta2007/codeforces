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
    int n, x;
    cin >> n >> x;

    const int maxC = 10 * 1000;
    vector<vector<double>> prob(n + 1, vector<double>(maxC + 1, 0.0));
    prob[0][0] = 1.;

    int total = 0;
    
    for (int i = 0; i < n; ++i) {
        int thew;
        cin >> thew;

        total += thew;
        
        for (int cnt = n - 1; cnt >= 0; --cnt)
            for (int w = maxC - thew; w >= 0; --w) {
                prob[cnt + 1][w + thew] += (prob[cnt][w] * (cnt + 1) / double(n - cnt));
            }
    }

    double ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= maxC; ++j) {
            ans += prob[i][j] * min(double(total - j) / (n - i), x / 2. * (1 + n / double(n - i)));
        }

    cout << std::fixed;
    cout.precision(10);
    cout << ans << "\n";
    
    return 0;
}