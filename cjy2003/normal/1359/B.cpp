#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,x,y;
char mp[110][1010];
int ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&x,&y);y=min(y,2*x);
		for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
		ans=0;
		for(int i=1;i<=n;++i)
		{
			int last=0;
			for(int j=1;j<=m;++j)
				if(mp[i][j]=='*')
				{
					int len=j-last-1;
					if(len&1)ans+=x;
					ans+=len/2*y;
					last=j;
				}
			int len=m-last;
			if(len&1)ans+=x;
			ans+=len/2*y;
		//	printf("%d\n",ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}