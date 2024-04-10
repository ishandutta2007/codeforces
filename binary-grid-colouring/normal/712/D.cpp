#include<bits/stdc++.h>
using namespace std;
int dp[210][400010];
const int mod=1e9+7;
int gao(int x,int y)
{
	return y<0 ? 0 : dp[x][y];
}
int main()
{
	int a,b,k,t;
	int ans;
	scanf("%d%d%d%d",&a,&b,&k,&t);
	k <<= 1;
	a = t*k-a+b;
	t <<= 1;
	ans = t*k;
	if(a>ans){
		cout<<0<<endl;
		return 0;
	}
	for(int i=0;i<=ans;i++) dp[0][i]=1;
	
	for(int i=1;i<=t;i++)
	for(int j=0;j<=ans;j++)
	{
		dp[i][j]=((long long)gao(i,j-1) + gao(i-1,j) - gao(i-1,j-k-1))%mod;
	}
	ans = ( gao(t,ans) - gao(t,a) )%mod;
	if(ans<0) ans+=mod;
	printf("%d\n",ans);
	return 0;
}