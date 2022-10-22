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

const int N=2e5+5;
int t,n,m,sum[N];

int main()
{
	t=read();
	while(t--)
	{
		m=n=read();
		for(int i=1;i<=n;++i)
			sum[i]=9;
		for(int i=n;i>=1&&n>=1;--i)
		{
			sum[i]=8;
			n-=4;
		}
		for(int i=1;i<=m;++i)
			printf("%d",sum[i]);
		printf("\n");
	}
	return 0;
}