#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;
int n;
vector<pair<int,int> > adj[maxn];

int dfn[maxn],low[maxn],c1,idx[maxn],c2;
int sidx[maxn];

int stk[maxn],ps;
void tarjan(vector<pair<int,int> >* adj,int u,int f){
    dfn[u]=low[u]=++c1;
    stk[++ps]=u;
    for(auto&e:adj[u]){
        int v,w;tie(v,w)=e;
        if(w==f)continue;
        if(!dfn[v]){
            tarjan(adj,v,w),low[u]=min(low[u],low[v]);
            
        }else low[u]=min(low[u],dfn[v]);
    }
    if(low[u]>=dfn[u]){
        int w;++c2;
        do{
            w=stk[ps--];
            idx[w]=c2;
        }while(w!=u);
    }
}

vector<int> bdj[maxn];
bool rvis[maxn];
int efn[maxn],refn[maxn*3],c3;
const int maxl=20;

int dfx[maxl][maxn*3];

void dfs(int u,int f){
    efn[u]=++c3;
    refn[c3]=u;
    rvis[u]=1;
    dfx[0][c3]=efn[u];
    for(int v:bdj[u])if(v!=f){
        dfs(v,u);
        dfx[0][++c3]=efn[u];
    }
}

inline int lca(int u,int v){
    if(u>v)swap(u,v);
    int lg=31-__builtin_clz(v-u+1);
    return min(dfx[lg][u],dfx[lg][v-(1<<lg)+1]);
}
int n1,m1;
int x[maxn];
pair<int,int> rx[maxn];
int z[maxn*3],zs;
int y[maxn],ys;
vector<pair<int,int> > cdj[maxn];

int c4;
void link(int u,int v){
    ++c4;
    cdj[refn[u]].push_back({refn[v],c4}),cdj[refn[v]].push_back({refn[u],c4});
}
int R=0;

int rotate(int element){
   element=(element+R)%n;if(element==0) {element=n;}
   return element;
}
int z1[maxn*3],z1s;
void fuck(int qi){
    zs=0;
    cin>>n1>>m1;
    for(int i=1;i<=n1;i++)cin>>x[i],x[i]=rotate(x[i]),x[i]=sidx[x[i]],z[++zs]=x[i];
    for(int i=1;i<=m1;i++){
        cin>>rx[i].first>>rx[i].second;
        rx[i].first=rotate(rx[i].first);
        rx[i].second=rotate(rx[i].second);
        rx[i].first=sidx[rx[i].first];
        rx[i].second=sidx[rx[i].second];
        z[++zs]=rx[i].first,z[++zs]=rx[i].second;
        link(efn[rx[i].first],efn[rx[i].second]);
    }
    z1s=0;
    for(int i=1;i<=zs;i++)z[i]=efn[z[i]];
    sort(z+1,z+1+zs);
    zs=unique(z+1,z+1+zs)-z-1;
    for(int i=1;i<=zs;i++)z1[++z1s]=z[i];
    ys=0;
    y[++ys]=z[1];
    for(int i=2;i<=zs;i++){
        int u=z[i];
        int p=lca(u,y[ys]);
        int lys=ys;
        while(ys&&y[ys]>p)ys--;
        for(int p=ys+1;p<lys;p++){
            link(y[p],y[p+1]);
        }
        int k=ys+1<=lys?y[ys+1]:-1;
        if(ys==0){
            if(p!=-1){
                if(k!=-1)link(p,k);
                y[++ys]=p;
                z1[++z1s]=p;
            }
        }else{
            z1[++z1s]=p;
            if(p!=y[ys])y[++ys]=p;
            if(k!=-1)link(y[ys],k);
        }
        y[++ys]=u;
    }
    while(ys>=2){
        link(y[ys-1],y[ys]);
        ys--;
    }
    c1=1;
    for(int i=1;i<=zs;i++)if(!dfn[refn[z[i]]]){
        int q=refn[z[i]];
        tarjan(cdj,q,-1);
    }
    bool ok=1;
    for(int i=2;i<=n1;i++){
        if(idx[x[i]]!=idx[x[i-1]]){ok=0;break;}
    }
    cout<<(ok?"YES\n":"NO\n");
    R+=(ok?qi:0);R%=n;
    for(int i=1;i<=z1s;i++)cdj[refn[z1[i]]].clear(),dfn[refn[z1[i]]]=0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int m,q;
    cin>>n>>m>>q;
    while(m--){
        int u,v;cin>>u>>v;
        adj[u].push_back({v,m});
        adj[v].push_back({u,m});
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]){
            tarjan(adj,i,-1);
        }
    }
    for(int i=1;i<=n;i++){
        for(auto&e:adj[i]){
            int v=e.first;
            if(idx[i]!=idx[v])bdj[idx[i]].push_back(idx[v]);
        }
    }
    for(int i=1;i<=c2;i++){
        sort(bdj[i].begin(),bdj[i].end());
        bdj[i].erase(unique(bdj[i].begin(),bdj[i].end()),bdj[i].end());
    }
    for(int i=1;i<=c2;i++){
        if(!rvis[i]){
            dfs(i,0);
            dfx[0][++c3]=-1;
        }
    }
    for(int j=1;j<maxl;j++){
        for(int i=1;i+(1<<j)-1<=c3;i++){
            dfx[j][i]=min(dfx[j-1][i],dfx[j-1][i+(1<<j>>1)]);
        }
    }
    memcpy(sidx,idx,sizeof(idx));
    memset(dfn,0,sizeof(dfn));
    for(int qi=1;qi<=q;qi++){
        fuck(qi);
    }
    return 0;
}