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
using ld = long double;
const int MM = 52;

int n, p, a[MM];
ld dp[MM][MM][MM];

int main(){
    scan(n);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    scan(p);
    ld ans = 0;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int k = 0; k <= p; k++){
                dp[i][j][k] += dp[i-1][j][k]*(i-j)/i;
                if(j and k >= a[i])
                    dp[i][j][k] += dp[i-1][j-1][k-a[i]]*(j)/i;
                
                if(i == n and j){
                    ans += dp[i][j][k];
                }
//                if(dp[i][j][k])
//                    cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
            }
        }
    }
    
    printf("%.9Lf\n", ans);
    
    return 0;
}