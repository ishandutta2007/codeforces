/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;
#define SZ(x)               ((int)(x).size())
#define all(x)              (x).begin(), (x).end()
#define loop(i, n)          for(int i = 0; i < (n); ++i)
#define cont(i, n)          for(int i = 1; i <= (n); ++i)
#define circ(i, a, b)       for(int i = (a); i <= (b); ++i)
#define range(i, a, b, c)   for(int i = (a); ((c) > 0 ? i <= (b) : i >= (b)); i += (c))
#define foreach(it, v)      for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define y0          y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1          y1II11II11III11I1III11II111IIII1II1I1
#define pub         push_back
#define pob         pop_back
#define mak         make_pair
typedef long long   ll;
typedef long double lf;
const int   Inf = 0x3f3f3f3f;
const ll    INF = 0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

template<int jt> struct ModInt {
    int x;
    ModInt(int v = 0) {x = v; if(x >= jt || x < 0) {x %= jt; if(x < 0) x += jt;}}
    ModInt(ll v) {x = v % jt; if(x < 0) x += jt;}
    operator int() const {return x;}
    friend inline ModInt &operator+=(ModInt &a, const ModInt &b) {a.x += b.x; if(a.x >= jt) a.x -= jt; return a;}
    friend inline ModInt operator+(ModInt a, const ModInt &b) {return a += b;}
    friend inline ModInt operator+(ModInt a, int b) {return a += ModInt(b);}
    friend inline ModInt operator+(int a, ModInt b) {return b += ModInt(a);}
    friend inline ModInt &operator++(ModInt &a) {return a += 1;}
    friend inline ModInt &operator-=(ModInt &a, const ModInt &b) {a.x -= b.x; if(a.x < 0) a.x += jt; return a;}
    friend inline ModInt operator-(ModInt a, const ModInt &b) {return a -= b;}
    friend inline ModInt operator-(ModInt a, int b) {return a -= ModInt(b);}
    friend inline ModInt operator-(int a, ModInt b) {return ModInt(a) - b;}
    friend inline ModInt &operator--(ModInt &a) {return a -= 1;}
    friend inline ModInt &operator*=(ModInt &a, const ModInt &b) {a.x = (ll)a.x * b.x % jt; return a;}
    friend inline ModInt operator*(ModInt a, const ModInt &b) {return a *= b;}
    friend inline ModInt operator*(ModInt a, int b) {return a *= ModInt(b);}
    friend inline ModInt operator*(int a, ModInt b) {return b *= ModInt(a);}
    static inline void exgcd(ll a, ll b, ll &x, ll &y) {b ? (exgcd(b, a % b, y, x), y -= a / b * x) : (x = 1, y = 0);}
    friend inline ModInt inv(const ModInt &a) {ll x, y; exgcd(a, jt, x, y); return x;}
    friend inline ModInt operator/(const ModInt &a, const ModInt &b) {return a * inv(b);}
    friend inline ModInt operator/(ModInt a, int b) {return a * inv(ModInt(b));}
    friend inline ModInt operator/(int a, ModInt b) {return ModInt(a) * inv(b);}
    friend inline ModInt operator/=(ModInt &a, const ModInt &b) {return a = a / b;}
};
const int jt = 998244353;
typedef ModInt<jt> mint;

mint dp[5005][5005];
mint qzh[5005][5005];
int n, a[5005];

int main() {
    scanf("%d", &n);
    cont(i, n) scanf("%d", a + i);
    sort(a + 1, a + n + 1);
    dp[0][0] = 1; qzh[0][0] = 1;
    cont(i, n) {
        int P = upper_bound(a + 1, a + n + 1, a[i] / 2) - a - 1;
        // 
        cont(j, i) dp[i][j] += qzh[P][j - 1];
        // 
        cont(j, P + 1) dp[i][j] += dp[i][j - 1] * (P - j + 2);
        // 
        loop(j, i + 1) qzh[i][j] = qzh[i - 1][j] + dp[i][j];
    }
    printf("%d\n", dp[n][n]);
    return 0;
}

/**
 * 
 *   
 *    f(i, j)  i i j  f(0, 0) = 1
 *   
 *      f(i, j) += sum f(p, j - 1) p  2Ap <= Ai P  p
 *      i  q  2Aq <= Ai f(i, j) += f(i, j - 1) * (P - j + 2)
 *   f(n, n)  O(n^3) O(n^2)
 */