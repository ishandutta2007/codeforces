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
const ll mod = 998244353;
const int MM = 2e5+5;

ll n, m, k, f[MM], inv[MM];

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

ll C(ll a, ll b){
    return f[a]*inv[b]%mod*inv[a-b]%mod;
}

int main(){
    scan(n, k);
    if(k >= n){
        print(0);
        return 0;
    }
    
    m = n-k;
    
    f[0] = inv[0] = 1;
    for(int i = 1; i < MM; i++){
        f[i] = f[i-1]*i%mod;
        inv[i] = fpow(f[i], mod-2, mod);
    }
    
    ll sum = 0;
    //inc ex = num of ways to get m boxes
    for(ll i = 1; i <= m; i++){
        ll v = fpow(i, n, mod)*C(m, m-i)%mod;
        if(i%2 == m%2){
            sum = (sum+v)%mod;
        }
        else{
            sum = (sum-v+mod)%mod;
        }
    }
    
    ll ans = (sum+mod)%mod;
    
    //chose free cols
    ans = ans*C(n, k)%mod;
    
    if(k){
        ans = ans*2%mod;
        //horizontal
    }
    
    print(ans);
    
    
    return 0;
}