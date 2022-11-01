// --------
//< 114514 >
// --------
//        \   ^__^
//         \  (oo)\_______
//            (__)\       )\/\
//                ||----w |
//                ||     ||
#include<bits/stdc++.h>
using namespace std;

int n,m,z[300005],dfn[300005],low[300005],ibcc[300005],bccsz[300005],dfncnt,bcccnt,hav[300005];
vector<pair<int,int>> g[300005],ng[300005];
int st[300005],stcnt;

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

bool dfs(const int& x,const int& p,const int& s,bool c){
    c|=hav[x];
    if(x==s){
        return c;
    }
    bool r=false;
    for(pair<int,int>& e:ng[x])if(e.first!=p){
        r|=dfs(e.first,x,s,c|e.second);
    }
    return r;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        static int x,y,zz;
        cin>>x>>y>>zz;
        g[x].emplace_back(y,i);
        g[y].emplace_back(x,i);
        z[i]=zz;
    }
    getbcc(1,-1);
    for(int x=1;x<=n;x++){
        for(pair<int,int> &e:g[x]){
            if(ibcc[x]!=ibcc[e.first]){
                ng[ibcc[x]].emplace_back(ibcc[e.first],z[e.second]);
            }else{
                hav[ibcc[x]]|=z[e.second];
            }
        }
    }
    int u,v;
    cin>>u>>v;
    cout<<(dfs(ibcc[u],-1,ibcc[v],0)?"YES\n":"NO\n");

    return 0;
}