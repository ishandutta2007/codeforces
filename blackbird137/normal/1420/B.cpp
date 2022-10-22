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

const int N=1e5+5;
int t,n,a,sum[32],ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ans=0;
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;++i)
		{
			a=read();
			int pos=0;
			for(int j=31;j>=0;--j)
				if(a&(1<<j))
				{
					pos=j;
					break;
				}
			ans+=sum[pos];
			sum[pos]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}