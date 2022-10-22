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
int t,n,m,a[N],ans;

bool cmp(int a,int b)
{
	return a>b;
}

inline bool check(int x);

signed main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();
		ans=0;
		for(int i=1;i<=n;++i)
			a[i]=read();
		sort(a+1,a+1+n,cmp);
		int l=1,r=n;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

inline bool check(int x)
{
	int all=0;
	for(int i=1;i<=x;++i)
		all+=a[i];
	return all/x>=m;
}