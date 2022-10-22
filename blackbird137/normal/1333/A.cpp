#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>

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
int t,n,m;

int main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		if(n*m%2==1)
		{
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
					if(i%2==j%2)
						printf("B");
					else
						printf("W");
				printf("\n");
			}
		}
		else
		{
			int flag=1;
			for(int i=1;i<=n;++i)
			{
				for(int j=1;j<=m;++j)
					if(i%2==j%2)
						printf("B");
					else if(flag)
						printf("B"),flag=0;
					else
						printf("W");
				printf("\n");
			}
		}
	}
	return 0;
}