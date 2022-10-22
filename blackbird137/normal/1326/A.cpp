#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=3e5+5;
int t,n;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		if(n==1) printf("-1\n");
		else
		{
			printf("2");
			for(int i=2;i<=n;++i)
				printf("3");
			printf("\n");
		}
	}
	return 0;
}