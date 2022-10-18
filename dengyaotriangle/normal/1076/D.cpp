#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

struct ed{
    int v,w,i;
};
int n,m,e;
vector<ed> adj[maxn];
long long ans[maxn];
int bk[maxn],bkp[maxn];
vector<int> nxt[maxn];

ed mked(int v,int w,int i){
    ed nw;nw.v=v;nw.w=w;nw.i=i;
    return nw;
}
void dij(){
    priority_queue<tuple<long long,int,int,int>,vector<tuple<long long,int,int,int> >,greater<tuple<long long,int,int,int> > > q;
    q.push(make_tuple(0,1,0,0));
    memset(ans,0x3f,sizeof(ans));
    while(!q.empty()){
        tuple<long long,int,int,int> cur=q.top();q.pop();
        if(ans[get<1>(cur)]<=get<0>(cur))continue;
        ans[get<1>(cur)]=get<0>(cur);
        bk[get<1>(cur)]=get<2>(cur);
        bkp[get<1>(cur)]=get<3>(cur);
        for(int i=0;i<adj[get<1>(cur)].size();i++){
            int v=adj[get<1>(cur)][i].v;
            long long w=adj[get<1>(cur)][i].w;
            if(ans[v]==0x3f3f3f3f3f3f3f3fll){
                q.push(make_tuple(w+get<0>(cur),v,adj[get<1>(cur)][i].i,get<1>(cur)));
            }
        }
    }
}

int dfq[maxn],c1;

void dfs(int u){
    dfq[++c1]=u;
    for(int i=0;i<nxt[u].size();i++){
        int v=nxt[u][i];
        dfs(v);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m>>e;
    for(int i=1;i<=m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        adj[x].push_back(mked(y,w,i));
        adj[y].push_back(mked(x,w,i));
    }
    dij();
    for(int i=2;i<=n;i++){
        int p=bkp[i];
        nxt[p].push_back(i);
    }
    dfs(1);
    queue<int> q;
    cout<<min(e,n-1)<<'\n';
    for(int i=2;i<=min(e+1,n);i++){
        cout<<bk[dfq[i]]<<' ';
    }
    return 0;
}//orzlim