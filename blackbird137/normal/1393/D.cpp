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

const int N=2005;
int n,m,s1[N][N],s2[N][N],s3[N][N],s4[N][N],ans;
char mmap[N][N];

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;++i)
		scanf("%s",mmap[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(mmap[i-1][j]==mmap[i][j-1]&&mmap[i][j-1]==mmap[i][j])
				s1[i][j]=min(s1[i-1][j],s1[i][j-1])+1;
	for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)
			if(mmap[i-1][j]==mmap[i][j+1]&&mmap[i][j+1]==mmap[i][j])
				s2[i][j]=min(s2[i-1][j],s2[i][j+1])+1;
	for(int i=n;i>=1;--i)
		for(int j=1;j<=m;++j)
			if(mmap[i+1][j]==mmap[i][j-1]&&mmap[i][j-1]==mmap[i][j])
				s3[i][j]=min(s3[i+1][j],s3[i][j-1])+1;
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
			if(mmap[i+1][j]==mmap[i][j+1]&&mmap[i][j+1]==mmap[i][j])
				s4[i][j]=min(s4[i+1][j],s4[i][j+1])+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ans+=min(s1[i][j],min(s2[i][j],min(s3[i][j],s4[i][j])))+1;
	printf("%d\n",ans);
	return 0;
}