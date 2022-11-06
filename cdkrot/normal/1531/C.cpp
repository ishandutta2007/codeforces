// Dmitry [cdkrot.me] Sayutin (2021)

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
    int n = input<int>();

    if (n == 2) {
        cout << "-1\n";
        return 0;
    }
    
    int x = 1;
    while (n > x * x)
        ++x;

    int ex = (n == x * x - 2);
    
    cout << x + ex << "\n";

    if (n == x * x) {
        for (int i = 0; i < x; ++i)
            cout << string(x, 'o') << "\n";
        return 0;
    }
    
    vector<string> res(x + ex, string(x + ex, '.'));

    for (int i = 0; i < x - 1; ++i)
        for (int j = 0; j < x - 1; ++j)
            res[i][j] = 'o';

    int rem = n - (x - 1) * (x - 1);
    int ptr = 0;
    while ((ex == 0 ? rem >= 1 : rem != 1)) {
        res[ptr][x - 1] = 'o';
        res[x - 1][ptr] = 'o';
        ++ptr, rem -= 2;
    }

    if (ex == 1) {
        res[x][0] = res[0][x] = 'o';
        res[x - 2][x - 2] = '.';
    } else if (rem == -1) {
        res[x - 2][x - 2] = '.';
    }
    
    for (int i = 0; i < SZ(res); ++i)
        cout << res[SZ(res) - 1 - i] << "\n";

    return 0;
}