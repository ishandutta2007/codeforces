#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define LL long long
int a[11][110][110];
using namespace std;
int n,q,c;
int main()
{
	memset(a,0,sizeof(a));
	cin>>n>>q>>c;
	for(int i=1;i<=n;i++)
	{
		int x,y,s;
		scanf("%d%d%d",&x,&y,&s);
		for(int i=0;i<=c;i++)
		{
			int t=(s+i)%(c+1);
			a[i][x][y]+=t;
		}
	}
	for(int t=0;t<=c;t++)
		for(int i=1;i<=100;i++)
			for(int j=1;j<=100;j++)
				a[t][i][j]=a[t][i][j]+a[t][i-1][j]+a[t][i][j-1]-a[t][i-1][j-1];

	for(int i=1;i<=q;i++)
	{
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		t%=(c+1);
		int ans=a[t][x2][y2]-a[t][x1-1][y2]-a[t][x2][y1-1]+a[t][x1-1][y1-1];
		printf("%d\n",ans);
	}
	return 0;
}