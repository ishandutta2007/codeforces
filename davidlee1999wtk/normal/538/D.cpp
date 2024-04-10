#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define N 100005
#define fi first
#define se second
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
int dx[10005],dy[10005],z,n,ans[105][105];
char mp[55][55];
bool vis[55][55];
bool check(int x,int y)
{
	if(x>0&&y>0&&x<=n&&y<=n)
		return 1;
	return 0;
}
int main()
{
	int i,j,r,c,now,tx,ty;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%s",mp[i]+1);
	for(i=-n+1;i<n;i++)
		for(j=-n+1;j<n;j++)
		{
			now=0;
			for(r=1;r<=n;r++)
				for(c=1;c<=n;c++)
					if(mp[r][c]=='o')
					{
						tx=r+i,ty=c+j;
						if(check(tx,ty))
							if(mp[tx][ty]=='.')
								if(!now)
									now=-1;
					}
			ans[i+n][j+n]=now;
			if(now!=-1)
			{
				for(r=1;r<=n;r++)
				for(c=1;c<=n;c++)
					if(mp[r][c]=='o')
					{
						tx=r+i,ty=c+j;
						if(check(tx,ty))
							vis[tx][ty]=1;
					}
			}
		}
	for(r=1;r<=n;r++)
		for(c=1;c<=n;c++)
			if(mp[r][c]=='x'&&!vis[r][c])
			{
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	for(i=1;i<n*2;i++)
	{
		for(j=1;j<n*2;j++)
		{
			if(i==n&&j==n)
			{
				printf("o");
				continue;
			}
			if(ans[i][j]<0)
				printf(".");
			else printf("x");
		}
		cout<<endl;
	}
	return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);