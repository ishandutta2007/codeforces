#include<bits/stdc++.h>
using namespace std;

int n,m,dfn[400005],low[400005],ibcc[400005],bccsz[400005],dfncnt,bcccnt;
vector<pair<int,int>> g[400005],ng[400005];
pair<int,int> edge[400005];
bool fix[400005];
int st[400005],stcnt;

void getbcc(int x,int pe){
    dfn[x]=low[x]=++dfncnt;
    st[stcnt++]=x;
    for(pair<int,int> &e:g[x])if(!dfn[e.first]){
        getbcc(e.first,e.second);
        low[x]=min(low[x],low[e.first]);
    }else if(e.second!=pe){
        low[x]=min(low[x],dfn[e.first]);
    }
    if(dfn[x]==low[x]){
        ibcc[x]=++bcccnt;
        bccsz[bcccnt]++;
        int y;
        while((y=st[--stcnt])!=x){
            ibcc[y]=bcccnt;
            bccsz[bcccnt]++;
        }
    }
}

bool vis[400005];

void dfsin(int x,int p){
    vis[x]=1;
    for(pair<int,int> &e:g[x])if(e.first!=p&&ibcc[x]==ibcc[e.first]){
        if(!fix[e.second])edge[e.second]=make_pair(x,e.first),fix[e.second]=1;
        if(!vis[e.first])dfsin(e.first,x);
    }
}

void dfsout(int x,int p){
    for(pair<int,int> &e:ng[x])if(e.first!=p){
        if(ibcc[edge[e.second].first]==x){
            swap(edge[e.second].first,edge[e.second].second);
        }
        fix[e.second]=1;
        dfsout(e.first,x);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
        edge[i]=make_pair(a,b);
    }
    getbcc(1,0);
    for(int i=1;i<=n;i++)if(!vis[i])dfsin(i,0);
    for(int x=1;x<=n;x++){
        for(pair<int,int> &e:g[x]){
            if(ibcc[x]!=ibcc[e.first]){
                ng[ibcc[x]].emplace_back(ibcc[e.first],e.second);
            }
        }
    }
    int mxbcc=-1,mxsz=0;
    for(int i=1;i<=bcccnt;i++){
        if(bccsz[i]>mxsz){
            mxsz=bccsz[i];
            mxbcc=i;
        }
    }
    dfsout(mxbcc,0);
    cout<<mxsz<<endl;
    for(int i=1;i<=m;i++){
        cout<<edge[i].first<<' '<<edge[i].second<<endl;
    }

    return 0;
}