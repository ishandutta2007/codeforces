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
    int n, k;
    cin >> n >> k;

    
    vector<int> primes;
    vector<int> mind(n + 1, -1);
    
    for (int i = 2; i <= n; ++i) {
        if (mind[i] == -1) {
            mind[i] = SZ(primes);
            primes.push_back(i);
        }

        for (int j = 0; j <= mind[i] and i * primes[j] <= n; ++j)
            mind[i * primes[j]] = j;
    }

    vector<int> phi(n + 1, -1);
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int val = i;
        
        int p = primes[mind[i]];
        int pw = 1;
        while (val % p == 0)
            val /= p, pw *= p;

        phi[i] = (pw / p) * (p - 1) * phi[val];
    }

    int64_t ans = TYPEMAX(int64_t);
    for (int take2 = 0; take2 <= 1; ++take2) {
        int64_t ans_this = 1 + take2;

        vector<int> lst;
        for (int i = 3; i <= n; ++i)
            if (i % 2 == 1 or take2)
                lst.push_back(phi[i]);

        sort(ALL(lst));
        
        if (lst.size() < k)
            continue;

        for (int i = 0; i != k; ++i)
            ans_this += lst[i];

        ans = min(ans, ans_this);
    }

    cout << ans << "\n";

    return 0;
}