#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){for(auto t:y)t<x?x=t:0;}
template<class T> inline void dmax(T& x,vector<T> y){for(auto t:y)t>x?x=t:0;}
/*
const int N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1,int mod=MOD){
	for(;n;n>>=1,x=1ll*x*x%mod)
		n&1?ret=1ll*ret*x%mod:0;
	return ret;
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int inv[N],fac[N],ifac[N];
struct IniterFacInv{
	IniterFacInv(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer_comb;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
inline int rcomb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*ifac[n]*fac[m]%MOD*fac[n-m]%MOD;
}
*/
const int MOD=998244353,N=5+4e5;
int pw[N];
struct K{ int cnt,ex; };
inline bool operator<(K x,K y){
	if(x.cnt>20||y.cnt>20){
		if(x.cnt!=y.cnt) return x.cnt<y.cnt;
		return x.ex<y.ex;
	}
	return ((1ll<<x.cnt)+x.ex)<((1ll<<y.cnt)+y.ex);
}
inline bool operator>(K x,K y){ return y<x; }
inline bool operator!=(K x,K y){ return x.cnt!=y.cnt||x.ex!=y.ex; }
inline K operator+(K x,K y){ return (K){x.cnt+y.cnt,x.ex+y.ex}; }
vector<int> e[2][N];
priority_queue<pair<K,int>,vector<pair<K,int> >,greater<pair<K,int> > > q;
void dij1(K dis[],int n,int t){
	for(int i=1;i<=n;++i) q.push(make_pair(dis[i],i));
	while(!q.empty()){
		int x=q.top().second; 
		if(q.top().first!=dis[x]){
			q.pop();
			continue;
		}
		q.pop();
		for(auto y:e[t][x]){
			if(dis[x]+(K){0,1}<dis[y]){
				dis[y]=dis[x]+(K){0,1};
				q.push(make_pair(dis[y],y));
			}
		}
	}
}
void dij2(K dis[],int n){
	for(int i=n+1;i<=n+n;++i) dis[i]=(K){(int)1e9,0};
	for(int i=1;i<=n+n;++i) q.push(make_pair(dis[i],i));
	while(!q.empty()){
		int x=q.top().second; 
		if(q.top().first!=dis[x]){
			q.pop();
			continue;
		}
		q.pop();
		if(x<=n){
			for(auto y:e[0][x]){
				if(dis[x]+(K){0,1}<dis[y]){
					dis[y]=dis[x]+(K){0,1};
					q.push(make_pair(dis[y],y));
				}
			}
			for(auto y:e[1][x]){
				if(dis[x]+(K){1,1}<dis[y+n]){
					dis[y+n]=dis[x]+(K){1,1};
					q.push(make_pair(dis[y+n],y+n));
				}
			}
		}else{
			for(auto y:e[1][x-n]){
				if(dis[x]+(K){0,1}<dis[y+n]){
					dis[y+n]=dis[x]+(K){0,1};
					q.push(make_pair(dis[y+n],y+n));
				}
			}
			for(auto y:e[0][x-n]){
				if(dis[x]+(K){1,1}<dis[y]){
					dis[y]=dis[x]+(K){1,1};
					q.push(make_pair(dis[y],y));
				}
			}
		}
	}
}
K dis[23][N];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int u,v; scanf("%d%d",&u,&v);
		e[0][u].push_back(v);
		e[1][v].push_back(u);
	}
	for(int i=0;i<=20;++i)
		for(int j=1;j<=n;++j)
			dis[i][j]=(K){(int)1e9,0};
	dis[0][1]=(K){0,0};
	for(int t=0;t<20;++t){
		dij1(dis[t],n,t&1);
		for(int x=1;x<=n;++x)
			for(auto y:e[~t&1][x]){
				if(dis[t][x]+(K){1,1}<dis[t+1][y])
					dis[t+1][y]=dis[t][x]+(K){1,1};
			}
	}
	dij2(dis[20],n); pw[0]=1;
	for(int i=1;i<=n;++i) pw[i]=(pw[i-1]+pw[i-1])%MOD;
	K ans=(K){(int)1e9,0};
	for(int t=0;t<=20;++t)
		ans=min(ans,dis[t][n]);
	ans=min(ans,dis[20][n+n]);
	int ret=(0ll+pw[ans.cnt]+ans.ex+MOD-1)%MOD;
	printf("%d\n",ret);
	return 0;
}