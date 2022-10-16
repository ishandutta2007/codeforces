#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;

ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1LL;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return (((t*t)%fpow_mod)*fpow_b)%fpow_mod;return (t*t)%fpow_mod;}
ll x, n, ans = 1, mod = 1e9+7;

void add(ll i){
    ll tn = n, cnt = 0;
    while(tn){
        tn /= i;
        cnt += tn;
    }
    ans = (ans*fpow(i, cnt, mod)) % mod;
}

int main(){
    
    scan(x, n);
    
    for(ll i = 2; i*i <= x; i++){
        if(x % i == 0){
            add(i);
            while(x % i == 0)
                x /= i;
        }
    }
    
    if(x > 1)
        add(x);
    
    print(ans);
    
    return 0;
}