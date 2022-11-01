#include<bits/stdc++.h>
using namespace std;

int n,dfn[200005],low[200005],dfc,scc,iscc[200005];
bool inst[200005];
vector<int> g[200005];
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

vector<int> ng[200005];
int sa[100005],sb[100005],fa[200005],fb[200005];
bool vis[200005];

void dfs(int x){
    vis[x]=1;
    for(int y:ng[x]){
        if(!vis[y])dfs(y);
        fa[x]=max(fa[x],fa[y]);
        fb[x]=max(fb[x],fb[y]);
    }
}

void mian(){
    memset(dfn+1,0,n<<3);
    memset(fa+1,0,n<<3);
    memset(fb+1,0,n<<3);
    memset(vis+1,0,n<<1);
    for(int i=1;i<=n*2;i++)g[i].clear();
    for(int i=1;i<=scc;i++)ng[i].clear();
    dfc=scc=0;
    cin>>n;
    for(int i=2;i<=n;i++){
        g[i].emplace_back(i-1);
        g[i+n].emplace_back(i+n-1);
    }
    map<int,int> ma,mb;
    for(int i=1;i<=n;i++){
        cin>>sa[i];
        ma[sa[i]]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>sb[i];
        mb[sb[i]]=0;
    }
    {
        int c=0;
        for(auto &[k,v]:ma)v=++c;
        c=0;
        for(auto &[k,v]:mb)v=++c;
    }
    for(int i=1;i<=n;i++){
        sa[i]=ma[sa[i]];
        sb[i]=mb[sb[i]];
        g[sa[i]].emplace_back(sb[i]+n);
        g[sb[i]+n].emplace_back(sa[i]);
    }
    for(int i=1;i<=n*2;i++)if(!dfn[i])tarjan(i);
    for(int x=1;x<=n*2;x++){
        for(int y:g[x]){
            if(iscc[x]!=iscc[y]){
                ng[iscc[x]].emplace_back(iscc[y]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        fa[iscc[sa[i]]]=max(fa[iscc[sa[i]]],sa[i]);
        fb[iscc[sa[i]]]=max(fb[iscc[sa[i]]],sb[i]);
        fa[iscc[sb[i]+n]]=max(fa[iscc[sb[i]+n]],sa[i]);
        fb[iscc[sb[i]+n]]=max(fb[iscc[sb[i]+n]],sb[i]);
    }
    for(int i=1;i<=n*2;i++)if(!vis[i])dfs(i);
    for(int i=1;i<=n;i++)cout<<(max(fa[iscc[sa[i]]],fb[iscc[sb[i]+n]])==n);
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