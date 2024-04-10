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

const int N=2e5+5;
int n,a,bit[30],ans,now;

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a=read();
		for(int j=0;j<=20;++j)
			bit[j]+=((a>>j)&1);
	}
	for(int i=1;i<=n;++i)
	{
		now=0;
		for(int j=0;j<=20;++j)
			if(bit[j])
			{
				bit[j]--;
				now|=(1<<j);
			}
		ans+=now*now;
	}
	printf("%lld\n",ans);
	return 0;
}