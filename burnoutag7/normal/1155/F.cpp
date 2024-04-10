#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n,m,cur,ans;
bool ban[250],ansv[250];
vector<pair<int,int>> g[15];
int dfn[15],low[15],dfc,bcc;
int U[250],V[250];

void getbcc(int x,int pe){
    dfn[x]=low[x]=++dfc;
    for(pair<int,int> &e:g[x])if(!dfn[e.first]&&!ban[e.second]){
        getbcc(e.first,e.second);
        low[x]=min(low[x],low[e.first]);
    }else if(e.second!=pe&&!ban[e.second]){
        low[x]=min(low[x],dfn[e.first]);
    }
    bcc+=dfn[x]==low[x];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int &u=U[i],&v=V[i];
        cin>>u>>v;
        g[u].emplace_back(v,i);
        g[v].emplace_back(u,i);
    }
    ans=cur=m;
    clock_t start=clock(),max=1.95*CLOCKS_PER_SEC;
    while(clock()-start<max){
        if(rng()%1000==0){
            cur=m;
            memset(ban,0,sizeof(ban));
        }else
        if(rng()%4){
            int id,t=50;
            while(ban[id=rng()%m]&&t--);
            cur-=!ban[id];
            ban[id]=1;
            memset(dfn,0,sizeof(dfn));
            dfc=bcc=0;
            getbcc(1,-1);
            if(bcc>1)ban[id]=0,cur++;
            else if(cur<ans){
                ans=cur;
                memcpy(ansv,ban,sizeof(ansv));
            }
        }else{
            int id,t=50;
            while(!ban[id=rng()%m]&&t--);
            cur+=ban[id];
            ban[id]=0;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<m;i++){
        int &u=U[i],&v=V[i];
        if(!ansv[i])cout<<u<<' '<<v<<endl;
    }

    return 0;
}