#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int ls[3*N],rs[3*N];
int lft[3*N],rgt[3*N];
ll num[3*N];
int rt,P;
int build(int l,int r){
    int p=++P;
    lft[p]=l;rgt[p]=r;
    return p;
}
void update(int p){
    num[p]=num[ls[p]]+num[rs[p]];
    return;
}
void change(int p,int pos,ll x){
    if(lft[p]==pos&&rgt[p]==pos){
        num[p]+=x;
        return;
    }
    int mid=(lft[p]+rgt[p])>>1;
    if(pos<=mid&&!ls[p]) ls[p]=build(lft[p],mid);
    if(pos>mid&&!rs[p]) rs[p]=build(mid+1,rgt[p]);
    if(pos<=mid) change(ls[p],pos,x);
    else change(rs[p],pos,x);
    update(p);
    return;
}
ll query(int p,int pos){
    if(!p) return 0;
    if(lft[p]==rgt[p]) return num[p];
    int mid=(lft[p]+rgt[p])>>1;
    if(pos>mid) return query(rs[p],pos);
    else return query(ls[p],pos)+num[rs[p]];
}
vector<int> g[N];
vector<ll> dis[N],val[N];
ll ans[N];
ll dep[N];
void dfs(int cur,int last){
    for(int i=0;i<dis[cur].size();i++){
    	if(dep[cur]+dis[cur][i]>N) change(rt,N,val[cur][i]);
    	else change(rt,dep[cur]+dis[cur][i],val[cur][i]);
    }
    ans[cur]=query(rt,dep[cur]);
    for(auto v:g[cur]){
        if(v==last) continue;
        dep[v]=dep[cur]+1;
        dfs(v,cur);
    }
    for(int i=0;i<dis[cur].size();i++){
    	if(dep[cur]+dis[cur][i]>N) change(rt,N,-val[cur][i]);
    	else change(rt,dep[cur]+dis[cur][i],-val[cur][i]);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    int i,j;
    cin>>n;
    rt=build(0,N);
    for(i=1;i<n;i++){
    	int x,y;cin>>x>>y;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    cin>>m;
    for(i=1;i<=m;i++){
    	int x,y,z;cin>>x>>y>>z;
    	dis[x].push_back(y);
    	val[x].push_back(z);
    }
    dfs(1,0);
    for(i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}