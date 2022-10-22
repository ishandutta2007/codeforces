#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9+7;
#define fi first
#define se second
int n,a[4404],b[4404];
pair<int,int>p[4404];
pair<ll,int>f[4404];
bool cmp(pair<int,int>A,pair<int,int>B){
	if(A.fi!=B.fi)return A.fi<B.fi;
	int t0=A.se<=n,t1=B.se<=n;
	if(t0!=t1)return t0<t1;
	return a[A.se]>a[B.se];
}
bool check(int t){
	if(t<0)return 0;
	for(int i=1;i<=n+n;i++)p[i]={b[i],i};
	sort(p+1,p+n+n+1,cmp);ll cur=0;
	for(int i=1;i<=n+n;i++){
		int x=p[i].se;
		cur=max(cur,(ll)t*a[x]+b[x]);
		if(x>n)f[i]={(ll)t*a[x]+b[x],-x};
		else f[i]={cur,x};
	}
	sort(f+1,f+n+n+1);
	for(int i=n+n,s=0;i;i--){
		s+=f[i].se>0?1:-1;
		if(s<0)return 0;
	}
	return 1;
}
struct edge{
	int to,cap,rev,cost;
	edge(int to,int cap,int rev,int cost):to(to),cap(cap),rev(rev),cost(cost){}
};
vector<edge>g[11004];
int S,T;
void addedge(int u,int v,int w,int c){
	g[u].push_back(edge(v,w,g[v].size(),c));
	g[v].push_back(edge(u,0,g[u].size()-1,-c));
}
void initflow(int t){
	S=n*5+1,T=n*5+2;
	for(int i=1;i<n+n;i++)addedge(i+1,i,inf,0),addedge(n+n+i+1,n+n+i,inf,0);
	for(int i=1;i<=n;i++)addedge(n+n+n+n+i,T,1,0);
	for(int i=1;i<=n+n;i++){
		int x=p[i].se;
		if(x<=n){
			addedge(S,i,1,0);
			for(int j=1;j<=n+n;j++)if(x==f[j].se)addedge(i,n+n+j,1,1);
			ll z=(ll)t*a[x]+b[x];
			int pos=upper_bound(f+1,f+n+n+1,make_pair(z,n+n+1))-f-1;
			if(pos)addedge(i,n+n+pos,1,0);
		}else addedge(i,n+n+n+x,1,0);
		if(f[i].se<0)addedge(n+n+i,n+n+n-f[i].se,1,0);
	}
}
int h[11004],d[11004],pv[11004],pe[11004];
int tot,hd[2204],nx[22004],vl[22004];
void ins(int x,int i){
	int id=++tot;
	nx[id]=hd[x],hd[x]=id,vl[id]=i;
}
int del(int x){
	int ret=vl[hd[x]];
	hd[x]=nx[hd[x]];
	return ret;
}
void calcflow(){
	int res=0;
	for(;;){
		memset(d,0x3f,sizeof(d));
		tot=0;memset(hd,0,sizeof(hd));
		d[S]=0,ins(0,S);
		for(int t=0;t<=2200;t++){
			while(hd[t]){
				int x=del(t);
				if(d[x]<t)continue;
				for(int i=0;i<g[x].size();i++){
					edge e=g[x][i];
					int w=t+e.cost+h[x]-h[e.to];
					if(e.cap>0&&w<d[e.to]){
						d[e.to]=w,ins(w,e.to);
						pv[e.to]=x,pe[e.to]=i;
					}
				}
			}
		}
		if(d[T]>inf){printf("%d",n+res);return;}
		for(int i=1;i<=T;i++)h[i]=min(h[i]+d[i],inf);
		res+=h[T];int cur=T;
		while(cur!=S){
			edge &e=g[pv[cur]][pe[cur]];
			e.cap--,g[cur][e.rev].cap++,cur=pv[cur];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n+n;i++)scanf("%d%d",&a[i],&b[i]);
	int l=-1,r=inf;
	while(r>l+1){
		int md=(l+r)>>1;
		if(check(md))r=md;else l=md;
	}
	if(!check(r)){puts("-1");return 0;}
	initflow(r),printf("%d ",r),calcflow();
}