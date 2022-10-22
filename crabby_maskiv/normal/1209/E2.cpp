#include<bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
const int N=13;
const int M=2005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int dp[N][1<<N];
int f[1<<N];
int a[N][M],c[N][N];
pair<int,int> p[M];
int cost,cnt;
int main(){
	int i,j,k;
	int T;scanf("%d",&T);
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)	
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		for(i=1;i<=m;i++){
			p[i].first=0;
			for(j=1;j<=n;j++)
				p[i].first=max(p[i].first,a[j][i]);
			p[i].second=i;
		}
		sort(p+1,p+m+1);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				c[i][j]=a[j][p[m-i+1].second];
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++){
			for(int p1=1;p1<=n;p1++){
				for(j=0;j<(1<<n);j++) f[j]=dp[i-1][j];
				for(j=0;j<(1<<n);j++){
					for(int p2=0;p2<n;p2++){
						if(!((1<<p2)&j)) continue;
						f[j]=max(f[j],f[j-(1<<p2)]+c[i][(p1+p2-1)%n+1]);
					}
				}
				for(j=0;j<(1<<n);j++) dp[i][j]=max(dp[i][j],f[j]);
			}
		}
		printf("%d\n",dp[n][(1<<n)-1]);
	}
	return 0;
}