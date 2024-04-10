#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,i,j,x,y,ans;
int dfs(int sx,int sy)
{
	if (!sx&&!sy) return 0;
	int ans=1<<25;
	int i;
	for (i=0;i<=sx&&i*x<=n;i++)
	{
		int j;
		for (j=0;j<=sy&&i*x+j*y<=n;j++)
		{
			if (!(i+j))continue;
			ans=min(ans,dfs(sx-i,sy-j));
		}
	}
	return ans+1;
}
int main()
{
	cin>>n>>x>>y;
	cout<<dfs(4,2);
	return 0;
}