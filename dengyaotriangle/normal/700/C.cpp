#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=1005;
const int maxm=30005;

int n,m,s,t;
int eu[maxm],ev[maxm],ew[maxm];
vector<pair<int,int> > adj[maxn];
bool vis[maxn];
vector<int> lk,pth;
bool flg=0;
void dfs0(int u){
    if(u==t){
        flg=1;
        pth=lk;
        return;
    }
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].first;
        int w=adj[u][i].second;
        if(!vis[v]){
            lk.push_back(w);
            dfs0(v);
            lk.pop_back();
        }
        if(flg)return;
    }
}
int del;
int c1;
int dfn[maxn],low[maxn];
int li,lv;

bool tarjan(int u,int fe){
    bool f=u==t;
    dfn[u]=low[u]=++c1;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].first,w=adj[u][i].second;
        if(del==w)continue;
        if(!dfn[v]){
            bool t=tarjan(v,w);
            f|=t;
            low[u]=min(low[u],low[v]);
            if(low[v]>dfn[u]){
                if(t&&ew[w]<lv){
                    lv=ew[w];li=w;
                }
            }
        }else if(w!=fe)low[u]=min(low[u],dfn[v]);
    }
    return f;
}

long long cst=LLONG_MAX;
vector<int> h;
int main(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        cin>>eu[i]>>ev[i]>>ew[i];
        adj[eu[i]].push_back(make_pair(ev[i],i));
        adj[ev[i]].push_back(make_pair(eu[i],i));
    }
    dfs0(s);
    if(!flg){
        cout<<0<<'\n'<<0;return 0;
    }
    for(int i=0;i<pth.size();i++){
        del=pth[i];
        long long w=ew[pth[i]];
        c1=0;
        for(int i=1;i<=n;i++)dfn[i]=0;
        lv=INT_MAX;
        bool f=tarjan(s,0);
        if(!f){
            if(w<cst){cst=w;h={del};}
        }else{
            w+=lv;
            if(w<cst){cst=w;h={del,li};}
        }
    }
    if(cst>INT_MAX)cout<<-1;
    else{
        cout<<cst<<endl;
        cout<<h.size()<<endl;
        for(int i=0;i<h.size();i++)cout<<h[i]<<' ';
    }
    return 0;
}