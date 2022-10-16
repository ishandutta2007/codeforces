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
const int MM = 3e5+5;

ll mod = 998244353;
int n;
vector<int> adj[MM];
ll dp[MM][3];
// in, out, isolated from children

void mulmod(ll &a, ll b){
    a = a*b%mod;
}

void dfs(int cur, int pre){
    dp[cur][0] = dp[cur][1] = dp[cur][2] = 1;
    for(int u: adj[cur]){
        if(u != pre){
            dfs(u, cur);
            mulmod(dp[cur][0], dp[u][0] - dp[u][2] + 2*dp[u][1]);
            // u is in, so can not have edge, but u must be connected to child; can have or not
            mulmod(dp[cur][1], 2*dp[u][0] -dp[u][2] + 2*dp[u][1]);
            mulmod(dp[cur][2], dp[u][0] - dp[u][2] + dp[u][1]);
        }
    }
}


int main(){
    scan(n);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1, 0);
    
    ll ans = dp[1][0] - dp[1][2] + dp[1][1] - 1; //can not have empty subgraph
    ans = (ans%mod+mod)%mod;
    print(ans);
    
//    for(int i = 1; i <= n; i++)
//        print(dp[i][0], dp[i][1], dp[i][2]);
    
    return 0;
}