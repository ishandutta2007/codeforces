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

const int N=2e5+5,mod=998244353;
int n,k,a,last,ans1,ans2=1;

signed main()
{
	n=read();k=read();
	for(int i=n;i>=n-k+1;--i)
		ans1+=i;
	for(int i=1;i<=n;++i)
	{
		int a=read();
		if(a>=n-k+1)
		{
			if(last!=0)
				ans2=(ans2*(i-last))%mod;
			last=i;
		}
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}