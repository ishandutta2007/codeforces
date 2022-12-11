#pragma GCC optimize(2,3,"Ofast")
#pragma GCC optimize("unroll-loops")

#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=(_##i);i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=(_##i);i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
const int INF=1e9;

int n,m,k;
int a[512][512],b[512][512];

int dis[2][512][512];

int work(int x,int y){
	int z=1e9;
	auto F=dis[0],G=dis[1];
	F[x][y]=0;
	const auto chk=[&](int &x,const int &w){
		if (w<x) x=w;
	};
	rep(_,0,k-1){
		const int t=k-_<<1;
		rep(u,x-_,x+_){
			const int d=_-abs(u-x);
			rep(v,y-d,y+d){
				if (u>n||u<1||v>m||v<1) continue;
				const int w=F[u][v]<<1; int e=INF;
//				printf("work %d %d dep %d dis %d %d = %d\n",x,y,_,u,v,F[u][v]);
				if (u>1) chk(e,b[u-1][v]);
				if (u<n) chk(e,b[u][v]);
				if (v>1) chk(e,a[u][v-1]);
				if (v<m) chk(e,a[u][v]);
				chk(z,w+e*t);
			}
		}
		if (_==k-1) break;
		swap(F,G);
		rep(u,x-_-1,x+_+1){
			const int d=1+_-abs(u-x);
			rep(v,y-d,y+d){
				if (u>n||u<1||v>m||v<1) continue;
				F[u][v]=INF;
			}
		}
		rep(u,x-_,x+_){
			const int d=_-abs(u-x);
			rep(v,y-d,y+d){
				if (u>n||u<1||v>m||v<1) continue;
				
				const int &w=G[u][v];
				if (u>1) chk(F[u-1][v],w+b[u-1][v]);
				if (u<n) chk(F[u+1][v],w+b[u][v]);
				if (v>1) chk(F[u][v-1],w+a[u][v-1]);
				if (v<m) chk(F[u][v+1],w+a[u][v]);
			}
		}
	}
	return z;
}

void solve(){
	n=read(),m=read(),k=read();
	if (k&1){
		rep(i,1,n) rep(j,1,m) printf("-1%c"," \n"[j==m]);
		return;
	}
	k>>=1;
	rep(i,1,n) rep(j,1,m-1) a[i][j]=read();
	rep(i,1,n-1) rep(j,1,m) b[i][j]=read();
	rep(i,1,n) rep(j,1,m) printf("%d%c",work(i,j)," \n"[j==m]);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}