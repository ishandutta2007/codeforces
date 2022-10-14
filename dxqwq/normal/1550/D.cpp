// Problem: D. Excellent Arrays
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int fac[1000003],ifac[1000003];
int C(int n,int m)
{
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=200000; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int T=read();T--;)
	{
		int n=read(),A=read(),B=read(),l=A-n,r=B-1;
		int s=(B-A+1);
		if(r<=0||l>=0)
		{
			printf("%lld\n",qp(s,n));
		}
		else
		{
			l=abs(l);
			if(l>r) swap(l,r);
			int cnt=0,ans=0;
			for(int d=1; d<=l; ++d)
			{
				int tl=min(n,d),tr=min(n,r-l+d);
				int cd=(tl+tr)-n;
				tl-=cd,tr-=cd;
				
				if(cd==n)
				{
					if(cnt!=(n/2)*(n-(n/2)))
					ans=0;
					ans+=(l-d+1)*C(n,n/2)%p;
					ans%=p;
					if(n&1) ans+=(l-d+1)*C(n,(n+1)/2)%p;
					ans%=p;
					break;
				}
				
				int mx=min(n/2,tl+cd)*(n-min(n/2,tl+cd));
				if(cnt!=mx) cnt=mx,ans=0;
				ans+=C(cd,n/2-tl);
				ans%=p;
				if(n&1) ans+=C(cd,(n+1)/2-tl);
				ans%=p;
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}