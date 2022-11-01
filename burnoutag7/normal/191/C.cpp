#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];
int hson[100005],fa[100005],dep[100005],sz[100005],top[100005],dfn[100005],dfncnt,rnk[100005];

int hldprec(int x,int p,int d){
    dep[x]=d;
    sz[x]=1;
    for(int &y:g[x])if(y!=p){
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
    dfn[x]=++dfncnt;
    rnk[dfncnt]=x;
    if(hson[x]){
        hlddec(hson[x],head);
        for(int &y:g[x])if(y!=fa[x]&&y!=hson[x]){
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

int pre[100005];

void deal(int u,int v){
    while(top[u]!=top[v]){
        if(dep[top[u]]>dep[top[v]]){
            pre[dfn[top[u]]]++;
            pre[dfn[u]+1]--;
            u=fa[top[u]];
        }else{
            pre[dfn[top[v]]]++;
            pre[dfn[v]+1]--;
            v=fa[top[v]];
        }
    }
    pre[min(dfn[u],dfn[v])+1]++;
    pre[max(dfn[u],dfn[v])+1]--;
}

map<pair<int,int>,int> edge;
int ans[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
        edge[make_pair(a,b)]=i;
        edge[make_pair(b,a)]=i;
    }
    hldprec(1,-1,0);
    hlddec(1,1);
    {
        int k;
        cin>>k;
        while(k--){
            int a,b;
            cin>>a>>b;
            deal(a,b);
        }
    }
    for(int i=1;i<=n;i++)pre[i]+=pre[i-1];
    for(int i=2;i<=n;i++){
        ans[edge[make_pair(i,fa[i])]]=pre[dfn[i]];
    }
    for(int i=1;i<n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}