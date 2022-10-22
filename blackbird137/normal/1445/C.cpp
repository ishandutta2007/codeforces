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

const int N=1e6+5;
int t,a,b,ans,fac[N],tot;

map<int,int> mp;

inline int q_pow(int a,int b,int p);
inline bool witness(int a,int n,int x,int sum);
inline bool miller(int n);
inline int pollard(int n,int c);
inline void find(int n);

signed main()
{
	//freopen("yangli.in","r",stdin);
	//freopen("std.out","w",stdout);
	t=read();
	while(t--)
	{
		mp.clear();
		a=read();b=read();
		if(a%b!=0) ans=a;
		else
		{
			tot=0;ans=0;
			find(b);
			for(int i=1;i<=tot;++i)
			{
				int sum=0,tmp=a;
				while(tmp%fac[i]==0)
					tmp/=fac[i],sum++;
				if(sum!=0) ans=max(ans,a/q_pow(fac[i],sum-mp[fac[i]]+1,2e18));
			}	
		}
		printf("%lld\n",ans);
	}
}

inline int q_pow(int a,int b,int p)
{
	int c=1;
	while(b>0)
	{
		if(b&1) c=a*c%p;
		b>>=1;a=a*a%p;
	}
	return c;
}

inline bool witness(int a,int n,int x,int sum)
{
	int now=q_pow(a,x,n);
	if(now==n-1||now==1)
		return 1;
	while(sum--)
	{
		now=now*now%n;
		if(now==n-1)
			return 1;
	}
	return 0;
}

inline bool miller(int n)
{
	if(n<2) return 0;
	if(n==2) return 1;
	if((n&1)==0) return 0;
	int x=n-1,sum=0;
	while(!(x&1))
	{
		x>>=1;
		sum++;
	}
	for(int i=1;i<=20;++i)
	{
		int a=rand()%(n-1)+1;
		if(!witness(a,n,x,sum))
			return 0;
	}
	return 1;
}

inline int pollard(int n,int c)
{
	int x=rand()%n,y=x,d,i=1,k=2;
	while(1)
	{
		i++;
		x=(x*x%n+c)%n;
		d=__gcd(y-x,n);
		if(d<0) d=-d;
		if(d>1&&d<n) return d;
		if(y==x) return n;
		if(i==k){y=x;k<<=1;}
	}
}

inline void find(int n)
{
	if(miller(n))
	{
		if(!mp[n])
			fac[++tot]=n;
		mp[n]++;
		return;
	}
	int p=n;
	while(p>=n)
		p=pollard(p,rand()%(n-1)+1);
	find(n/p);find(p);
}