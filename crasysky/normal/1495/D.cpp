#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=402,P=998244353;
int d[N][N],q[N],c[N]; vector<int> G[N];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,m){
		int u,v; scanf("%d%d",&u,&v);
		G[u].pb(v),G[v].pb(u);
	}
	rep(s,1,n){
		rep(i,1,n) d[s][i]=n+1;
		int l=1,r=1; d[s][s]=0,q[r]=s;
		while (l<=r){
			int u=q[l++];
			rep0(i,G[u].size()){
				int v=G[u][i];
				if (d[s][u]+1<d[s][v]) d[s][v]=d[s][u]+1,q[++r]=v;
			}
		}
	}
	rep(x,1,n){
		rep(y,1,n){
			memset(c,0,sizeof(c));
			rep(i,1,n) if (d[x][i]+d[y][i]==d[x][y]) ++c[d[x][i]];
			bool t=false; rep(i,0,d[x][y]) t=t||c[i]!=1;
			if (t){ printf("0 "); continue; }
			int ans=1;
			rep(u,1,n){
				if (d[x][u]+d[y][u]==d[x][y]) continue;
				int c=0;
				rep0(i,G[u].size()){
					int v=G[u][i];
					if (d[x][v]==d[x][u]-1&&d[y][v]==d[y][u]-1) ++c;
				}
				ans=(ll)ans*c%P;
			}
			printf("%d ",ans);
		}
		putchar('\n');
	}
	return 0;
}