#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
int first[maxn],des[maxn],nxt[maxn],tot;
int a[maxn];
int dp[maxn][26];
int d[maxn];
int m,n;
int vis[maxn];
int findCir(int node){
    if (vis[node]==2)return 0;
    if (vis[node]==1)return 1;
    vis[node]=1;
    for (int t = first[node];t;t=nxt[t]){
        int v = des[t];
        if (findCir(v))return 1;
    }
    vis[node]=2;
    return 0;
}
inline void addEdge(int u,int v){
    tot++;
    des[tot]=v;
    nxt[tot] =first[u];
    first[u] = tot;
    d[v]++;
}
char s[maxn];
void input(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++){
        a[i] = s[i]-'a';
    }
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(v,u);
    }
}
queue<int> Q;
void solve(){
    for (int i=1;i<=n;i++){
        if (!vis[i]){
            if (findCir(i)){
                cout<<-1<<endl;
                return;
            }
        }
    }
    for (int i=1;i<=n;i++){
        if (!d[i]){
            Q.push(i);
            int id = a[i];
        }
    }
    while (!Q.empty()){
        int u = Q.front();
        Q.pop();
        dp[u][a[u]]++;
        for (int t = first[u];t;t=nxt[t]){
            int v =des[t];
            for (int i=0;i<26;i++){
                dp[v][i] = max(dp[v][i],dp[u][i]);
            }
            d[v]--;
            if (d[v]==0)Q.push(v);
        }
    }
    int ans =0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<26;j++){
            ans = max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
}
int main(){
    input();
    solve();
    return 0;
}