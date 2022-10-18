#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=100005,thr=333,maxv=maxn/thr+5;

int n,m,q,t;
int idx[maxn];
vector<int> adj[maxn];
int mdp[maxn],mdpi[maxn];
int dia[maxn],da[maxn],db[maxn];
int val[maxn];
vector<int> dis[maxn];
vector<long long> pfx[maxn];

void dfs0(int u,int f){
    mdp[u]=0;mdpi[u]=u;
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            idx[v]=idx[u];
            dfs0(v,u);
            if(mdp[v]+1+mdp[u]>=dia[idx[u]]){
                dia[idx[u]]=mdp[v]+1+mdp[u];
                da[idx[u]]=mdpi[u];db[idx[u]]=mdpi[v];
            }
            if(mdp[v]+1>=mdp[u]){
                mdp[u]=mdp[v]+1;mdpi[u]=mdpi[v];
            }
        }
    }
}
void dfs1(int u,int f,int rd){
    val[u]=max(val[u],rd);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            dfs1(v,u,rd+1);
        }
    }
}
void dfs2(int u,int f){
    dis[idx[u]].push_back(val[u]);
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];
        if(v!=f){
            dfs2(v,u);
        }
    }
}

long long ans[maxn],dans[maxn];
vector<pair<int,int> > qry[maxn];
int lid[maxn];

long long tans[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!idx[i]){
            idx[i]=++t;
            dia[t]=0;da[t]=db[t]=i;
            dfs0(i,0);
            dfs1(da[t],0,0);dfs1(db[t],0,0);
            dfs2(i,0);
            sort(dis[t].begin(),dis[t].end(),greater<int>());
            pfx[t].resize(dis[t].size());
            for(int i=0;i<dis[t].size();i++)pfx[t][i]=dis[t][i]+(i?pfx[t][i-1]:0);
        }
    }
    for(int i=1;i<=q;i++){
        int a,b;cin>>a>>b;
        if(idx[a]==idx[b])ans[i]=-1;
        else{
            if(dis[idx[a]].size()<dis[idx[b]].size())swap(a,b);
            qry[idx[a]].push_back(make_pair(idx[b],i));
        }
        dans[i]=(long long)dis[idx[a]].size()*(long long)dis[idx[b]].size();
    }
    for(int i=1;i<=t;i++){
        if(dis[i].size()<thr){
            for(int j=0;j<qry[i].size();j++){
                int v=qry[i][j].first,id=qry[i][j].second;
                int wans=max(dia[i],dia[v]);
                vector<int>::iterator it=dis[v].begin();
                long long tcnt=0,tot=0;
                for(int k=(int)dis[i].size()-1;k>=0;k--){
                    while(it!=dis[v].end()&&*it+dis[i][k]+1>wans)it++;
                    if(it!=dis[v].begin())tot+=pfx[v][it-dis[v].begin()-1]+(it-dis[v].begin())*(long long)(dis[i][k]+1);
                    tcnt+=dis[v].end()-it;
                }
                ans[id]=tot+tcnt*wans;
            }
        }else{
            for(int j=0;j<=dis[i][0];j++)lid[j]=-1;
            for(int j=0;j<dis[i].size();j++)lid[dis[i][j]]=j;
            for(int j=dis[i][0];j>0;j--)lid[j-1]=max(lid[j-1],lid[j]);
            for(int j=1;j<=t;j++){
                if(i==j)continue;
                int wans=max(dia[i],dia[j]);
                long long tcnt=0,tot=0;
                for(int k=0;k<dis[j].size();k++){
                    int miv=wans-1-dis[j][k],id;
                    if(miv>dis[i][0])id=0;
                    else if(miv<0)id=dis[i].size();
                    else id=lid[miv]+1;
                    if(id!=0)tot+=pfx[i][id-1]+id*(long long)(dis[j][k]+1);
                    tcnt+=(int)dis[i].size()-id;
                }
                tans[j]=tot+tcnt*wans;
            }
            for(int j=0;j<qry[i].size();j++){
                ans[qry[i][j].second]=tans[qry[i][j].first];
            }
        }
    }
    for(int i=1;i<=q;i++){
        if(ans[i]==-1)cout<<"-1\n";
        else{
            long double o=ans[i]/(long double)dans[i];
            cout<<fixed<<setprecision(13)<<o<<'\n';
        }
    }
    return 0;
}