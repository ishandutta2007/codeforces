#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
inline int read(){
	char ch=getchar();int x=0,op=0;
	while(!isdigit(ch))op|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return op?-x:x;
}
 
const int N=200005;
struct P{
	ll x,y;
	P(ll _x=0,ll _y=0){x=_x,y=_y;}
	friend P operator + (const P &a,const P &b){
		return P(a.x+b.x,a.y+b.y);
	}
	friend P operator - (const P &a,const P &b){
		return P(a.x-b.x,a.y-b.y);
	}
	friend ll operator * (const P &a,const P &b){
		return (ll)a.x*b.y-(ll)a.y*b.x;
	}
	inline ll f(const int &k){return k*x+y;}
}emp;
vector<pair<int,P>> g[N],e[N];
vector<P> L,R,all;
int n,m;
 
void rebuild(int u,int fa){
	vector<pair<int,P>> son;
	for(auto v:g[u])
		if(v.fi!=fa){
			rebuild(v.fi,u);
			son.pb(v);
		}
	int last=u,now;
	for(auto v:son){
		now=++n;
		e[last].pb(mp(now,emp));
		e[now].pb(mp(last,emp));
		e[now].pb(mp(v.fi,v.se));
		e[v.fi].pb(mp(now,v.se));
		last=now;
	}
}
 
void convex(vector<P> &p){
	vector<P> res;
	sort(p.begin(),p.end(),[&](const P &a,const P &b){
		return a.x<b.x||a.x==b.x&&a.y>b.y;
	});
	int m=0;
	REP(i,p.size()){
		if(i&&p[i].x==p[i-1].x)continue;
		while(m&&res[m-1].y<=p[i].y)
			res.pop_back(),m--;
		while(m>=2&&(p[i]-res[m-2])*(res[m-1]-res[m-2])<=0)
			res.pop_back(),m--;
		res.pb(p[i]),m++;
	}
	p=res;
}
void merge(){
	all.pb(L[0]+R[0]);
	for(int i=0,j=0;i+1<L.size()||j+1<R.size();)
		if(j+1==R.size()||(i+1<L.size()&&(L[i+1]-L[i])
										*(R[j+1]-R[j])<0))
			all.pb(L[++i]+R[j]);
		else
			all.pb(L[i]+R[++j]);
}
 
P bas;
int sz[N],vis[N],rt,prt;
void find(int u,int fa,int s,P las){
	sz[u]=1;
	for(auto v:e[u])
		if(v.fi!=fa&&!vis[v.fi]){
			find(v.fi,u,s,v.se);
			sz[u]+=sz[v.fi];
		}
	if(fa&&(!rt||max(sz[u],s-sz[u])<max(sz[rt],s-sz[rt])))
		rt=u,prt=fa,bas=las;
}
void get(int u,int fa,vector<P> &p,P now){
	p.pb(now);
	for(auto v:e[u])
		if(v.fi!=fa&&!vis[v.fi])
			get(v.fi,u,p,now+v.se);
}
void divide(int x,int s){
	if(s==1)return;
	rt=0,find(x,0,s,emp);
	int u=rt,v=prt;
	int su=sz[u],sv=s-su;
	L.clear(),get(u,v,L,emp);
	R.clear(),get(v,u,R,bas);
	convex(L),convex(R),merge();
	vis[v]=1,divide(u,su),vis[v]=0;
	vis[u]=1,divide(v,sv),vis[v]=0;
}
 
int main(){
	n=read(),m=read();
	if(n==1){
		while(m--)puts("0");
		return 0;
	}
	rep(i,1,n-1){
		int u=read(),v=read();
		int x=read(),y=read();
		g[u].pb(mp(v,P(x,y)));
		g[v].pb(mp(u,P(x,y)));
	}
	rebuild(1,0);
	divide(1,n);
	convex(all);
	for(int i=0,j=0;i<m;i++){
		while(j+1<all.size()&&all[j+1].f(i)>all[j].f(i))j++;
		printf("%lld%c",all[j].f(i)," \n"[i==m-1]);
	}
	return 0;
}