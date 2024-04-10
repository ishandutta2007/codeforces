// Problem: C. Timofey and remoduling
// Contest: Codeforces Round #395 (Div. 1)
// URL: https://codeforces.com/contest/763/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int p;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
namespace modsqrt
{
	mt19937 rnd(1234);
	//const long long p=998244353,p0=499122176;
	long long p,p0;
	long long a,w;
	struct cp
	{
		long long x,y;
		cp operator*(const cp&t){return(cp){(x*t.x%p+y*t.y%p*w%p)%p,(x*t.y%p+y*t.x%p)%p};}
	};
	cp qp(cp x,long long y)
	{
		cp res=(cp){1,0};
		for(cp now=x; y; y>>=1,now=now*now) if(y&1) res=res*now;
		return res;
	}
	long long qpow(long long x,long long y)
	{
		long long res=1;
		for(long long now=x; y; y>>=1,now=now*now%p) (y&1)&&(res=res*now%p);
		return res;
	}
	void setp(long long P)
	{
		p=P,p0=(P-1)>>1;
		return ;
	}
	long long getans(long long n)
	{
		while(1)
		{
			a=1ll*rnd()%(p-1)+1,w=(a*a%p-n+p)%p;
			if(qpow(w,p0)==p-1) break;
		}
		return qp((cp){a,1},p0+1).x;
	}
	int solve(long long n)
	{
		if(n==0) 
		{
			return 0;
		}
		if(qpow(n,p0)==p-1) 
		{
			return -1;
		}
		long long ans=getans(n);
		if(ans<p-ans) return ans;
		return p-ans;
	}
};
int a[1000003];
set<int> numbers;
int n;
void check(int fir,int d)
{
	int rif=fir;
	for(int i=1; i<=n; ++i,fir=(fir+d)%p)
		if(numbers.find(fir)==numbers.end()) return ;
	printf("%lld %lld\n",rif,d);
	exit(0);
}
signed main()
{
	p=read();
	modsqrt::setp(p);
	n=read();
	if(n==p)
	{
		puts("0 1");
		return 0;
	}
	for(int i=1; i<=n; ++i) a[i]=read(),numbers.insert(a[i]);
	if(n==1)
	{
		printf("%lld 0\n",a[1]);
		return 0;
	}
	if(n==2)
	{
		printf("%lld %lld\n",min(a[1],a[2]),max(a[1],a[2])-min(a[1],a[2]));
		return 0;
	}
	int s=0,ss=0;
	for(int i=1; i<=n; ++i) s=(s+a[i])%p,ss=(ss+a[i]*a[i])%p;
	s=s*qp(n,p-2)%p;
	//(x-a)^2~(x+a)^2
	//x^2+a^2+
	if(n&1)
	{
		int N=(n+1)>>1,lol=0;
		for(int i=1; i<=n; ++i) ss=(ss+p-(s*s%p))%p;
		for(int i=1; i<=n; ++i) lol=(lol+(i-N)*(i-N))%p;
		ss=ss*qp(lol,p-2)%p;
		int o=modsqrt::solve(ss);
		if(o==-1) puts("-1"),exit(0);
		check((p+s-o*(N-1)%p)%p,o);
	}
	else
	{
		//(-2.5a)^2+(-1.5a)^2
		if(p<=5000)
		{
			for(int o=1; o<p; ++o)
				check((p+s-o*(n-1)%p*qp(2,p-2)%p)%p,o);
			puts("-1");
			return 0;
		}
		int N=n+1,lol=0;
		for(int i=1; i<=n; ++i) ss=(ss+p-(s*s%p))%p;
		for(int i=1; i<=n; ++i) 
		lol=(lol+(i*2-N)*(i*2-N))%p;
		lol=lol*qp(4,p-2)%p;
		ss=ss*qp(lol,p-2)%p;
		int o=modsqrt::solve(ss);
		if(o==0||o==-1) puts("-1"),exit(0);
		check((p+s-o*(n-1)%p*qp(2,p-2)%p)%p,o);
	}
	puts("-1");
	return 0;
}