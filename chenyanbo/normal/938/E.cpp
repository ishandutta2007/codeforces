#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
#define MO 1000000007
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int o,n,ans,v[35],a[1000005];

inline int ksm(int p, int k)
{
	v[0]=p;
	for(int i=1; i<=29; ++i)v[i]=(long long)v[i-1]*v[i-1]%MO;
	int s=1;
	for(int i=29; i>=0; --i)if(1<<i<=k){
		k-=1<<i;
		s=(long long)s*v[i]%MO;
	}
	return s;
}

int main()
{
	n=read(); 
	for(int i=1; i<=n; ++i)a[i]=read();
	sort(a+1,a+n+1);
	ans=0;
	for(int i=1; i<=n;){
	    o=i+1;
		while(a[o]==a[i])++o;
		ans=((long long)ans+(long long)ksm(n-i+1,MO-2)%MO*a[i]%MO*(o-i))%MO;
		i=o;
	}
	ans=(ans+MO-a[n])%MO;
	for(int i=2; i<=n; ++i)ans=(long long)ans*i%MO;
	printf("%d\n",ans);
}