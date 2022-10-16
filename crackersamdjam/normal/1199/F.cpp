#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 52;

int n, dp[MM][MM][MM][MM];
char a[MM][MM];

int go(int lx, int rx, int ly, int ry){
    int &ret = dp[lx][rx][ly][ry];
    if(~ret)
        return ret;
    ret = max(rx-lx, ry-ly);
    if(lx+1 == rx and ly+1 == ry)
        return ret = (a[lx][ly] == '#');
    for(int i = lx+1; i < rx; i++){
        ret = min(ret, go(lx, i, ly, ry) + go(i, rx, ly, ry));
    }
    for(int i = ly+1; i < ry; i++){
        ret = min(ret, go(lx, rx, ly, i) + go(lx, rx, i, ry));
    }
    return ret;
}

int main(){
    memset(dp, -1, sizeof dp);
    scan(n);
    for(int i = 0; i < n; i++)
        scanf("%s", a[i]);
    print(go(0, n, 0, n));
    
    return 0;
}