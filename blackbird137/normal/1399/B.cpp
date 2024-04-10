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

const int N=105;
int t,n,a[N],b[N],ma,mb,ans;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();
		ma=mb=1e18;
		for(int i=1;i<=n;++i)
			a[i]=read(),ma=min(ma,a[i]);
		for(int i=1;i<=n;++i)
			b[i]=read(),mb=min(mb,b[i]);
		ans=0;
		for(int i=1;i<=n;++i)
			ans+=max(a[i]-ma,b[i]-mb);
		printf("%lld\n",ans);
	}
	return 0;
}