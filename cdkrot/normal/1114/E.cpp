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

    int lo = 0; // true
    int hi = (int)1e9 + 1; // not true

    while (hi - lo > 1) {
        int mi = lo + (hi - lo) / 2;

        cout << "> " << mi << std::endl;

        if (input<int>() == 1)
            lo = mi;
        else
            hi = mi;
    }

    int largest = lo + 1;

    std::mt19937 rnd((size_t)(new char()));

    std::uniform_int_distribution<int> dist(1, n);

    set<int> ask;
    while (SZ(ask) < 30 and SZ(ask) < n)
        ask.insert(dist(rnd));

    int step = 0;
    
    for (int elem: ask) {
        cout << "? " << elem << std::endl;
        
        step = std::__gcd(step, largest - input<int>());
    }

    cout << "! " << largest - (n - 1) * step << " " << step << "\n";
    
    return 0;
}