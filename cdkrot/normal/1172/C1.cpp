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

const int mod = 998244353;
int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int fpow(int a, int n) {
    int r = 1;

    while (n) {
        if (n % 2)
            r = mult(r, a);

        a = mult(a, a);
        n /= 2;
    }

    return r;
}

int inv[10000];

// steps, delta ourwgh, delta badwgh
int dp[52][52][52];




int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, m;
    cin >> n >> m;

    for (int i = 1; i < 10000; ++i)
        inv[i] = fpow(i, mod - 2);
    
    vector<int> a(n);
    for (int& elem: a)
        cin >> elem;

    vector<int> wgh(n);
    for (int& elem: wgh)
        cin >> elem;
    
    for (int pic = 0; pic != n; ++pic) {
        memset(dp, 0, sizeof(dp));

        if (a[pic] == 1) {
            dp[0][0][0] = 1;

            int wgood = 0;
            int wbad = 0;
            
            for (int i = 0; i != n; ++i)
                if (i != pic)
                    (a[i] == 1 ? wgood : wbad) += wgh[i];
            
            for (int steps = 0; steps < m; ++steps)
                for (int dwe = 0; dwe <= steps; ++dwe)
                    for (int dbad = 0; dbad + dwe <= steps and dbad <= wbad; ++dbad) {
                        int dgood = steps - dbad - dwe;

                        int WE = dp[steps][dwe][dbad];
                        WE = mult(WE, inv[wgood + dgood + wbad - dbad + wgh[pic] + dwe]);
                        
                        dp[steps + 1][dwe][dbad] = add(dp[steps + 1][dwe][dbad], mult(WE, wgood + dgood));
                        dp[steps + 1][dwe + 1][dbad] = add(dp[steps + 1][dwe + 1][dbad], mult(WE, wgh[pic] + dwe));
                        dp[steps + 1][dwe][dbad + 1] = add(dp[steps + 1][dwe][dbad + 1], mult(WE, wbad - dbad));
                    }

            int ans = 0;
            for (int dwe = 0; dwe <= 50; ++dwe)
                for (int dbad = 0; dbad <= 50; ++dbad) {
                    ans = add(ans, mult(wgh[pic] + dwe, dp[m][dwe][dbad]));
                }

            cout << ans << "\n";
        } else {
            dp[0][0][0] = 1;

            int wgood = 0;
            int wbad = 0;
            
            for (int i = 0; i != n; ++i)
                if (i != pic)
                    (a[i] == 1 ? wgood : wbad) += wgh[i];
            
            for (int steps = 0; steps < m; ++steps)
                for (int dwe = 0; dwe <= steps and dwe <= wgh[pic]; ++dwe)
                    for (int dbad = 0; dbad + dwe <= steps and dbad <= wbad; ++dbad) {
                        int dgood = steps - dbad - dwe;

                        int WE = dp[steps][dwe][dbad];
                        WE = mult(WE, inv[wgood + dgood + wbad - dbad + wgh[pic] - dwe]);
                        
                        dp[steps + 1][dwe][dbad] = add(dp[steps + 1][dwe][dbad], mult(WE, wgood + dgood));
                        dp[steps + 1][dwe + 1][dbad] = add(dp[steps + 1][dwe + 1][dbad], mult(WE, wgh[pic] - dwe));
                        dp[steps + 1][dwe][dbad + 1] = add(dp[steps + 1][dwe][dbad + 1], mult(WE, wbad - dbad));
                    }

            int ans = 0;
            for (int dwe = 0; dwe <= wgh[pic]; ++dwe)
                for (int dbad = 0; dbad <= 50; ++dbad) {
                    ans = add(ans, mult(wgh[pic] - dwe, dp[m][dwe][dbad]));
                }

            cout << ans << "\n";
        }
    }
    
    return 0;
}