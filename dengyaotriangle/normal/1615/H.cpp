#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

template<typename ft>struct flowg{
    struct edg{int v,b;ft w;edg(){}edg(int v,ft w,int b):v(v),w(w),b(b){}};
    vector<vector<edg> >adj;
    vector<int> dep,cur;
    int n,s,t;
    flowg(int _n,int s,int t):s(s),t(t){n=_n;adj.clear();adj.resize(n+1);dep.resize(n+1);cur.resize(n+1);}
    inline void adde(int u,int v,ft w){
        int ui=adj[u].size(),vi=adj[v].size();
        adj[u].push_back(edg(v,w,vi));
        adj[v].push_back(edg(u,0,ui));
    }
    inline bool bfs(){
        fill(dep.begin(),dep.end(),-1);
        fill(cur.begin(),cur.end(),0);
        queue<int> q;
        q.push(s);
        dep[s]=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<adj[u].size();i++){
                edg e=adj[u][i];
                if(dep[e.v]==-1&&e.w!=0){
                    dep[e.v]=dep[u]+1;
                    q.push(e.v);
                }
            }
        }
        return dep[t]!=-1;
    }
    inline ft dfs(int u,ft lim){
        if(u==t||lim==0)return lim;
        ft tot=0;
        for(int&i=cur[u];i<adj[u].size();i++){
            edg e=adj[u][i];
            if(dep[e.v]==dep[u]+1&&e.w!=0){
                ft c=dfs(e.v,min(lim,e.w));
                tot+=c;lim-=c;
                adj[u][i].w-=c;
                adj[e.v][e.b].w+=c;
                if(lim==0)break;
            }
        }
        return tot;
    }
    inline ft maxflow(ft mx){
        ft ans=0;
        while(bfs())ans+=dfs(s,mx);
        return ans;
    }
};
const int maxn=1005;
const int maxm=64;

int n,m;
int v[maxn];
vector<int> adj[maxn];//u <= v
int pt[maxn];
int rv[maxn];
long long ans=0;
int res[maxn];

int lc[maxn],rc[maxn];
void solve(int l,int r,int cl,int cr){
    if(cl>cr)return;
    if(l==r){
        for(int j=cl;j<=cr;j++)res[pt[j]]=l;
        return;
    }
    int ml=(l+r)>>1,mr=ml+1;
    flowg<long long> fl(cr-cl+3,cr-cl+2,cr-cl+3);
    for(int j=cl;j<=cr;j++){
        int u=pt[j];
        rv[u]=j-cl+1;
        long long w=(abs(v[u]-ml)-abs(v[u]-mr));
        if(w>0)fl.adde(fl.s,j-cl+1,w);
        else fl.adde(j-cl+1,fl.t,-w);
    }
    for(int j=cl;j<=cr;j++){
        int u=pt[j];
        for(int k=0;k<(int)adj[u].size();k++){
            int v=rv[adj[u][k]];
            if(v){
                fl.adde(j-cl+1,v,LLONG_MAX);
            }
        }
    }
    fl.maxflow(LLONG_MAX);
    int ls=0,rs=0;
    for(int j=cl;j<=cr;j++){
        int u=pt[j];
        rv[u]=0;
        if(fl.dep[j-cl+1]!=-1){
            rc[++rs]=u;
        }else lc[++ls]=u;
    }
    for(int k=1;k<=ls;k++)pt[cl+k-1]=lc[k];
    for(int k=1;k<=rs;k++)pt[cl+ls+k-1]=rc[k];
    solve(l,ml,cl,cl+ls-1);
    solve(mr,r,cl+ls,cr);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++)pt[i]=i;
    solve(*min_element(v+1,v+1+n),*max_element(v+1,v+1+n),1,n);
    for(int i=1;i<=n;i++)cout<<res[i]<<' ';
    return 0;
}