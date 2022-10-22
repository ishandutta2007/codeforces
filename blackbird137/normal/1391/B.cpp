#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<bitset>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<map>

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=105;
int t,n,m,ans;
char mmap[N][N];

int main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		ans=0;
		for(int i=1;i<=n;++i)
			scanf("%s",mmap[i]+1);
		for(int i=1;i<=n;++i)
			if(mmap[i][m]=='R')
				ans++;
		for(int j=1;j<=m;++j)
			if(mmap[n][j]=='D')
				ans++;
		printf("%d\n",ans);
	}
	return 0;
}