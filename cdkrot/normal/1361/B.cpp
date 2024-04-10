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

const int mod = int(1e9) + 7;

int mult(int a, int b) {return (int64_t(a) * b) % mod;}

int fpow(int a, int n, int r = 1) {
    while (n) {
        if (n % 2)
            r = mult(r, a);
        
        a = mult(a, a);
        n /= 2;
    }
    return r;
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}


void solve() {
    int n, p;
    cin >> n >> p;
    
    vector<int> ks(n);
    input_seq(ALL(ks));
    sort(RALL(ks));

    if (p == 1) {
        cout << n % 2 << "\n";
        return;
    }
    
    int ptr = 0;
    while (ptr != n) {
        int evil = ks[ptr++];

        int oldptr = ptr;
        
        map<int, int> cur;
        while (ptr != n and not (cur.count(evil) and cur[evil] == 1)) {
            int val = ks[ptr++];

            cur[val] += 1;
            while (cur[val] == p) {
                cur[val] = 0;
                cur[val + 1] += 1;
                val++;
            }
        }

        if (ptr != n)
            continue;

        int ans = fpow(p, evil);
        for (int i = oldptr; i != n; ++i)
            ans = sub(ans, fpow(p, ks[i]));
        cout << ans << "\n";
        return;
    }

    cout << "0\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    for (int t = input<int>(); t; --t) {
        solve();
    }

    return 0;
}