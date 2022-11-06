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
    int n = input<int>();
    vector<pair<int, int>> ops;

    int N = 1;
    while (2 * N <= n)
        N *= 2;

    for (int start: {0, n - N}) {
        for (int lvl = 1; lvl != N; lvl *= 2)
            for (int off = 0; off != N; off += 2 * lvl)
                for (int little = 0; little < lvl; little++)
                    ops.emplace_back(start + off + little,
                                     start + off + little + lvl);
    }
    
    assert(SZ(ops) <= int(5e5));
    cout << SZ(ops) << "\n";
    for (auto [x, y]: ops)
        cout << x + 1 << " " << y + 1 << "\n";
    
    return 0;
}