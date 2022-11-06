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
    int n = input<int>();
    vector<pair<int, int>> p(n);

    if (n % 2) {
        cout << "NO\n";
        return 0;
    }

    for (auto& elem: p)
        cin >> elem.first >> elem.second;

    p.push_back(p[0]);
    p.push_back(p[1]);
    
    for (int i = 0; i < n / 2; ++i) {
        auto a = p[i];
        auto b = p[i + 1];
        auto c = p[i + 1 + (n/2)];
        auto d = p[i +  (n/2)];

        if (make_pair(b.first - a.first, b.second - a.second) != make_pair(d.first - c.first, d.second - c.second)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}