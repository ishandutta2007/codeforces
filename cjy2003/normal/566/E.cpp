#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
bitset<1010>mp[1010],cur,bi[1010];
int n,cnt[1010];
bool vis[1010];
int main()
{
	scanf("%d",&n);
	if(n==2)return printf("1 2"),0;
	int x,y;
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&cnt[i]);
		for(int j=1;j<=cnt[i];++j)scanf("%d",&x),mp[i][x]=1;
	}
	int num=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if((cur=mp[i]&mp[j]).count()==2)
			{
				x=cur._Find_next(0);
				y=cur._Find_next(x);
				if(!bi[x][y])printf("%d %d\n",x,y),vis[x]=vis[y]=1,bi[x][y]=bi[y][x]=1,++num;
			}
	if(!num)
	{
		for(int i=2;i<=n;++i)printf("%d %d\n",1,i);
		return 0;
	}
	if(num==1)
	{
		x=0,y=0;
		for(int i=1;i<=n;++i)
			if(vis[i])
			{
				if(!x)x=i;
				else{y=i;break;}
			}
		for(int i=1;i<=n;++i)
			if(cnt[i]!=n)
			{
				for(int j=1;j<=n;++j)if(mp[i][j]==1&&!vis[j])vis[j]=1,printf("%d %d\n",x,j);
				break;
			}
		for(int i=1;i<=n;++i)if(!vis[i])printf("%d %d\n",y,i);
		return 0;
	}
	for(int i=1;i<=n;++i)bi[i][i]=1;
	for(int i=1;i<=n;++i)
		if(!vis[i])
		{
			int mi=0x3f3f3f3f,p;
			for(int j=1;j<=n;++j)if(mp[j][i]==1&&cnt[j]<mi)mi=cnt[j],p=j;
			x=0,y=0,num=0;
			cur.reset();
			for(int j=1;j<=n;++j)if(mp[p][j]==1&&vis[j])cur[j]=1,++num;
			if(num==2)
			{
				x=cur._Find_next(0);
				y=cur._Find_next(x);
				for(int j=1;j<=n;++j)if(mp[j][i]==0&&mp[j][x]!=mp[j][y])
				{
					if(mp[j][x])printf("%d %d\n",i,y);
					else printf("%d %d\n",i,x);
					break;
				}
			}
			else
			{
				for(int j=1;j<=n;++j)
					if(cur[j]&&(bi[j]&cur)==cur)
					{
						printf("%d %d\n",i,j);
						break;
					}
			}
		}
	return 0;
}