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
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        vector<int> where(n + 1, -1);
        vector<int> when(n, -1);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = input<int>();
            where[arr[i]] = i;
        }

        vector<int> b(k);
        input_seq(ALL(b));

        for (int i = 0; i < k; ++i)
            when[where[b[i]]] = i;
        
        int ans = 1;
        const int mod = 998244353;
        
        for (int B: b) {
            B = where[B];

            int delta = 0;
            if (B + 1 != n and when[B + 1] < when[B])
                ++delta;
            if (B != 0 and when[B - 1] < when[B])
                ++delta;

            ans = (ans * delta) % mod;
        }

        cout << ans << "\n";
    }

    return 0;
}