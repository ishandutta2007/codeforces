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

int t,n,ans;

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		int x=(2+n)*(n/2)/2;
		int y=(1+n-3)*(n/2-1)/2;
		int z=x-y;
		if(z<=n||z%2==0||z<=n-3)
			printf("NO\n");
		else
		{
			printf("YES\n");
			for(int i=1;i<=n/2;++i)
				printf("%d ",i*2);
			for(int i=1;i<=n/2-1;++i)
				printf("%d ",i*2-1);
			printf("%d\n",z);
		}
	}
	return 0;
}