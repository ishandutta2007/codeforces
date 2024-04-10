#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
constexpr int MM = 2005, MN = 24, MV = 2e5+5;
const ll mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

#define x first
#define y second

ll f[MV], inv[MV];

ll val(ll a, ll b){
    if(a < 0 or b < 0)
        return 0;
    return  (f[a+b]*inv[b] % mod)*inv[a] % mod;
}
void addmod(ll &a, ll b){
    a += b;
    while(a >= mod)
        a -= mod;
}
void submod(ll &a, ll b){
    a -= b;
    while(a < 0)
        a += mod;
}

int n, m, k, s;
pair<int, int> a[MM];

ll dp[MM][MN], ans;

int main(){
    scan(n, m, k, s);
    f[0] = inv[0] = 1;
    for(int i = 1; i <= n+m+2; i++)
        f[i] = f[i-1]*i%mod;
    inv[n+m+2] = fpow(f[n+m+2], mod-2, mod);
    for(int i = n+m+1; i > 0; i--)
        inv[i] = inv[i+1]*(i+1)%mod;
    
    for(int i = 0; i < k; i++)
        scan(a[i].x, a[i].y);
    a[k] = {1, 1};
    a[k+1] = {n, m};
    k += 2;
    sort(a, a+k);
    
    dp[0][0] = 1;
    for(int i = 1; i < k; i++){
        for(int r = 0; r < MN; r++){
            dp[i][r] = val(a[i].x-1, a[i].y-1);
            for(int l = 0; l < r; l++){
                submod(dp[i][r], dp[i][l]);
                // lesser ones
            }
    
            for(int j = 1; j < i; j++){
                submod(dp[i][r], dp[j][r]*val(a[i].x-a[j].x, a[i].y-a[j].y) % mod);
                //all posibilities
            }
        }
        //move down because val is all one
        addmod(dp[i][MN-2], dp[i][MN-1]);
        dp[i][MN-1] = 0;
    }
    
    for(int j = 0; j < MN; j++){
        ll add = dp[k-1][j]*s%mod;
        s = (s+1)/2;
        addmod(ans, add);
    }
    
    print(divmod(ans, val(n-1, m-1), mod));
    
    return 0;
}