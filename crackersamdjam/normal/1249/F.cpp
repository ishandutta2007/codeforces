#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 202;

int n, k, dp[MM][MM], v[MM], sum[MM][MM];
vector<int> adj[MM];

void dfs(int cur, int pre){
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs(u, cur);
        
        for(int i = 1; i <= k; i++)
            sum[cur][i] += dp[u][i-1];
    }
    dp[cur][0] = v[cur] + sum[cur][k];
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        for(int i = 1; i <= k; i++){
            int j = max(k-i, i);
            dp[cur][i] = max(dp[cur][i], dp[u][i-1] + sum[cur][j] - (j ? dp[u][j-1] : 0));
        }
    }
    for(int i = k-1; i >= 0; i--)
        dp[cur][i] = max(dp[cur][i], dp[cur][i+1]);
}

int main(){
    
    scan(n, k);
    
    for(int i = 1; i <= n; i++)
        scan(v[i]);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    k++;
    dfs(1, 0);
    int ans = 0;
    for(int i = 0; i <= k; i++)
        ans = max(ans, dp[1][i]);
    print(ans);
    
    return 0;
}