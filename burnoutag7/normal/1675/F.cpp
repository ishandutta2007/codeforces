#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> g[200005];
int hson[200005],fa[200005],dep[200005],sz[200005],top[200005],dfn[200005],dfc;

int hldprec(int x,int p,int d){
    dep[x]=d;
    sz[x]=1;
    hson[x]=0;
    for(int y:g[x])if(y!=p){
        sz[x]+=hldprec(y,x,d+1);
        fa[y]=x;
        if(sz[y]>sz[hson[x]]){
            hson[x]=y;
        }
    }
    return sz[x];
}

void hlddec(int x,int head){
    top[x]=head;
    dfn[x]=++dfc;
    if(hson[x]){
        hlddec(hson[x],head);
        for(int y:g[x])if(y!=fa[x]&&y!=hson[x]){
            hlddec(y,y);
        }
    }
}

int lca(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            u=fa[top[u]];
        }else{
            v=fa[top[v]];
        }
    }
    return dep[u]<dep[v]?u:v;
}

int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}

int n,k,x,y,a[200005];

void mian(){
    for(int i=1;i<=n;i++)g[i].clear();
    dfc=0;
    cin>>n>>k>>x>>y;
    a[0]=x;a[1]=y;
    k+=2;
    for(int i=2;i<k;i++)cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    sort(a,a+k,[&](int x,int y){
        return dfn[x]<dfn[y];
    });
    int ans=0;
    a[k]=a[0];
    for(int i=0;i<k;i++)ans+=dis(a[i],a[i+1]);
    ans-=dis(x,y);
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}