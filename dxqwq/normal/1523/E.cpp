// Problem: E. Crypto Lights
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//If I can prove that everyone is wrong......
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
	if(m<0||m>n) return 0;
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=1000000; ++i) 
	fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
    for(int T=read();T--;)
    {
    	int n=read(),m=read()-1;
    	//n+2m+1i+2>=m
    	int ans=1;
    	for(int i=1; i<=n; ++i)
    	{
    		ans=ans+C(n+m+m-(i+1)*m,i)*qp(C(n,i),p-2)%p;
    		ans%=p;
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}