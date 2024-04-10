/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f3f3f3f3f;
const int W=3,N=100000,M=300000;
int n,m;
vector<int> a[W+1];
pair<int,pair<int,int> > dp[M+1];
signed main(){
	cin>>n>>m;
	while(n--){
		int x,y;
		cin>>x>>y;
		a[x].pb(y);
	}
	for(int i=1;i<=3;i++)if(a[i].size())sort(a[i].begin(),a[i].end()),reverse(a[i].begin(),a[i].end());
	dp[0]=mp(0ll,mp(-1ll,-1ll));
	for(int i=1;i<=m;i++){
		if(i>=1)dp[i]=max(dp[i],mp(dp[i-1].X+(dp[i-1].Y.X+1<(int)a[1].size()?a[1][dp[i-1].Y.X+1]:0),mp(dp[i-1].Y.X+1,dp[i-1].Y.Y)));
		if(i>=2)dp[i]=max(dp[i],mp(dp[i-2].X+(dp[i-2].Y.Y+1<(int)a[2].size()?a[2][dp[i-2].Y.Y+1]:0),mp(dp[i-2].Y.X,dp[i-2].Y.Y+1)));
	}
	int sum=0,ans=-inf;
	for(int i=-1;i<(int)a[3].size();i++){
		if(~i)sum+=a[3][i];
		if(3*(i+1)>m)break;
		ans=max(ans,sum+dp[m-3*(i+1)].X);
	}
	cout<<ans;
	return 0;
}
/*1
1 1
2 1
*/
/*2
2 2
1 3
2 2
*/
/*3
4 3
3 10
2 7
2 8
1 1
*/
/*4
1 29
2 8
*/