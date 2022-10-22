/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=300000,M=8;
int n,m;
int a[N+1][M];
int hav[1<<M],dp[1<<M];
pair<int,int> chk(int lim){
	memset(hav,0,sizeof(hav));memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		int msk=0;
		for(int j=0;j<m;j++)if(a[i][j]>=lim)msk|=1<<j;
		hav[msk]=i;
	}
	for(int i=(1<<m)-1;~i;i--){
		dp[i]=hav[i];
		for(int j=0;j<m;j++)if(!(i&1<<j))
			dp[i|1<<j]?dp[i]=dp[i|1<<j]:0;
	}
	for(int i=0;i<1<<m;i++)if(dp[i]&&dp[(1<<m)-1^i])return mp(dp[i],dp[(1<<m)-1^i]);
	return mp(0,0);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)scanf("%d",a[i]+j);
	int ans=-1;pair<int,int> cho;
	for(int i=30;~i;i--){
		pair<int,int> c=chk(ans+(1<<i));
		if(c.X)ans+=1<<i,cho=c;
//		printf("%d:(%d,%d)\n",ans,c.X,c.Y);
	}
	cout<<cho.X<<" "<<cho.Y;
	return 0;
}
/*1
6 5
5 0 3 1 2
1 8 9 1 3
1 2 3 4 5
9 1 0 3 7
2 3 0 6 3
6 4 1 7 0
*/