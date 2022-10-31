#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
const int N = 5e5;

inline int read()
{
	int X=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){X=(X<<1)+(X<<3)+ch-'0';ch=getchar();}
	if(flag)return X;
	return ~(X-1);
}

inline void write(int X)
{
	if(X<0){X=~(X-1);putchar('-');}
	if(X>9){write(X/10);}
	putchar(X%10+'0');
}

int T,n,a[N];

signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		memset(a,0,sizeof a);
//		a[0]=1e9,a[n+1]=1e9;
		if(n==1)
		{
			a[1]=read();
			printf("%lld\n",a[1]);
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
		}
		int cnt=0,maxn=0,minn=1e9;
		for(int i=1;i<=n;i++)if(a[i]>a[i-1]&&a[i]>a[i+1])cnt+=min(a[i]-a[i-1],a[i]-a[i+1]),a[i]=max(a[i-1],a[i+1]);
		for(int i=0;i<=n;i++)maxn+=abs(a[i]-a[i+1]);
		cout<<cnt+maxn<<endl;
	}
	return 0;
}