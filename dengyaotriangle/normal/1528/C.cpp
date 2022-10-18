#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;
const int maxl=20;

int n;
int fa[maxn],fb[maxn];
vector<int> adj[maxn],bdj[maxn];
int dfn[maxn],otn[maxn],c1;
int kfa[maxn][maxl];
int bit[maxn];

void chg(int u,int c){
    for(;u<=n;u+=u&-u)bit[u]+=c;
}
int qry(int u){
    int ret=0;
    for(;u;u-=u&-u)ret+=bit[u];
    return ret;
}
void dfs1(int u){
    dfn[u]=++c1;
    for(int v:bdj[u]){
        kfa[v][0]=u;
        for(int i=1;i<maxl;i++)kfa[v][i]=kfa[kfa[v][i-1]][i-1];
        dfs1(v);
    }
    otn[u]=c1;
}
int cans;
void dfs2(int u,int ans){
    int fli=-1;
    if(qry(dfn[u])==0){
        ans++;
    }else{
        int cu=u;
        for(int j=maxl-1;j>=0;j--){
            if(kfa[cu][j]&&qry(dfn[kfa[cu][j]]))cu=kfa[cu][j];
        }
        fli=cu;
        chg(dfn[fli],-1);chg(otn[fli]+1,1);
    }
    cans=max(cans,ans);
    chg(dfn[u],1);
    chg(otn[u]+1,-1);
    for(int v:adj[u]){
        dfs2(v,ans);
    }
    chg(dfn[u],-1);
    chg(otn[u]+1,1);
    if(fli!=-1){
        chg(dfn[fli],1);chg(otn[fli]+1,-1);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)adj[i].clear(),bdj[i].clear(),bit[i]=0;
        for(int i=2;i<=n;i++)cin>>fa[i],adj[fa[i]].push_back(i);
        for(int i=2;i<=n;i++)cin>>fb[i],bdj[fb[i]].push_back(i);
        c1=0;
        dfs1(1);
        cans=0;
        dfs2(1,0);
        cout<<cans<<'\n';
    }
    return 0;
}