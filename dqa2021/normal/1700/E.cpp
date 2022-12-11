#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
using namespace std;

//#define DEBUG
#ifdef DEBUG
template<typename ...Args>
int debug(const Args &...args){
	return fprintf(stderr,args...);
}
#else
#define debug(...) void()
#endif

typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])

int n,m;
int p[400010],q[400010];
int S(int x,int y){
	return (x-1)*m+y;
}
void T(int &x,int &y,int h){
	x=(h-1)/m+1,y=(h-1)%m+1;
}
bool val(int x,int y){
	return min(x,y)>0&&x<=n&&y<=m;
}
int d[400010],D;
bool upd(int o,int i,int j){
	if (p[o]==1) return 0;
	D-=d[o];
	int mn=1e9,x,y;
	x=i-1,y=j;
	if (val(x,y)) mn=min(mn,p[S(x,y)]);
	x=i+1,y=j;
	if (val(x,y)) mn=min(mn,p[S(x,y)]);
	x=i,y=j-1;
	if (val(x,y)) mn=min(mn,p[S(x,y)]);
	x=i,y=j+1;
	if (val(x,y)) mn=min(mn,p[S(x,y)]);
	d[o]=mn>p[o];
	D+=d[o];
	
//	printf("upd %d %d %d: mn %d d %d\n",o,i,j,mn,d[o]);
	
	return d[o];
}

void t_swap(int u,int v){
	swap(p[u],p[v]);
	swap(q[p[u]],q[p[v]]);
	int ux,uy,vx,vy; T(ux,uy,u),T(vx,vy,v);
	upd(u,ux,uy);
	upd(v,vx,vy);
	int dx,dy;
	dx=0,dy=1;
	if (val(ux+dx,uy+dy)) upd(S(ux+dx,uy+dy),ux+dx,uy+dy);
	if (val(vx+dx,vy+dy)) upd(S(vx+dx,vy+dy),vx+dx,vy+dy);
	dx=0,dy=-1;
	if (val(ux+dx,uy+dy)) upd(S(ux+dx,uy+dy),ux+dx,uy+dy);
	if (val(vx+dx,vy+dy)) upd(S(vx+dx,vy+dy),vx+dx,vy+dy);
	dx=1,dy=0;
	if (val(ux+dx,uy+dy)) upd(S(ux+dx,uy+dy),ux+dx,uy+dy);
	if (val(vx+dx,vy+dy)) upd(S(vx+dx,vy+dy),vx+dx,vy+dy);
	dx=-1,dy=0;
	if (val(ux+dx,uy+dy)) upd(S(ux+dx,uy+dy),ux+dx,uy+dy);
	if (val(vx+dx,vy+dy)) upd(S(vx+dx,vy+dy),vx+dx,vy+dy);
}

bool chk(int u,int v){
	
//	printf("fcheck %d %d\n",u,v);
	
	if (u>=v) return 0;
	t_swap(u,v);
	int z=D==0;
	t_swap(u,v);
	
//	printf("  %svalid swap %d %d\n",z?"":"in",p[u],p[v]);
	
	return z;
}

void solve(){
	n=read(),m=read();
	rep(i,1,n) rep(j,1,m){
		int o=S(i,j),u=read();
		p[o]=u,q[u]=o;
	}
	vector<int> C;
	rep(i,1,n) rep(j,1,m){
		int o=S(i,j),u=p[o];
//		if (u==1) continue;
		if (upd(o,i,j)) C.pb(o);
	}
	
//	for (int x: C) printf("err %d\n",x);
	
	if (C.empty()) return puts("0"),void();
	if (C.size()>10) return puts("2"),void();
	int z=0;
	rep(_,1,n*m){
		int o=q[_],u,v; T(u,v,o);
		static int c[400010];
		int cnt=0;
		static int _dx[4]={0,0,1,-1},_dy[4]={1,-1,0,0};
		for (int oo: C){
			int uu,vv; T(uu,vv,oo);
			bool ok=oo==o;
			if (ok) continue;
			rep(e,0,3){
				int dx=_dx[e],dy=_dy[e];
				if (val(uu+dx,vv+dy)&&S(uu+dx,vv+dy)==o)
				{ok=1; break;}
			}
			if (ok) continue;
			++c[S(uu,vv)]; ++cnt;
			
//			printf("  visit %d -> %d\n",S(uu,vv),S(uu,vv));
			
			rep(e,0,3){
				int dx=_dx[e],dy=_dy[e];
				if (val(uu+dx,vv+dy))
					++c[S(uu+dx,vv+dy)];
//				printf("  visit %d -> %d\n",S(uu,vv),S(uu+dx,vv+dy));
			}
		}
//		printf("case %d: ",o);
//		rep(j,1,n*m) printf("%d ",c[j]);
//		puts("");
		if (!cnt){
			rep(oo,o+1,n*m) z+=chk(o,oo);
			continue;
		}
		
		
		for (int oo: C){
			int uu,vv; T(uu,vv,oo);
			bool ok=oo==o;
			if (ok) continue;
			rep(e,0,3){
				int dx=_dx[e],dy=_dy[e];
				if (val(uu+dx,vv+dy)&&S(uu+dx,vv+dy)==o)
				{ok=1; break;}
			}
			if (ok) continue;
			if (c[S(uu,vv)]==cnt) z+=chk(o,S(uu,vv));
			--c[S(uu,vv)];
//			printf("  visit %d -> %d\n",S(uu,vv),S(uu,vv));
			rep(e,0,3){
				int dx=_dx[e],dy=_dy[e];
				if (!val(uu+dx,vv+dy)) continue;
				if (c[S(uu+dx,vv+dy)]==cnt)
					z+=chk(o,S(uu+dx,vv+dy));
				--c[S(uu+dx,vv+dy)];
//				printf("  visit %d -> %d\n",S(uu,vv),S(uu+dx,vv+dy));
			}
		}
		
//		printf("case %d: ",o);
//		rep(j,1,n*m) printf("%d ",c[j]);
//		puts("");
		
	}
	if (z) printf("1 %d\n",z);
	else puts("2");
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}