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
const int MM = 250001;

ll n, m, ans, fac[MM];

int main(){
    
    scan(n, m);
    fac[0] = 1;
    for(ll i = 1; i <= n; i++)
        fac[i] = fac[i-1]*i%m;
    
    for(ll dif = 0; dif < n; dif++){
        ans += (((n-dif)*(n-dif) % m)*fac[n-dif-1] % m)*fac[dif+1] % m;
        ans %= m;
    }
    /*
    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j++){
            print(i, j, (n-(j-i))*fac[n-(j-i+1)]*fac[j-i+1], (n-(j-i)), fac[n-(j-i+1)], fac[j-i+1]);
            ans += (n-(j-i))*fac[n-(j-i+1)]*fac[j-i+1];
        }
    }
     */
    
    print(ans);
    
    return 0;
}