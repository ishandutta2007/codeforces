#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> g[10005];
int dep[10005],fa[10005],edge[10005];
int oneven[10005],onodd[10005],icc[10005],ccnt;
vector<int> err[10005],saf[10005],tre[10005],res[10005];
vector<int> ans;

void getree(int x,int p){
    fa[x]=p;icc[x]=ccnt;
    for(pair<int,int> &e:g[x])if(dep[e.first]==-1){
        dep[e.first]=dep[x]+1;
        edge[e.first]=e.second;
        getree(e.first,x);
    }
}

void getstat(int x,int p){
    for(pair<int,int> &e:g[x])if(fa[e.first]==x){
        getstat(e.first,x);
        onodd[x]+=onodd[e.first];oneven[x]+=oneven[e.first];
    }
    if(onodd[x]==err[icc[x]].size()&&oneven[x]==0)res[icc[x]].emplace_back(edge[x]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    memset(dep,-1,sizeof(dep));
    for(int i=1;i<=n;i++)if(dep[i]==-1){
        dep[i]=0;++ccnt;
        getree(i,-1);
    }
    for(int x=1;x<=n;x++)for(pair<int,int> &e:g[x]){
        int &y=e.first;
        if(dep[x]<dep[y])continue;
        if(fa[x]==y){
            tre[icc[x]].emplace_back(e.second);
        }else
        if(dep[x]-dep[y]&1){
            oneven[x]++;oneven[y]--;
            saf[icc[x]].emplace_back(e.second);
        }else{
            onodd[x]++;onodd[y]--;
            err[icc[x]].emplace_back(e.second);
        }
    }
    ccnt=0;
    for(int i=1;i<=n;i++)if(icc[i]>ccnt){
        ++ccnt;
        getstat(i,-1);
    }
    for(int i=1;i<=ccnt;i++){
        if(!err[i].empty()){
            if(!ans.empty()){
                cout<<"0\n";
                return 0;
            }
            if(err[i].size()==1)ans.emplace_back(err[i].front());
            if(res[i].empty()&&err[i].size()!=1){
                cout<<"0\n";
                return 0;
            }else{
                for(int &it:res[i])ans.emplace_back(it);
            }
        }
    }
    if(ans.empty())
        for(int i=1;i<=ccnt;i++){
            for(int &it:saf[i])ans.emplace_back(it);
            for(int &it:tre[i])ans.emplace_back(it);
        }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(int &it:ans)cout<<it<<' ';

    return 0;
}