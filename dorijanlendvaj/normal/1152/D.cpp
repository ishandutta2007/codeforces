#include <bits/stdc++.h>

using namespace std;

int n,d[2010][4010][2];

int dp(int i, int j, int k) 
{
	if (j<0) return -1000000006;
	return d[i][j][k]%1000000007;
} 

int main() 
{
	cin>>n;
	for (int i=0;i<=2*n;++i) for (int j=0;j<=4*n;++j) d[i][j][0]=d[i][j][1]=-1000000006;
	d[0][0][0]=d[0][0][1]=0;
	for (int i=0;i<2*n;++i) for (int j=0;j<=2*n;++j)
	{
		if (dp(i,j-1,1)<0 && dp(i,j+1,1)<0) d[i+1][j][0]=-1000000006;
		else d[i+1][j][0]=max(0,dp(i,j-1,1))+max(dp(i,j+1,1),0);
		if (dp(i,j-1,1)>=0 || dp(i,j+1,0)>=0 || dp(i,j-1,0)>=0 || dp(i,j+1,1)>=0)
		{
			int a=max(0,dp(i,j-1,1))+max(0,dp(i,j+1,0)),b=max(0,dp(i,j-1,0))+max(0,dp(i,j+1,1));
			if (dp(i,j+1,0)>=0) d[i+1][j][1]=max(d[i+1][j][1],a+1);
			else d[i+1][j][1]=max(d[i+1][j][1],a);
			if (dp(i,j-1,0)>=0) d[i+1][j][1]=max(d[i+1][j][1],b+1);
			else d[i+1][j][1]=max(d[i+1][j][1],b);
		}
		//cout<<i+1<<' '<<j<<' '<<dp(i+1, j, 0)<<' '<<dp(i+1, j, 1)<<endl;
		//cout<<dp(i,j-1,1)+dp(i,j+1,0)-(dp(i,j-1,0)+dp(i,j+1,1))<<endl;
	}
	cout<<max(dp(2*n,0,1),dp(2*n,0,0));
}