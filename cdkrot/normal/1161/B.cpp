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
    int n = input<int>();
    int m = input<int>();

    set<pair<int, int>> lst;
    
    for (int i = 0; i != m; ++i) {
        int a, b;
        cin >> a >> b;

        --a, --b;

        lst.emplace(min(a, b), max(a, b));
    }

    auto ok = [&](int k) {
        for (auto elem: lst) {
            pair<int, int> nw = {(elem.first + k) % n, (elem.second + k) % n};
            if (nw.first > nw.second)
                swap(nw.first, nw.second);

            if (not lst.count(nw))
                return false;
        }
        return true;
    };
    
    for (int k = 1; k < n; ++k)
        if (n % k == 0) {
            if (ok(k)) {
                cout << "Yes\n";
                return 0;
            }
        }

    cout << "No\n";
    
    return 0;
}