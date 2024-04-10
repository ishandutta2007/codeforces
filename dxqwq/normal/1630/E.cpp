// Problem: E. Expected Components
// Contest: Codeforces Round #768 (Div. 1)
// URL: https://codeforces.com/contest/1630/problem/E
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003],b[1000003],c[1000003],fac[1000003],ifac[1000003];
int f[1000003],F[1000003],F_[1000003],FF[1000003],iv[1000003];
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=1000000; ++i) 
	iv[i]=qp(i,p-2),fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=b[i]=0,f[i]=-1;
		for(int i=1; i<=n; ++i) ++a[read()];
		for(int i=1; i<=n; ++i) ++b[a[i]];
		int cnt=0;
		for(int i=1; i<=n; ++i) if(b[i]) c[++cnt]=i;
		int O=n;
		for(int i=1; i<=n; ++i) if(a[i]) O=__gcd(O,a[i]);
		for(int i=1; i<=O; ++i)if(O%i==0)
		{
			F[i]=fac[n/i];
			for(int j=1; j<=cnt; ++j)
				F[i]=F[i]*qp(ifac[c[j]/i],b[c[j]])%p;
			FF[i]=F[i];
		}
		for(int i=O; i>=1; --i) if(O%i==0)
			for(int j=2; i*j<=O; ++j) if(O%(i*j)==0)
				FF[i]=(FF[i]+p-FF[i*j])%p;
		bool S=0;
		for(int i=1; i<=n; ++i) if(a[i]==n) S=1;
		if(S){puts("1");continue;}
		int ans=0;
		for(int i=1; i<=O; ++i) if(O%i==0) ans=(ans+FF[i]*iv[n/i]%p)%p;
		int AA=ans;
		// printf("! %lld\n",F[1]);
		for(int i=1; i<=n; ++i) if(a[i]>=2)
		{
			if(f[a[i]]!=-1){ans=(ans+f[a[i]])%p;continue;}
			int R=0;
			for(int j=1; j<=O; ++j) if(O%j==0) if(a[i]/j>=2)
				F_[j]=F[j]*fac[a[i]/j]%p*ifac[a[i]/j-2]%p*ifac[n/j]%p*fac[n/j-2]%p;
				else F_[j]=0;
			for(int j=O; j>=1; --j)if(O%j==0)
				for(int k=2; j*k<=O; ++k)if(O%(j*k)==0)
					F_[j]=(F_[j]+p-F_[j*k])%p;
			for(int j=1; j<=O; ++j) if(O%j==0)
				R=(R+F_[j]*iv[n/j]%p)%p;
			f[a[i]]=(p-R)%p;
			ans=(ans+f[a[i]])%p;
			// puts("");
		}
		// printf("%lld %lld\n",ans,AA);
		printf("%lld\n",ans*n%p*qp(AA,p-2)%p);
		// puts("");
	}
	return 0;
}////////////