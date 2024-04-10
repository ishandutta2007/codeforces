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

int n,m,x,y,sum,now;

int main()
{
	n=read();m=read();
	x=read();y=read();
	printf("%d %d\n",x,y);
	for(int j=1;j<=m;++j)
		if(j!=y)
			printf("%d %d\n",x,j);
	for(int i=1;i<=n;++i)
		if(i!=x)
		{
			if(now%2==0)
				for(int j=m;j>=1;--j)
					printf("%d %d\n",i,j);
			else
				for(int j=1;j<=m;++j)
					printf("%d %d\n",i,j);
			now++;
		}
	return 0;
}