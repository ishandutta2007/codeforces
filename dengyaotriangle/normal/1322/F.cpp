#include<bits/stdc++.h>

using namespace std;

const int maxn=500005;
const int maxl=20;

int n,m;
vector<int> adj[maxn];
int fa[maxn],dep[maxn];
int kfa[maxn][maxl];
vector<int> bdj[maxn];

int feq[maxn];


void dfs(int u){
    for(int v:adj[u])if(v!=fa[u]){
        fa[v]=u;
        dep[v]=dep[u]+1;
        kfa[v][0]=u;
        for(int j=1;j<maxl;j++)kfa[v][j]=kfa[kfa[v][j-1]][j-1];
        dfs(v);
    }
}
void dfs0(int u){
    for(int v:adj[u])if(v!=fa[u]){
        dfs0(v);
        feq[u]+=feq[v];
    }
}
inline int lca(int u,int v,int&us,int&vs){
    bool typ=0;
    if(dep[u]>dep[v])swap(u,v),typ=1;
    int d=dep[v]-dep[u];
    int v0=v;
    for(int i=maxl-1;i>=0;i--)if((d>>i)&1)v=kfa[v][i];
    if(u==v){
        int d1=d-1;
        for(int i=maxl-1;i>=0;i--)if((d1>>i)&1)v0=kfa[v0][i];
        if(typ)us=v0;
        else vs=v0;
        return u;
    }
    for(int i=maxl-1;i>=0;i--)if(kfa[u][i]!=kfa[v][i])u=kfa[u][i],v=kfa[v][i];
    if(typ)us=v,vs=u;
    else us=u,vs=v;
    return fa[u];
}
int col[maxn];

vector<array<vector<int>,2> > vq[maxn];

void dfsx(int rt,int u){
    if(u)vq[rt].back()[col[u]].push_back(u);
    for(int v:bdj[u]){
        if(col[v]==-1){
            col[v]=!col[u];
            dfsx(rt,v);
        }else if(col[v]==col[u]){
            cout<<"-1\n";
            exit(0);
        }
    }
}

void dfs1(int u){
    bdj[0].clear();
    col[0]=-1;
    for(int v:adj[u])if(v!=fa[u]){
        col[v]=-1;
        if(feq[v]){
            bdj[0].push_back(v);
            bdj[v].push_back(0);
        }
    }
    vq[u].emplace_back();
    col[0]=0;dfsx(u,0);
    for(int v:adj[u])if(v!=fa[u]){
        if(col[v]==-1){
            vq[u].emplace_back();
            col[v]=0;dfsx(u,v);
        }
    }
    //cerr<<u<<' '<<vq[u].size()<<endl;
    for(int v:adj[u])if(v!=fa[u]){
        dfs1(v);
    }
}
int cc;

int dp[maxn][2];

bool ok[maxn];

void dfs2(int u){
    for(int v:adj[u])if(v!=fa[u]){
        dfs2(v);
    }
    int dc=(cc+1)/2;

    for(int t=0;t<2;t++){
        int tl=1,tr=cc,xl=1,xr=dc;
        for(int i=0;i<vq[u].size();i++){
            int cl0=1,cr0=cc;
            int cl1=1,cr1=cc;
            for(int x:vq[u][i][0]){
                cr0=min(cr0,dp[x][0]-1);
                cl1=max(cl1,dp[x][1]+1);
            }
            for(int x:vq[u][i][1]){
                cl0=max(cl0,dp[x][1]+1);
                cr1=min(cr1,dp[x][0]-1);
            }/*
            if(i==0){
                if(t==0)tl=max(tl,cl1),tr=min(tr,cr1);
                else tl=max(tl,cl0),tr=min(tr,cr1);
            }else{

            }*/
            //cerr<<u<<"->"<<' '<<cl0<<' '<<cr0<<' '<<cl1<<' '<<cr1<<endl;
            //cerr<<cl0<<' '<<cc+1-cr1<<' '<<cl1<<' '<<cc+1-cr0<<endl;
            if(i==0){
                if(t==0)tl=cl1,tr=cr1;//for(int j=1;j<=cc;j++)ok[j]&=(cl1<=j&&j<=cr1);
                else tl=cl0,tr=cr0;//for(int j=1;j<=cc;j++)ok[j]&=(cl0<=j&&j<=cr0);
            }else{
                cr0=min(cr0,dc);
                cr1=min(cr1,dc);
                int pl=dc+1,pr=0;
                if(cl0<=cr0){
                    pl=min(pl,cl0);pr=max(pr,cr0);
                }
                if(cl1<=cr1){
                    pl=min(pl,cl1);pr=max(pr,cr1);
                }
                xl=max(xl,pl);xr=min(xr,pr);
            }
        }
        if(t==0){
            dp[u][0]=0;
            int yl=max(tl,xl),yr=min(tr,xr);
            if(yl<=yr)dp[u][0]=max(dp[u][0],yr);
            yl=max(tl,cc+1-xr),yr=min(tr,cc+1-xl);
            if(yl<=yr)dp[u][0]=max(dp[u][0],yr);
        }else{
            dp[u][1]=cc+1;
            int yl=max(tl,xl),yr=min(tr,xr);
            if(yl<=yr)dp[u][1]=min(dp[u][1],yl);
            yl=max(tl,cc+1-xr),yr=min(tr,cc+1-xl);
            if(yl<=yr)dp[u][1]=min(dp[u][1],yl);
        }
    }
    //cerr<<cc<<' '<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<endl;
}

int res[maxn];

void dfs3(int u,bool typ,int g){
    res[u]=g;
    for(int i=0;i<vq[u].size();i++){
        int cl0=1,cr0=cc;
        int cl1=1,cr1=cc;
        for(int x:vq[u][i][0]){
            cr0=min(cr0,dp[x][0]-1);
            cl1=max(cl1,dp[x][1]+1);
        }
        for(int x:vq[u][i][1]){
            cl0=max(cl0,dp[x][1]+1);
            cr1=min(cr1,dp[x][0]-1);
        }
        bool p=0;
        if(i==0){
            if(typ==0){
                //cl1-cr1
                p=1;
            }else{
                //cl0-cr0
                p=0;
            }
        }else{
            if(cl0<=g&&cr0>=g){
                p=0;
            }else{
                p=1;
            } 
        }
        for(int x:vq[u][i][0]){
            if(p){
                dfs3(x,1,dp[x][1]);
            }else{
                dfs3(x,0,dp[x][0]);
            }
        }
        for(int x:vq[u][i][1]){
            if(p){
                dfs3(x,0,dp[x][0]);
            }else{
                dfs3(x,1,dp[x][1]);
            }
        }
        
    }

}

bool chk(bool typ){
    dfs2(1);
    if(typ){
        dfs3(1,0,dp[1][0]);
    }
    return dp[1][0];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        int cu=0,cv=0;
        int l=lca(u,v,cu,cv);
        if(cu)feq[u]++,feq[cu]--;
        if(cv)feq[v]++,feq[cv]--;
        if(cu&&cv){
            bdj[cu].push_back(cv);
            bdj[cv].push_back(cu);
        }
    }
    dfs0(1);
    //for(int i=1;i<=n;i++)cerr<<feq[i]<<endl;
    dfs1(1);
    int l=1,r=n;
    while(l<r){
        cc=(l+r)/2;
        if(chk(0))r=cc;
        else l=cc+1;
    }
    cout<<l<<'\n';
    cc=l;
    chk(1);
    for(int i=1;i<=n;i++)cout<<res[i]<<' ';
    return 0;
}