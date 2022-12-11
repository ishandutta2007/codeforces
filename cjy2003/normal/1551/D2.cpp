#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,m,k;
char ans[110][110];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d",&n,&m,&k);
		if(n&1)
		{
			if(k<m/2||(k-m/2)&1)printf("NO\n");
			else
			{
				printf("YES\n");
				int cnt=(k-m/2)/2;
				for(int i=1;i<=n/2;++i)
					for(int j=1;j<=m/2;++j)
						if(cnt)
						{
							ans[i*2-1][j*2-1]=ans[i*2-1][j*2]=j&1?'a':'b';
							ans[i*2][j*2-1]=ans[i*2][j*2]=j&1?'b':'a';
							--cnt;
						}
						else
						{
							ans[i*2-1][j*2-1]=ans[i*2][j*2-1]=i&1?'c':'d';
							ans[i*2-1][j*2]=ans[i*2][j*2]=i&1?'d':'c';
						}
				for(int i=1;i<=m/2;++i)ans[n][i*2-1]=ans[n][i*2]=i&1?'e':'f';
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=m;++j)putchar(ans[i][j]);
					putchar('\n');
				}
			}
		}
		else if(m&1)
		{
			if(n*m/2-k<n/2||k&1)printf("NO\n");
			else
			{
				printf("YES\n");
				int cnt=k/2;
				for(int i=1;i<=n/2;++i)
					for(int j=1;j<=m/2;++j)
						if(cnt)
						{
							ans[i*2-1][j*2-1]=ans[i*2-1][j*2]=j&1?'a':'b';
							ans[i*2][j*2-1]=ans[i*2][j*2]=j&1?'b':'a';
							--cnt;
						}
						else
						{
							ans[i*2-1][j*2-1]=ans[i*2][j*2-1]=i&1?'c':'d';
							ans[i*2-1][j*2]=ans[i*2][j*2]=i&1?'d':'c';
						}
				for(int i=1;i<=n/2;++i)ans[i*2-1][m]=ans[i*2][m]=i&1?'e':'f';
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=m;++j)putchar(ans[i][j]);
					putchar('\n');
				}
			}
		}
		else
		{
			if(k&1)printf("NO\n");
			else
			{
				printf("YES\n");
				int cnt=k/2;
				for(int i=1;i<=n/2;++i)
					for(int j=1;j<=m/2;++j)
						if(cnt)
						{
							ans[i*2-1][j*2-1]=ans[i*2-1][j*2]=j&1?'a':'b';
							ans[i*2][j*2-1]=ans[i*2][j*2]=j&1?'b':'a';
							--cnt;
						}
						else
						{
							ans[i*2-1][j*2-1]=ans[i*2][j*2-1]=i&1?'c':'d';
							ans[i*2-1][j*2]=ans[i*2][j*2]=i&1?'d':'c';
						}
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=m;++j)putchar(ans[i][j]);
					putchar('\n');
				}
			}
		}
	}
	return 0;
}