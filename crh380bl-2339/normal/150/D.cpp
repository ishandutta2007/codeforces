#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[155],f[155][155][155],ans[155];char s[155];
int main()
{
	int n,i,j,k;cin>>n;
	for (i=1;i<=n;i++) {cin>>a[i];if (a[i]==-1) a[i]=-100000000;}
	cin>>s+1;memset(f,-40,sizeof(f));
	for (i=1;i<=n+1;i++) f[i][i-1][0]=0;
	for (i=n;i;i--)
	{
		for (j=i;j<=n;j++)
		{
			for (k=1;k<=j-i+1;k++)
			{
				if (s[i]==s[j])
				{
					if (k==1) f[i][j][k]=max(f[i+1][j][0],f[i][j-1][0]);
					else f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k-2]);
				}
				for (int x=i;x<j;x++)
				{
					f[i][j][k]=max(f[i][j][k],f[i][x][k]+f[x+1][j][0]);
					f[i][j][k]=max(f[i][j][k],f[i][x][0]+f[x+1][j][k]);
				}
				f[i][j][0]=max(f[i][j][0],f[i][j][k]+a[k]);
			}
		}
	}
	for (i=1;i<=n;i++)
	{
		ans[i]=ans[i-1];
		for (j=0;j<i;j++)
		{
			ans[i]=max(ans[i],ans[j]+f[j+1][i][0]);
		}
	}
	cout<<ans[n];
}