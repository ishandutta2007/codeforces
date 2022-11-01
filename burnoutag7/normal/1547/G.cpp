#include<bits/stdc++.h>
using namespace std;

int n,m,dfn[400005],low[400005],dfc,scc,iscc[400005],ind[400005];
bool inst[400005],nf[400005],snf[400005],vis[400005];
vector<int> g[400005],tpv;
stack<int> st;

void tarjan(int x){
    dfn[x]=low[x]=++dfc;
    st.push(x);
    inst[x]=1;
    for(int y:g[x])if(!dfn[y]){
        tarjan(y);
        low[x]=min(low[x],low[y]);
    }else if(inst[y]){
        low[x]=min(low[x],dfn[y]);
    }
    if(dfn[x]==low[x]){
        iscc[x]=++scc;
        snf[scc]=nf[x];
        int y;
        while((y=st.top())!=x){
            st.pop();
            inst[y]=0;
            iscc[y]=scc;
            snf[scc]=1;
        }
        st.pop();
        inst[x]=0;
    }
}

vector<int> ng[400005];

void topo(int x){
    vis[x]=1;
    for(int y:ng[x])if(!vis[y]){
        topo(y);
    }
    tpv.emplace_back(x);
}

void mian(){
    cin>>n>>m;
    memset(dfn+1,0,n*4);
    memset(ind+1,0,n*4);
    memset(nf+1,0,n);
    memset(snf+1,0,n);
    memset(vis+1,0,n);
    dfc=scc=0;
    for(int i=1;i<=n;i++)g[i].clear(),ng[i].clear();
    tpv.clear();
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(a!=b)g[a].emplace_back(b);
        else nf[a]=1;
    }
    tarjan(1);
    for(int x=1;x<=n;x++)if(dfn[x]){
        for(int y:g[x]){
            if(iscc[x]!=iscc[y]){
                ng[iscc[x]].emplace_back(iscc[y]);
            }
        }
    }
    topo(iscc[1]);
    reverse(tpv.begin(),tpv.end());
    for(int x:tpv){
        for(int y:ng[x]){
            snf[y]|=snf[x];
            if(ind[x]==2)ind[y]=2;
            else ind[y]=min(2,ind[y]+1);
        }
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i])cout<<"0 ";
        else if(snf[iscc[i]])cout<<"-1 ";
        else if(ind[iscc[i]]>1)cout<<"2 ";
        else cout<<"1 ";
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}