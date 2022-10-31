#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int maxm = 100005;
int first[maxn],nxt[maxm],des[maxm],tot;
int vis[maxn];
int m,n;
vector<int> cir;
stack<pair<int,int> > stk;
inline void addEdge(int u,int v){
    tot++;
    des[tot] =v;
    nxt[tot] = first[u];
    first[u] = tot;
}
void input(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        addEdge(u,v);
    }
}
int findcir(int node,int Eid){
    if (vis[node]==2)return 0;
    if (vis[node]==1){
        cir.push_back(Eid);
        while (stk.top().first!=node){
            cir.push_back(stk.top().second);
            stk.pop();
        }
        return 1;
    }
    vis[node]=1;
    stk.push(make_pair(node,Eid));
    for (int t = first[node];t;t=nxt[t]){
        if (findcir(des[t],t))return 1;
    }
    vis[node] =2;
    stk.pop();
    return 0;
}
int findcir2(int node,int Eid){
    if (vis[node]==2)return 0;
    if (vis[node]==1)return 1;
    vis[node]=1;
    for (int t = first[node];t;t=nxt[t]){
        if (t==Eid)continue;
        if (findcir2(des[t],Eid))return 1;
    }
    vis[node]=2;
    return 0;
}
int check(int Eid){
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;i++)if (!vis[i])if (findcir2(i,Eid))return 0;
    return 1;
}
void solve(){
    memset(vis,0,sizeof vis);
    for (int i=1;i<=n;i++)if (!vis[i])if (findcir(i,-1))break;
    if (cir.empty()){
        cout<<"YES"<<endl;
        return ;
    }
    for (int Eid:cir){
        if (check(Eid)){
            cout<<"YES"<<endl;
            return ;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    input();
    solve();
    return 0;
}