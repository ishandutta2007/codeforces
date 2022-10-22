#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=19;
int n,m;
vector<int> nei[N+1];
int dp[1<<N][N+1];
signed main(){
	scanf("%lld%lld",&n,&m);
	while(m--){
		int x,y;scanf("%lld%lld",&x,&y);
		nei[x].pb(y);nei[y].pb(x);
	}
	for(int i=1;i<=n;i++)dp[1<<i-1][i]=1;
	for(int i=0;i<1<<n;i++){
		int sm;
		for(int j=n;j;j--)if(i&1<<j-1)sm=j;
		for(int j=1;j<=n;j++)if(i&1<<j-1&&j!=sm)
			for(int k=0;k<nei[j].size();k++)dp[i][j]+=dp[i^1<<j-1][nei[j][k]];
	}
//	for(int i=0;i<1<<n;i++)for(int j=1;j<=n;j++)if(i&1<<j-1){
//		printf("dp[");for(int k=1;k<=n;k++)cout<<!!(i&1<<k-1);
//		printf("][%d]=%d\n",j,dp[i][j]);
//	}
	int ans=0;
	for(int i=0;i<1<<n;i++)if(__builtin_popcount(i)>2){
		int sm;
		for(int j=n;j;j--)if(i&1<<j-1)sm=j;
		for(int j=0;j<nei[sm].size();j++)ans+=dp[i][nei[sm][j]];
	}
	printf("%lld",ans>>1);
	return 0;
}
/*1
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/