#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
const int HASH_NUM = 19260817;
typedef long long LL;
int u[maxn],v[maxn];
int m,n;
LL bas[maxn];
LL has[maxn];
map<LL,int> f;int cnt;
set<pair<int,int> >E;
int first[maxn],des[maxn*2],nxt[maxn*2],tot,d[maxn];
int flag[maxn],ans[maxn],score;
inline void addEdge(int x,int y){
    if (E.count(make_pair(x,y)))return;
    E.insert(make_pair(x,y));
    tot++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
    d[y]++;
}
void init(){
    bas[0]=1;
    for (int i=1;i<maxn;i++){
        bas[i] = bas[i-1]*HASH_NUM;
    }
}
void input(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d %d",u+i,v+i);
        has[u[i]]+=bas[v[i]];
        has[v[i]]+=bas[u[i]];
    }
    for (int i=1;i<=n;i++){
        has[i]+=bas[i];
    }
}
void dfs(int x){
    ans[x] = ++score;
    for (int t = first[x];t;t=nxt[t]){
        int v = des[t];
        if (ans[v])continue;
        dfs(v);
    }
}
void solve(){
    for (int i=1;i<=n;i++){
        if (!f[has[i]]){
            f[has[i]] = ++cnt;
        }
        flag[i] = f[has[i]];
    }
    for (int i=0;i<m;i++){
        if (flag[u[i]]!=flag[v[i]]){
            addEdge(flag[u[i]],flag[v[i]]);
            addEdge(flag[v[i]],flag[u[i]]);
            if (d[flag[u[i]]]==3||d[flag[v[i]]]==3){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    queue<int> Q;
    for (int i=1;i<=cnt;i++){
        if (d[i]==1){
            Q.push(i);
        }
    }
    while (!Q.empty()){
        int q = Q.front();
        Q.pop();
        if (ans[q])continue;
        score++;
        dfs(q);
    }
    for (int i=1;i<=cnt;i++){
        ++score;
        if (!ans[i])ans[i] = ++score;
    }
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++){
        printf("%d ",ans[flag[i]]);
    }
}
int main(){
    init();
    input();
    solve();
    return 0;
}