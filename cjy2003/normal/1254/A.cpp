#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,r,c,k;
char mp[110][110],ans[110][110];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&r,&c,&k);
		for(int i=1;i<=r;++i)scanf("%s",mp[i]+1);
		int cnt=0;
		for(int i=1;i<=r;++i)
			for(int j=1;j<=c;++j)
				cnt+=mp[i][j]=='R';
		int cnt1=cnt/k,cnt2=cnt%k,id=1,now=0;
		for(int i=1;i<=r;++i)
		{
			if(i&1)
			{
				for(int j=1;j<=c;++j)
				{
					now+=mp[i][j]=='R';
					if(id<=26)ans[i][j]=id+'a'-1;
					else if(id<=52)ans[i][j]=id-26+'A'-1;
					else ans[i][j]=id-53+'0';
					if(id!=k&&now==cnt1+(id<=cnt2))now=0,++id;
				}
			}
			else
			{
				for(int j=c;j;--j)
				{
					now+=mp[i][j]=='R';
					if(id<=26)ans[i][j]=id+'a'-1;
					else if(id<=52)ans[i][j]=id-26+'A'-1;
					else ans[i][j]=id-53+'0';
					if(id!=k&&now==cnt1+(id<=cnt2))now=0,++id;
				}				
			}
		}
		for(int i=1;i<=r;++i)
		{
			for(int j=1;j<=c;++j)putchar(ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}