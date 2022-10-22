#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=605;
template<class T> void chmin(T& x,T y){ y<x?void(x=y):void(); }
ll c[N][N],dis[N];
bool vis[N];
int n;
inline int mo_n(int x){ return x>=n?x-n:x; }
void update(ll dis[]){
	ll mi=1e18;
	for(int y=0;y<n+n;++y){
		ll& k=dis[mo_n(y)];
		mi+y<=k?k=mi+y:mi=k-y;
	}
}
int main(){
	int m; scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			c[i][j]=1e18;
	for(int i=0;i<m;++i){
		int a,b,w; scanf("%d%d%d",&a,&b,&w);
		c[a][b]=w;
	}	
	for(int x=0;x<n;++x) update(c[x]);
	for(int x=0;x<n;++x){
		for(int y=0;y<n;++y) dis[y]=c[x][y],vis[y]=0;
		for(int i=0;i<n;++i){
			int z=-1;
			for(int j=0;j<n;++j)
				if(!vis[j]&&(z==-1||dis[j]<dis[z])) z=j;
			vis[z]=1;
			for(int y=0;y<n;++y)
				chmin(dis[y],dis[z]+c[z][mo_n(y+n-dis[z]%n)]);
			update(dis);
		}
		for(int y=0;y<n;++y)
			printf("%lld ",x==y?0:dis[y]);
		puts("");
	}
	return 0;
}