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
int t,n,a[N],b[N],c[N],all,ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;++i)
		{
			a[i]=read();
			b[i]=read();
		}
		all=c[1]=max(0ll,a[1]-b[n]);
		for(int i=2;i<=n;++i)
		{
			c[i]=max(0ll,a[i]-b[i-1]);
			all+=c[i];
		}
		ans=1e18;
		for(int i=1;i<=n;++i)
			ans=min(ans,all-c[i]+a[i]);
		printf("%lld\n",ans);
	}
	return 0;
}