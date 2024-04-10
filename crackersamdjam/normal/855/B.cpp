#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 1e5+2;
using ll = long long;
ll a[MM], b[3], premx[MM], premin[MM], sufmx[MM], sufmin[MM];
int n;

int main(){
    init();
    scan(n, b[0], b[1], b[2]);
    premx[0] = sufmx[n+1] = LLONG_MIN;
    premin[0] = sufmin[n+1] = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        premin[i] = min(premin[i-1], a[i]);
        premx[i] = max(premx[i-1], a[i]);
    }
    for(int i = n; i; i--){
        sufmx[i] = max(sufmx[i+1], a[i]);
        sufmin[i] = min(sufmin[i+1], a[i]);
    }
    ll ans = LLONG_MIN;
    for(int i = 1; i <= n; i++){
        ll v = max(b[0]*premin[i], b[0]*premx[i]) + b[1]*a[i]
        + max(b[2]*sufmx[i], b[2]*sufmin[i]);
        ans = max(ans, v);
    }

    print(ans);

    
    return 0;
}