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
int t,n,q,a[N],ans,last;

signed main()
{
	t=read();
	while(t--)
	{
		n=read();q=read();
		ans=0;
		for(int i=1;i<=n;++i)
			a[i]=read();
		for(int i=1;i<=n;++i)
			if(i==n) ans+=a[i],last=0;
			else if(a[i+1]<a[i])
			{
				int j=i+1,mmin=1e18;
				for(;j<=n&&a[j]<a[j-1];++j)
					mmin=min(mmin,a[j]);
				ans+=a[i]-mmin;
				last=mmin;i=j-1;
			}
		ans+=last;
		printf("%lld\n",ans);
	}
	return 0;
}