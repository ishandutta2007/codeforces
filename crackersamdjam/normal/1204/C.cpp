#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 105, MN = 1e6+2;

int n, m, adj[MM][MM], path[MN];
int dis[MM][MM], last[MN], dp[MN];
char s[MM];
stack<int> ans;

void go(int st){
    queue<int> q;
    q.push(st);
    dis[st][st] = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int u = 1; u <= n; u++){
            if(!adj[cur][u])
                continue;
            
            if(dis[st][cur]+1 < dis[st][u]){
                dis[st][u] = dis[st][cur]+1;
                q.push(u);
            }
        }
    }
}

int main(){
    
    memset(dis, 0x3f, sizeof dis);
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            adj[i][j] = gc-'0';
        gc;
    }
    
    scan(m);
    
    for(int i = 1; i <= m; i++)
        scan(path[i]);
    
    memset(dis, 0x3f, sizeof dis);
    memset(dp, 0x3f, sizeof dp);
    
    for(int i = 1; i <= n; i++)
        go(i);
    
    dp[1] = 1;
    
    for(int i = 1; i < m; i++){
        int cur = path[i];
        for(int u = 1; u <= n; u++){
            int t = i+dis[cur][u];
            if(t > m || path[t] != u)
                continue;
            if(dp[i]+1 < dp[t]){
                dp[t] = dp[i]+1;
                last[t] = i;
            }
        }
    }
    
    print(dp[m]);
    
    int cur = m;
    while(cur != 1){
        ans.push(path[cur]);
        cur = last[cur];
    }
    ans.push(path[cur]);
    
    while(!ans.empty()){
        printn(ans.top()), pc(32);
        ans.pop();
    }
    
    return 0;
}