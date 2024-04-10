#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q;
bool vis[2][100010];
int cnt;
void ins(int x,int y)
{
	if(vis[x^1][y])++cnt;
	if(vis[x^1][y-1])++cnt;
	if(vis[x^1][y+1])++cnt;
}
void era(int x,int y)
{
	if(vis[x^1][y])--cnt;
	if(vis[x^1][y-1])--cnt;
	if(vis[x^1][y+1])--cnt;
}
int main()
{
	scanf("%d %d",&n,&q);
	for(int i=1,x,y;i<=q;++i)
	{
		scanf("%d %d",&x,&y);
		if(vis[x-1][y])era(x-1,y);
		else ins(x-1,y);
		vis[x-1][y]^=1;
		if(cnt)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}