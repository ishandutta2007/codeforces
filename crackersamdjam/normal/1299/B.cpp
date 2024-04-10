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
using ld = long double;
const int MM = 1e5+5;

int n;
ll x[MM], y[MM];
ll sq(ll z){
    return z*z;
}
ll dis(int i, int j){
    return sq(x[i]-x[j]) + sq(y[i]-y[j]);
}

int main(){
    scan(n);
    for(int i = 0; i < n; i++)
        scan(x[i], y[i]);
    x[n] = x[0], y[n] = y[0];
    
    if(n&1){
        return puts("no"), 0;
    }
    
    bool b = 1;
    int m = n/2;
    ld midx = (x[0]+x[m])/2.0, midy = (y[0]+y[m])/2.0;
    for(int i = 0; i <= m; i++){
        ld tx = (x[i]+x[m+i])/2.0, ty = (y[i]+y[m+i])/2.0;
        if(tx != midx || ty != midy)
            b = 0;
    }
    
    puts(b ? "yes" : "no");
    
    return 0;
}