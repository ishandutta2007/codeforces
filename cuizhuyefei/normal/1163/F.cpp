#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef pair<ll,int> Pli;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2e5+11;
int n,m,q,A[N],B[N],C[N],lo[N],ri[N],pre[N],bh[N];ll dis1[N],dis2[N];
vector<pair<int,Pii> >e[N];
void dij(int s, int tp, ll *dis){
	priority_queue<Pli,vector<Pli>,greater<Pli> >heap;
	rep(i,1,n)dis[i]=1e18,pre[i]=0;dis[s]=0;heap.push(mp(0,s));
	while(!heap.empty()){
		int u=heap.top().se;ll d=heap.top().fi;heap.pop();
		if(d!=dis[u])continue;
		for(auto v:e[u])if(dis[v.fi]>dis[u]+v.se.fi){
			dis[v.fi]=dis[u]+v.se.fi;pre[v.fi]=v.se.se;
			if(tp==1)lo[v.fi]=max(lo[u],bh[v.se.se]);
			if(tp==2)ri[v.fi]=min(ri[u],bh[v.se.se]?bh[v.se.se]:n);
			heap.push(mp(dis[v.fi],v.fi));
		}
	}
}
ll a[N][18];int Log[N];Vi d;
void upd(int u, int v, int w){
	//lo[u]+1..v
	int l=lo[u]+1,r=ri[v]-1;
	if(l>r)return;
//	if(q>=84){printf("%d %d %d %d %d\n",l,r,SZ(d),ri[u],lo[v]);exit(0);}
	int k=Log[r-l+1];
	umin(a[l][k],dis1[u]+dis2[v]+w);
	umin(a[r-(1<<k)+1][k],dis1[u]+dis2[v]+w);
}
bool cmp1(int x ,int y){return dis1[x]<dis1[y];}
bool cmp2(int x ,int y){return dis2[x]<dis2[y];}
int main() {
	read(n);read(m);read(q);
	rep(i,1,m){
		read(A[i]);read(B[i]);read(C[i]);
		e[A[i]].pb(mp(B[i],mp(C[i],i)));e[B[i]].pb(mp(A[i],mp(C[i],i)));
	}
	dij(1,0,dis1);for(int u=n;u;u=A[pre[u]]+B[pre[u]]-u){if(u==1)break;d.pb(pre[u]);}
	reverse(ALL(d));
	rep(i,0,SZ(d)-1)bh[d[i]]=i+1;
	assert(A[d[0]]==1||B[d[0]]==1);
	rep(i,0,n)lo[i]=0,ri[i]=SZ(d)+1;
	dij(1,1,dis1);
	
//	static int b[N];rep(i,1,n)b[i]=i;
//	sort(b+1,b+n+1,cmp1);
//	rep(j,2,n){
//		int u=b[j],v=A[pre[u]]+B[pre[u]]-u;
//	//	printf("%d %d %lld\n",u,v,dis1[u]);
//	//	assert(dis1[u]==dis1[v]+C[pre[u]]);
//		assert(lo[u]==max(lo[v],bh[pre[u]]));
//	}
//	
	dij(n,2,dis2);
//	
//	sort(b+1,b+n+1,cmp2);
//	rep(j,2,n){
//		int u=b[j],v=A[pre[u]]+B[pre[u]]-u;
//	//	printf("%d %d %lld\n",u,v,dis1[u]);
//	//	assert(dis2[u]==dis2[v]+C[pre[u]]);
//	//	assert(ri[u]==min(ri[v],bh[pre[u]]?bh[pre[u]]:n));
//	}
	
//	rep(i,0,SZ(d)-1)printf("qwq %d\n",d[i]);
 //   for (int i = 1; i <= n; i++)printf("%d:%d %d\n",i,lo[i],ri[i]);
	memset(a,0x3f,sizeof(a));
	rep(i,1,n){Log[i]=Log[i-1];if(i==(1<<Log[i]+1))Log[i]++;}
	rep(i,1,m)if(!bh[i]&&dis1[A[i]]<1e18&&dis2[A[i]]<1e18)upd(A[i],B[i],C[i]),upd(B[i],A[i],C[i]);
	per(j,17,1)rep(i,1,n)umin(a[i][j-1],a[i][j]),umin(a[i+(1<<j-1)][j-1],a[i][j]);
	assert(n>=SZ(d));
	rep(cas,1,q){
		int id,w;read(id);read(w);ll res;
	//	if(cas==84)assert(bh[id]&&dis1[n]+w-C[id]>=3544877538ll);
		if(!bh[id])res=min({dis1[n],dis1[A[id]]+dis2[B[id]]+w,dis1[B[id]]+dis2[A[id]]+w});
		else res=min(a[bh[id]][0],dis1[n]+w-C[id]);
		printf("%lld\n",res);
	}
	return 0;
}