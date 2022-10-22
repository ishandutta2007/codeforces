#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=1000;
int n;
int a[N+1];
int dp[N+1][N+2],pa1[N+1][N+2],pa2[N+1][N+2];
vector<pair<int,int> > ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	if(n==1)return printf("%d\n1",a[1]),0;
	if(n==2)return printf("%d\n1 2\n",max(a[1],a[2])),0;
	for(int i=1;i<n;i++)dp[i][n]=max(a[i],a[n]);
	for(int i=1;i<=n;i++)dp[i][n+1]=a[i];
	for(int i=n;i;i--)for(int j=n-1;j>i;j--){
		dp[i][j]=max(a[i],a[j])+dp[j+1][j+2];pa1[i][j]=i;pa2[i][j]=j;
		if(max(a[i],a[j+1])+dp[j][j+2]<dp[i][j])
			dp[i][j]=max(a[i],a[j+1])+dp[j][j+2],pa1[i][j]=i,pa2[i][j]=j+1;
		if(max(a[j],a[j+1])+dp[i][j+2]<dp[i][j])
			dp[i][j]=max(a[j],a[j+1])+dp[i][j+2],pa1[i][j]=j,pa2[i][j]=j+1;
	}
//	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
//		printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
	printf("%d\n",dp[1][2]);
	int nowi=1,nowj=2;
	while(pa1[nowi][nowj]){
		int x=pa1[nowi][nowj],y=pa2[nowi][nowj];
		ans.pb(mp(x,y));
		if(!x)break;
		x==nowj?nowj+=2
		:y==nowj?nowi=nowj+1,nowj+=2
		:(nowi=nowj,nowj+=2);
	};
	ans.pb(mp(nowi,nowj));
	for(int i=0;i<ans.size();i++)
		printf(ans[i].Y==n+1?"%d\n":"%d %d\n",ans[i].X,ans[i].Y);
	return 0;
}
/*1
4
1 2 3 4
*/
/*2
5
2 4 3 1 4
*/