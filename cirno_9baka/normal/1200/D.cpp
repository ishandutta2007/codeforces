#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,i,k,j,s1[2005][2005],s2[2005][2005],s3[2005][2005],s4[2005][2005],p[2005][2005],q[2005][2005],a1[2005],a2[2005],a3[2005],a4[2005];
int ans;
int s[2005][2005];
char c[2005][2005];
int main()
{
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%s",c[i]+1);
	for(i=1;i<=n;i++)
		s1[0][i]=s2[i][0]=s3[n+1][i]=s4[i][n+1]=1;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			s1[i][j]=s1[i-1][j]&(c[i][j]=='W');
			s2[i][j]=s2[i][j-1]&(c[i][j]=='W');
		}
	for(i=n;i>=1;i--)
		for(j=n;j>=1;j--)
		{
			s3[i][j]=s3[i+1][j]&(c[i][j]=='W');
			s4[i][j]=s4[i][j+1]&(c[i][j]=='W');
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			p[i][max(1,j-k+1)]+=s1[i-1][j]&s3[min(i+k,n+1)][j];
			p[i][j+1]-=s1[i-1][j]&s3[min(i+k,n+1)][j];
			q[max(1,i-k+1)][j]+=s2[i][j-1]&s4[i][min(j+k,n+1)];
			q[i+1][j]-=s2[i][j-1]&s4[i][min(j+k,n+1)];
		}
	for(i=1;i<=n-k+1;i++)
	{
		int t=0;
		for(j=1;j<=n-k+1;j++)
		{
			t+=p[i][j];
			s[i][j]+=t;
		}
	}
	for(i=1;i<=n-k+1;i++)
	{
		int t=0;
		for(j=1;j<=n-k+1;j++)
		{
			t+=q[j][i];
			s[j][i]+=t;
		}
	}
	for(i=1;i<=n;i++)
	{
		a1[i]=a1[i-1]+s1[n][i];
		a2[i]=a2[i-1]+s2[i][n];
	}
	for(i=n;i>=1;i--)
	{
		a3[i]=a3[i+1]+s1[n][i];
		a4[i]=a4[i+1]+s2[i][n];
	}
	for(i=1;i<=n-k+1;i++)
		for(j=1;j<=n-k+1;j++)
			ans=max(ans,s[i][j]+a1[j-1]+a2[i-1]+a3[j+k]+a4[i+k]);
	cout<<ans;
}