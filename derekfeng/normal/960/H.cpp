#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
#define fi first
#define se second
struct node{
	ll S1,S2;
	int lzy;
	bool to0;
	node(){
		S1=S2=lzy=to0=0;
	}
}d[131100];
void push(int id,int L,int x,bool y){
	if(y){
		d[id].S1=d[id].S2=d[id].lzy=0;
		d[id].to0=1;
	}
	d[id].S2+=2ll*d[id].S1*x+(ll)L*x*x;
	d[id].S1+=(ll)L*x;
	d[id].lzy+=x;
}
void upd(int l,int r,int id,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b){
		push(id,r-l+1,x,0);
		return;
	}
	int mid=(l+r)>>1;
	if(d[id].lzy!=0||d[id].to0){
		push(id<<1,mid-l+1,d[id].lzy,d[id].to0);
		push(id<<1|1,r-mid,d[id].lzy,d[id].to0);
		d[id].lzy=0,d[id].to0=0;
	}
	upd(l,mid,id<<1,a,b,x),upd(mid+1,r,id<<1|1,a,b,x);
	d[id].S1=d[id<<1].S1+d[id<<1|1].S1,d[id].S2=d[id<<1].S2+d[id<<1|1].S2;
}
int n,cnt,fa[50004],nxt[50004],dfn[50004],h[50004],siz[50004];
vector<int>g[50004];
void dfs(int x){
	siz[x]=1;
	for(auto to:g[x]){
		dfs(to);
		siz[x]+=siz[to];
		if(siz[to]>siz[h[x]])h[x]=to;
	}
}
void dfs1(int x,int H){
	nxt[x]=H,dfn[x]=++cnt;
	if(h[x])dfs1(h[x],H);
	for(auto to:g[x])if(to!=h[x])dfs1(to,to);
}
void fupd(int u,int x){
	while(1){
		int F=nxt[u];
		upd(1,n,1,dfn[F],dfn[u],x);
		if(F==1)break;
		u=fa[F];
	}
}
int m,q,C;
ll ans[50004];
vector<pii>qry[50004];
int f[50004],c[50004];
int ask[50004];
void solve(vector<pii>&Q,int B){
	push(1,n,0,1);
	for(auto x:Q){
		if(x.fi<0){
			ans[-x.fi]=(ll)n*C*C-2ll*B*C*d[1].S1+(ll)B*B*d[1].S2;
			continue;
		}
		fupd(x.fi,x.se);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&q,&C);
	for(int i=1;i<=n;i++)scanf("%d",&f[i]),qry[f[i]].push_back({i,1});
	for(int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		g[fa[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)scanf("%d",&c[i]);
	for(int i=1;i<=q;i++){
		scanf("%d",&ask[i]);
		int x,c;
		if(ask[i]==1){
			scanf("%d%d",&x,&c);
			qry[f[x]].push_back({x,-1});
			qry[c].push_back({x,1});
			f[x]=c;
		}else{
			scanf("%d",&c);
			qry[c].push_back({-i,0});
		}
	}
	dfs(1),dfs1(1,1);
	for(int i=1;i<=m;i++)solve(qry[i],c[i]);
	for(int i=1;i<=q;i++)if(ask[i]==2)printf("%.10lf\n",(db)ans[i]/(db)n);
}