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
const int MM = 105;

int t, n, m;
ll a[MM][MM], dp[MM][MM];

int main(){
    scan(t);
    while(t--){
        set<ll> st;
        scan(n, m);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scan(a[i][j]);
                a[i][j] -= i+j;
                if(a[i][j] <= a[1][1])
                    st.insert(a[i][j]);
            }
        }
        ll ans = LLONG_MAX;
        for(ll v: st){
            memset(dp, 0x3f, sizeof dp);
            dp[1][1] = a[1][1] - v;
            for(int i = 1; i <= n; i++){
                for(int j = 1+(i==1); j <= m; j++){
                    if(a[i][j] < v) continue;
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j]-v;
                }
            }
            ans = min(ans, dp[n][m]);
        }
        print(ans);
    }
    
    
    return 0;
}