#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define sit set<pr>::iterator
#define ll long long
#define pb push_back
#define db long double
#define pr pair<int,db>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+6; const db INF=1e30;
struct data{ int x,y,t; }a[N]; vector<pr> G[N];
int dep[N],len[N],fa[N],sz[N]; db b[N],d[N],sd[N],d2[N],d3[N];
bool cmp(data a,data b){
	if (a.x!=b.x) return a.x==0||b.x&&a.x<b.x;
	if (a.y!=b.y) return a.y==0||b.y&&a.y<b.y;
	return a.t<b.t;
}
db dis(int x,int y){ return sqrt((db)x*x+(db)y*y); }
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
int read(){ int x; scanf("%d",&x); return x; }
int main(){
	int n=read(),k=read();
	rep(i,1,n){
		int x=read(),y=read(),g=gcd(abs(x),abs(y));
		if (g==0) a[i]=(data){0,0,0};
		else a[i]=(data){x/g,y/g,g};
	}
	sort(a+1,a+1+n,cmp); 
	rep(i,1,n) b[i]=dis(a[i].x,a[i].y)*a[i].t;
	dep[1]=1;
	rep(i,2,n){
		if (a[i].x==a[i-1].x&&a[i].y==a[i-1].y)
			G[i-1].pb(mp(i,b[i]-b[i-1])),fa[i]=i-1,dep[i]=dep[i-1]+1;
		else G[1].pb(mp(i,b[i])),fa[i]=1,dep[i]=2;
		d[1]+=dis(a[i].x,a[i].y)*a[i].t;
	}
	per(i,n,1) sz[fa[i]]+=++sz[i],++len[i],len[fa[i]]=max(len[fa[i]],len[i]);
	rep(u,1,n){
		d2[u]+=b[u];
		rep0(i,G[u].size()){
			int v=G[u][i].fi;
			d[v]=d[u]+(n-2*sz[v])*G[u][i].se,d2[v]+=d2[u];
		}
	}
	db sum=0; rep(i,1,n) sum+=d[i]; sum/=2;
	rep(u,1,n){
		d3[u]+=dep[u]*b[u]-d2[u];
		rep0(i,G[u].size()) d3[G[u][i].fi]+=d3[u];
	}
	rep(i,1,n) sd[i]=sd[i-1]+d[i];
	rep(i,1,n){
		if (dep[i]>n-k) d[i]=INF;
		else d[i]-=dep[i]*b[i]-(d2[i]+d2[fa[i]])+(n-k-dep[i])*b[i];
	}
	rep(i,1,n) d[i]=b[i]*(k-2*len[i]+1);//b[i]*(k-len[i])-b[i]*(len[i]-1)
	sort(d+1,d+1+n),reverse(d+1,d+1+n);
	db v=0; rep(i,1,k) v+=d[i]; db s=INF;
	rep(i,n-k,n){
		int j=i-(n-k),t=fa[j+1];
		if (a[i].x==a[j+1].x&&a[i].y==a[j+1].y)
			s=min(s,sd[i]-sd[j]-(d3[i]-d3[t]-(dep[t]*(d2[i]-d2[t])-(dep[i]-dep[t])*d2[t])));
	}
	printf("%.8Lf",max(v,sum-s));
	return 0; 
}
/*
14 10
0 19
0 -17
0 17
0 15
-13 0
6 0
0 13
19 0
-19 0
0 0
-17 0
-6 0
0 -15
0 -13

1214
*/