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

    set<int> hand;

    for (int i = 0; i != n; ++i) {
        int v = input<int>();

        if (v != 0)
            hand.insert(v);
    }

    vector<int> deq(n);
    for (int& elem: deq)
        cin >> elem;


    int ans = TYPEMAX(int);
    auto ok = [&](int mi) {
        auto deqq = deq;
        auto handd = hand;
        int steps = 0;
        
        int ptr = 0;
        auto draw = [&]() {
            int val = deqq[ptr++];

            if (val != 0)
                handd.insert(val);
        };
        
        for (int i = 0; i != mi; ++i) {
            deqq.push_back(0);
            draw();
            ++steps;
        }

        int val0 = 1;
        if (deqq[SZ(deqq) - 1] != 0) {
            int v = deqq[SZ(deqq) - 1];
            
            bool ok = true;
            for (int i = 1; i < v; ++i)
                if (ptr > SZ(deqq) - 1 - i or deqq[SZ(deqq) - 1 - i] != v - i)
                    ok = false;
            
            if (ok)
                val0 = v + 1;
        }

        for (int val = val0; val <= n; ++val) {
            if (not handd.count(val))
                return false;

            deqq.push_back(val);
            handd.erase(val);
            draw();
            ++steps;
        }

        ans = min(ans, steps);
        return true;
    };

    int lo = 1;
    int hi = n + 1; // how much desk to draw.

    ok(0); // special case
    if (lo < hi)
        ok(lo);
    
    while (hi - lo > 1) {
        int mi = lo + (hi - lo) / 2;

        if (ok(mi))
            hi = mi;
        else
            lo = mi;
    }

    cout << ans << "\n";
    
    return 0;
}