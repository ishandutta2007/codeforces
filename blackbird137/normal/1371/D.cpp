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

const int N=305;
int t,n,k,mmap[N][N];

int main()
{
	t=read();
	while(t--)
	{
		memset(mmap,0,sizeof(mmap));
		n=read();k=read();
		int x=1,y=1,a=1;
		while(k--)
		{
			mmap[x][y]=1;
			x++,y++;
			if(x>n) x=1,y=++a;
			if(y>n) y-=n;
		}
		int maxr=0,minr=0x7fffffff,maxc=0,minc=0x7fffffff;
		for(int i=1;i<=n;++i)
		{
			int sum=0;
			for(int j=1;j<=n;++j)
				sum+=mmap[i][j];
			maxr=max(maxr,sum);
			minr=min(minr,sum);
		}
		for(int j=1;j<=n;++j)
		{
			int sum=0;
			for(int i=1;i<=n;++i)
				sum+=mmap[i][j];
			maxc=max(maxc,sum);
			minc=min(minc,sum);
		}
		printf("%d\n",(maxr-minr)*(maxr-minr)+(maxc-minc)*(maxc-minc));
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
				printf("%c",mmap[i][j]+'0');
			printf("\n");
		}
	}
	return 0;
}