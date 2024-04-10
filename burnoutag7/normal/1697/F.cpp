#include<bits/stdc++.h>
using namespace std;

int n,m,k,dfn[400005],low[400005],dfc,scc,iscc[400005],ans[20005];
bool inst[400005];
vector<int> g[400005];
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
        int y;
        while((y=st.top())!=x){
            st.pop();
            inst[y]=0;
            iscc[y]=scc;
        }
        st.pop();
        inst[x]=0;
    }
}

int id(int p,int v,bool t){
    return (p-1)*k+v+t*n*k;
}

void mian(){
    for(int i=1;i<=2*n*k;i++)g[i].clear();
    dfc=scc=0;
    fill(dfn+1,dfn+1+2*n*k,0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(j>1)g[id(i,j,1)].emplace_back(id(i,j-1,1));
            if(j<k)g[id(i,j,0)].emplace_back(id(i,j+1,0));
            if(i<n)g[id(i,j,1)].emplace_back(id(i+1,j,1));
            if(i>1)g[id(i,j,0)].emplace_back(id(i-1,j,0));
        }
        g[id(i,1,0)].emplace_back(id(i,1,1));
    }
    while(m--){
        int typ;
        cin>>typ;
        if(typ==1){
            int i,x;
            cin>>i>>x;
            if(x+1<=k){
                g[id(i,x+1,0)].emplace_back(id(i,x,0));
                g[id(i,x,1)].emplace_back(id(i,x+1,1));
            }else g[id(i,x,1)].emplace_back(id(i,x,0));
        }else if(typ==2){
            int i,j,x;
            cin>>i>>j>>x;
            for(int v=1;v<=x&&v<=k;v++)if(x-v+1<=k){
                g[id(i,v,1)].emplace_back(id(j,x-v+1,0));
                g[id(j,v,1)].emplace_back(id(i,x-v+1,0));
            }
        }else if(typ==3){
            int i,j,x;
            cin>>i>>j>>x;
            for(int v=1;v<=x&&v<=k;v++)if(x-v+1<=k){
                g[id(i,v,0)].emplace_back(id(j,x-v+1,1));
                g[id(j,v,0)].emplace_back(id(i,x-v+1,1));
            }else{
                g[id(i,v,0)].emplace_back(id(i,v,1));
                g[id(j,v,0)].emplace_back(id(j,v,1));
            }
        }
    }
    for(int i=1;i<=2*n*k;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=n;i++){
        ans[i]=0;
        for(int j=1;j<=k;j++){
            if(iscc[id(i,j,1)]==iscc[id(i,j,0)]){
                cout<<"-1\n";
                return;
            }
            ans[i]+=iscc[id(i,j,1)]<iscc[id(i,j,0)];
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
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