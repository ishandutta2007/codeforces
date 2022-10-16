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
constexpr int MM = 201, MV = 1001;
const ll mod = 1e9+7;

void addmod(ll &a, ll b){
    a = (a+b)%mod;
}

int n, m, a[MM];
ll dp[2][MM][MV], ans;

int main(){
    scan(n, m);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    sort(a+1, a+1+n);
    int cur = 1, pre = 0;
    dp[cur][0][0] = 1;
    for(int i = 1; i <= n; i++){
        swap(cur, pre);
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= m; k++){
                dp[cur][j][k] = 0;
                int v = (j+1)*(a[i]-a[i-1]);
                if(v <= k)
                    addmod(dp[cur][j][k], (j+1)*dp[pre][j+1][k-v]); //close
                    
                v = (j)*(a[i]-a[i-1]);
                if(v <= k)
                    addmod(dp[cur][j][k], (j+1)*dp[pre][j][k-v]); //open and close or join another (do nothing)
    
                v = (j-1)*(a[i]-a[i-1]);
                if(j and v <= k)
                    addmod(dp[cur][j][k], dp[pre][j-1][k-v]); //open
            }
        }
    }
    for(int k = 0; k <= m; k++)
        addmod(ans, dp[cur][0][k]);
    print(ans);
    
    return 0;
}