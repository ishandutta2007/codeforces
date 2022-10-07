#include<bits/stdc++.h>
using namespace std;
long long a[105][105],mn[105][105],mx[105][105],s=1,x;
int i,n,j,q;
void dfs(int x,int y,long long s)
{
	if(x==1&&y==1)
	{
		cout<<x<<' '<<y<<endl;
		return;
	}
	s-=a[x][y];
	if(s>=mn[x-1][y]&&x!=1)
		dfs(x-1,y,s);
	else
		dfs(x,y-1,s);
	cout<<x<<' '<<y<<endl;
}
int main()
{
	scanf("%d",&n);
	for(i=2;i<=n+1;++i)
		for(j=i-2;j>=1;--j)
		{
			mn[j][i-j]=mx[j+1][i-j-1]+1;
			a[j][i-j]=mn[j][i-j]-mn[j][i-j-1];
			if(j==1)
				mx[j][i-j]=mx[j][i-j-1]+a[j][i-j];
			else
				mx[j][i-j]=mx[j-1][i-j]+a[j][i-j];
		}
	for(i=n+2;i<2*n;++i)
	{
		mx[n][i-n]=mx[n-1][i-n];
		for(j=n-1;i-j<=n;--j)
		{
			mn[j][i-j]=mx[j+1][i-j-1]+1;
			a[j][i-j]=mn[j][i-j]-mn[j][i-j-1];
			mx[j][i-j]=mx[j-1][i-j]+a[j][i-j];
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
			cout<<a[i][j]<<' '/*<<mn[i][j]<<' '<<mx[i][j]<<' '*/;
		cout<<endl;
	}
	scanf("%d",&q);
	while(q--)
	{
		cin>>x;
		dfs(n,n,x);
	}
}