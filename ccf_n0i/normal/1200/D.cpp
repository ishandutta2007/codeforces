#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,a[2005][2005];
char mp[2005][2005];
int main()
{
	scanf("%d%d",&n,&m);
	rep(i,n)
	{
		scanf(" ");
		rep(j,n)
		{
			scanf("%c",&mp[i][j]);
		}
	}
	rep(i,n)
	{
		int ly=1,ry=n-m+1,lx=1,rx=n-m+1;
		rep(j,n)
		{
			if(mp[i][j]=='B')
			{
				lx=max(lx,i-m+1);
				rx=min(rx,i);
				ly=max(ly,j-m+1);
				ry=min(ry,j);
			}
		}
		if(lx>rx)continue;
		if(ly>ry)continue;
		a[lx][ly]++;
		a[lx][ry+1]--;
		a[rx+1][ly]--;
		a[rx+1][ry+1]++;
	}
	rep(j,n)
	{
		int ly=1,ry=n-m+1,lx=1,rx=n-m+1;
		rep(i,n)
		{
			if(mp[i][j]=='B')
			{
				lx=max(lx,i-m+1);
				rx=min(rx,i);
				ly=max(ly,j-m+1);
				ry=min(ry,j);
			}
		}
		if(lx>rx)continue;
		if(ly>ry)continue;
		a[lx][ly]++;
		a[lx][ry+1]--;
		a[rx+1][ly]--;
		a[rx+1][ry+1]++;
	}
	int ans=0;
	rep(i,n-m+1)rep(j,n-m+1)
	{
		a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		ans=max(ans,a[i][j]);
	}
	cout<<ans<<endl;
	return 0;
}