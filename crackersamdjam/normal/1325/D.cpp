#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

ll n, m;
ll a[69], b[69];

int main(){
    scan(n, m);
    for(int i = 0; i < 64; i++){
        if(n&(1LL<<i))
            a[i] = 1;
        if(m&(1LL<<i))
            b[i] = 1;
    }
    for(int i = 63; i > 0; i--){
        if(((b[i]%2+2)%2) != a[i]){
            b[i]--;
            b[i-1] += 2;
        }
        ll mv = b[i]/2;
        b[i] -= 2*mv;
        b[i-1] += 4*mv;
    }
    if((((b[0]%2+2)%2) != a[0]) || (*min_element(b, b+69) < 0)){
        print(-1);
        return 0;
    }
    for(int i = 0; i < 64; i++){
        ll mv = b[i]/4;
        b[i] -= 4*mv;
        b[i+1] += 2*mv;
    }
    
    ll ans = *max_element(b, b+69);
    print(ans);
    vector<ll> v(ans);
    for(int i = 0; i < 64; i++){
        for(int j = 0; j < b[i]; j++){
            v[j] |= (1LL<<i);
        }
    }
    for(ll i: v)
        printf("%lld ", i);
    
    return 0;
}