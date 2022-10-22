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
int t,m,n0,n1,n2;

int main()
{
	t=read();
	while(t--)
	{
		n0=read();n1=read();n2=read();
		if(n0==0&&n1==0)
			for(int i=1;i<=n2+1;++i)
				printf("1");
		else if(n2==0&&n1==0)
			for(int i=1;i<=n0+1;++i)
				printf("0");
		else
		{
			for(int i=1;i<=n2+1;++i)
				printf("1");
			for(int i=1;i<=n0+1;++i)
				printf("0");
			for(int i=1;i<=n1-1;++i)
				printf("%d",i%2);
		}
		printf("\n");
	}
	return 0;
}