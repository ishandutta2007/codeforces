#include<bits/stdc++.h>
using namespace std;

int n,m,q,dfn[200005],low[200005],ibcc[200005],dfc,nbcc;
vector<pair<int,int>> g[200005];
int st[200005],stcnt;

void getbcc(int x,int pe){
    dfn[x]=low[x]=++dfc;
    st[stcnt++]=x;
    for(pair<int,int> &e:g[x])if(!dfn[e.first]){
        getbcc(e.first,e.second);
        low[x]=min(low[x],low[e.first]);
    }else if(e.second!=pe){
        low[x]=min(low[x],dfn[e.first]);
    }
    if(dfn[x]==low[x]){
        ibcc[x]=++nbcc;
        int y;
        while((y=st[--stcnt])!=x){
            ibcc[y]=nbcc;
        }
    }
}

vector<int> ng[200005];
int hson[200005],fa[200005],dep[200005],sz[200005],top[200005];

int hldprec(int x,int p,int d){
    dep[x]=d;
    sz[x]=1;
    for(int& y:ng[x])if(y!=p){
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
    if(hson[x]){
        hlddec(hson[x],head);
        for(int &y:ng[x])if(y!=fa[x]&&y!=hson[x]){
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

int up[200005],down[200005];
bool vis[200005];

void calc(int x,int p){
    vis[x]=true;
    for(int &y:ng[x])if(y!=p){
        calc(y,x);
        up[x]+=up[y];
        down[x]+=down[y];
    }
    if(up[x]&&down[x]){
        cout<<"No";
        exit(0);
    }
}

struct UnionFind{
    int sz;
    vector<int> fa;

    UnionFind(int _sz=100000){
        fa.resize((sz=_sz)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    UnionFind uf(n);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
        uf.unite(u,v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])getbcc(i,-1);
    for(int x=1;x<=n;x++){
        for(pair<int,int> &e:g[x]){
            if(ibcc[x]!=ibcc[e.first]){
                ng[ibcc[x]].emplace_back(ibcc[e.first]);
            }
        }
    }
    for(int i=1;i<=n;i++)if(!sz[i])hldprec(i,-1,0);
    for(int i=1;i<=n;i++)if(!top[i])hlddec(i,i);
    while(q--){
        int u,v,anc;
        cin>>u>>v;
        if(uf.find(u)!=uf.find(v)){
            cout<<"No";
            return 0;
        }
        u=ibcc[u];
        v=ibcc[v];
        anc=lca(u,v);
        up[u]++;
        up[anc]--;
        down[v]++;
        down[anc]--;
    }
    for(int i=1;i<=nbcc;i++)if(!vis[i])calc(i,-1);
    cout<<"Yes";

    return 0;
}