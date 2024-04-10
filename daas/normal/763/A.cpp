#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,mem[100001][2],col[100001],rest[100001][2],cnt;
int main()
{
	n=read();
	for(int i=1;i<n;++i)
		mem[i][0]=read(),mem[i][1]=read();
	for(int i=1;i<=n;++i)
		col[i]=read();
	for(int i=1;i<n;++i)
		if(col[mem[i][0]]!=col[mem[i][1]])
		{
			++cnt;
			rest[cnt][0]=mem[i][0];
			rest[cnt][1]=mem[i][1];
		}
	if(!cnt)
	{
		puts("YES");
		puts("1");
	}
	else
	{
		if(cnt==1)
		{
			puts("YES");
			printf("%d\n",rest[1][0]);
		}
		else
		{
			int ans=0;
			if(rest[1][0]==rest[2][0] || rest[1][0]==rest[2][1])
				ans=rest[1][0];
			if(rest[1][1]==rest[2][0] || rest[1][1]==rest[2][1])
				ans=rest[1][1];
			if(!ans)
			{
				puts("NO");
				return 0;
			}
			for(int i=3;i<=cnt;++i)
				if(ans!=rest[i][0] && ans!=rest[i][1])
				{
					puts("NO");
					return 0;
				}
			puts("YES");
			printf("%d\n",ans);
		}
	}
	return 0;
}