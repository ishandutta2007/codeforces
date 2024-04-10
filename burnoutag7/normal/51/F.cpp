#include<bits/stdc++.h>
using namespace std;

int n,m,dfn[2005],low[2005],ibcc[2005],bccsz[2005],dfncnt,bcccnt;
vector<int> g[2005],ng[2005];
int st[2005],stcnt;

void getbcc(int x,int p){
    dfn[x]=low[x]=++dfncnt;
    st[stcnt++]=x;
    for(int &y:g[x])if(!dfn[y]){
        getbcc(y,x);
        low[x]=min(low[x],low[y]);
    }else if(y!=p){
        low[x]=min(low[x],dfn[y]);
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

int icc[2005],cccnt,ccsz[2005];

void getcc(int x,int p){
    icc[x]=cccnt;
    ccsz[cccnt]+=ng[x].size()>1;
    for(int &y:ng[x])if(y!=p){
        getcc(y,x);
    }
}

void far(int x,int p,int d,int &res,int &rval){
    if(d>rval){
        rval=d;
        res=x;
    }
    for(int &y:ng[x])if(y!=p){
        far(y,x,d+1,res,rval);
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
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    int ans=-1;
    for(int i=1;i<=n;i++)if(!dfn[i]){
        ans++;
        getbcc(i,-1);
    }
    for(int i=1;i<=bcccnt;i++)ans+=bccsz[i]-1;
    for(int x=1;x<=n;x++){
        for(int &y:g[x]){
            if(ibcc[x]!=ibcc[y]){
                ng[ibcc[x]].emplace_back(ibcc[y]);
            }
        }
    }
    for(int i=1;i<=bcccnt;i++){
        if(!icc[i]){
            ++cccnt;
            getcc(i,-1);
            int f=i,fv=0;
            far(i,-1,0,f,fv);
            int f2=f,fv2=0;
            far(f,-1,0,f2,fv2);
            ans+=ccsz[cccnt]-max(0,fv2-1);
        }
    }
    cout<<ans<<endl;

    return 0;
}