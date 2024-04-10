#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1003,P=998244353,inv2=(P+1)/2,T=500;
int add(int x,int y){ x+=y; return x>=P?x-P:x; }
int dp[N][N]; vector<int> G[N];
void dfs(int u,int f,int r){
	rep0(i,G[u].size()){
		int v=G[u][i]; if (v==f) continue;
		dfs(v,u,r);
	}
	static int s[N],mx[N][2],mn[N][2];
	rep(j,0,r){
		mx[j][0]=j!=0,mx[j][1]=j==0;
		mn[j][0]=j!=0,mn[j][1]=j==0;
	}
	dp[u][-(r+1)+T]=1;
	rep0(i,G[u].size()){
		int v=G[u][i]; if (v==f) continue;
		s[-r-1+T]=0;
		rep(j,-r,r) s[j+T]=add(s[j-1+T],dp[v][j-1+T]);
		rep(j,0,r){//max+i>=0 [-mx,mx-1]
			int x[2]; x[0]=x[1]=0;
			rep(t,0,1){
				x[t]=(x[t]+(ll)mx[j][t]*add(s[j-1+T],P-s[-j-1+T]))%P;
				x[1]=(x[1]+(ll)mx[j][t]*dp[v][j-1+T])%P;
			}
			mx[j][0]=x[0],mx[j][1]=x[1];
		}
		rep(j,0,r){//min+i<0 [min+1,-min-1]
			int x[2]; x[0]=x[1]=0;
			rep(t,0,1){
				if (j) x[t]=(x[t]+(ll)mn[j][t]*add(s[j-1+T],P-s[-j+T]))%P;
				x[1]=(x[1]+(ll)mn[j][t]*dp[v][-j-1+T])%P;
			}
			mn[j][0]=x[0],mn[j][1]=x[1];
		}
		dp[u][-(r+1)+T]=(ll)dp[u][-(r+1)+T]*s[r+T]%P;
	}
	rep(j,0,r) dp[u][-j+T]=mn[j][1],dp[u][j+T]=mx[j][1];
}
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n-1){
		int u,v; scanf("%d%d",&u,&v);
		G[u].pb(v),G[v].pb(u);
	}
	int ans=0,pw=1; rep(i,1,n) pw=2LL*pw%P;
	rep(i,0,n){
		dfs(1,0,i); ans=add(ans,pw);
		rep(j,-i-1,-1) ans=add(ans,P-dp[1][j+T]);
	}
	rep(i,1,n) ans=(ll)ans*inv2%P;
	printf("%d\n",add(ans,P-1));
	return 0;
}
/*
aaaaaa
*/