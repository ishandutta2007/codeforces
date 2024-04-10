#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i) 
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db long double
using namespace std;
const int N=1e6+6; bool dp[35][35];
int main(){
	int q; scanf("%d",&q);
	while (q--){
		int u,v; scanf("%d%d",&u,&v);
		rep(i,0,30) rep(j,0,30) dp[i][j]=0;
		dp[0][0]=1;
		rep(i,0,29){
			int a=u>>i&1,b=v>>i&1;
			rep(j,0,i){
				int t=j+a-b;
				if (dp[i][j]&&t>=0)
					rep(k,(t+1)/2,t) dp[i+1][k]=true;
			}
		}
		puts(dp[30][0]?"YES":"NO");
	}
	return 0;
}