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
const int MM = 2e5+5;

int n, a[MM], b[MM], sa[MM], sb[MM], wa[MM];
ll dp[MM], c[MM];
vector<int> adj[MM];

void dfs(int cur, int pre){
    sa[cur] = (a[cur] == 0 and b[cur] == 1);
    sb[cur] = (b[cur] == 0 and a[cur] == 1);
    wa[cur] = (a[cur] != b[cur]);
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs(u, cur);
        sa[cur] += sa[u];
        sb[cur] += sb[u];
        wa[cur] += wa[u];
    }
//    print(cur, sa[cur], sb[cur], wa[cur]);
}

ll ans;

void dfs2(int cur, int pre){
    dp[cur] = dp[pre];
    if(c[cur] < dp[cur] or cur == 1){
        ans += (c[cur]-dp[cur])*2*min(sa[cur], sb[cur]);
        dp[cur] = c[cur];
    }
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs2(u, cur);
    }
}


int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(c[i], a[i], b[i]);
    }
    for(int i = 0,u,v; i < n-1; i++){
        scan(u, v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 0);
    dfs2(1, 0);
    print(sa[1] != sb[1] ? -1 : ans);
    
    return 0;
}