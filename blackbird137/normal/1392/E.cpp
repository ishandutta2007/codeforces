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

const int N=100;
int n,q,k,mmap[N][N];

signed main()
{
	scanf("%lld",&n);
	for(int i=2;i<=2*n-1;++i)
		for(int j=1;j<=i;++j)
			if(i%2ll!=j%2ll)
				mmap[j][i-j+1]=(1ll<<(i-2ll));
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			printf("%lld ",mmap[i][j]);
		printf("\n");
		fflush(stdout);
	}
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&k);
		int x=1,y=1,now=0;
		while(1)
		{
			printf("%lld %lld\n",x,y);
			fflush(stdout);
			if(x==n&&y==n)
				break;
			if(x==n) y++;
			else if(y==n) x++;
			else
			{
				if((k&(1ll<<now))!=0)
				{
					if(mmap[x+1][y]!=0) x++;
					else y++;
				}
				else
				{
					if(mmap[x+1][y]==0) x++;
					else y++;
				}
				now++;
			}
		}
	}
	return 0;
}