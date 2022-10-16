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
const int MM = 30002, ADD = 500;

int n, d, dpa[1005][MM*2], a[MM], ans;

int main(){
    scan(n, d);
    for(int i = 0,l; i < n; i++){
        scan(l);
        a[l]++;
    }
    int (*dp)[MM*2] = dpa+ADD-d+2;
    memset(dpa, -0x3f, sizeof dpa);
    
    dp[d][d] = 0;
    for(int i = 0; i < MM; i++){
        for(int j = max(1, d-ADD); j < d+ADD; j++){
            dp[j][i] += a[i];
            int v = dp[j][i];
            ans = max(ans, v);
            dp[j][i+j] = max(dp[j][i+j], v);
            dp[j+1][i+j+1] = max(dp[j+1][i+j+1], v);
            dp[j-1][i+j-1] = max(dp[j-1][i+j-1], v);
        }
    }
    print(ans);
    
    return 0;
}