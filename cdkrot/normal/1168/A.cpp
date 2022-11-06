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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    input_seq(ALL(a));

    int lo = -1;
    int hi = m;

    auto check = [&](int L) {
        assert(L < m);
        
        int val = 0;

        for (int elem: a) {
            int to = (elem + L) % m;

            vector<pair<int, int>> kokoko;

            if (to < elem) {
                kokoko.emplace_back(elem, m - 1);
                kokoko.emplace_back(0, to);
            } else {
                kokoko.emplace_back(elem, to);
            }

            int newval = TYPEMAX(int);
            for (auto seg: kokoko)
                if (val <= seg.second)
                    newval = min(newval, max(val, seg.first));

            if (newval == TYPEMAX(int))
                return false;

            val = newval;
        }

        return true;
    };
    
    while (hi - lo > 1) {
        int mi = lo + (hi - lo + 1) / 2;

        if (check(mi))
            hi = mi;
        else
            lo = mi;
    }

    cout << hi << "\n";
    
    return 0;
}