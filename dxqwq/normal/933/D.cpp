// Problem: D. A Creative Cutout
// Contest: Codeforces - Codeforces Round #462 (Div. 1)
// URL: https://codeforces.com/contest/933/problem/D
// Memory Limit: 296 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int LIM=8;
struct Lagrange
{
	int F[LIM+1],G[LIM+1],H[LIM+1],x[LIM+1],y[LIM+1];
	void clr()
	{
		memset(F,0,sizeof(F)),
		memset(G,0,sizeof(G)),
		memset(H,0,sizeof(H));
	}
	const int n=LIM;
	void init(int nnnnnnnn)
	{
		F[0]=1;
		for(int i=1; i<=n; ++i) 
		{
			for(int j=0; j<i; ++j)
				G[j]=(G[j]+p-1ll*F[j]*x[i]%p)%p,
				G[j+1]=(G[j+1]+F[j])%p;
			for(int j=0; j<=i; ++j) F[j]=G[j],G[j]=0;
		}
		for(int i=1; i<=n; ++i)
		{
			for(int j=0; j<=n; ++j) G[j]=F[j];
			int S=1;
			for(int j=1; j<=n; ++j)
				if(j!=i) S=1ll*S*(p+x[i]-x[j])%p;
			S=1ll*qp(S,p-2)*y[i]%p;
			for(int j=n-1; j>=0; --j)
				H[j]=(H[j]+1ll*G[j+1]*S)%p,
				G[j]=(G[j]+1ll*G[j+1]*x[i])%p;
		}
		return ;
	}
	int query(int x0)
	{
		x0%=p;
		int ans=0;
		for(int i=0,t=1; i<n; ++i,t=1ll*t*x0%p)
			ans=(ans+1ll*t*H[i])%p;
		return ans;
	}
}A,f;
signed main()
{
	int n=read();
	for(int i=1; i<=LIM; ++i)
		f.x[i]=i,f.y[i]=(f.y[i-1]+(p+n+1-i)%p*i)%p;
	f.init(LIM);
	int ans=f.query(n);
	for(int i=1; i*i<=n; ++i)
	{
		if(i*i+LIM*LIM>n){
			for(int j=0; i*i+j*j<=n; ++j)
				ans=(ans+f.query(n+1-i*i-j*j)*4)%p;
		}
		else
		{
			A.clr();
			int sum=0;
			for(int j=0; j<LIM; ++j)
				sum=(sum+f.query(n+1-i*i-j*j))%p,
				A.x[j+1]=j+1,A.y[j+1]=sum;
			A.init(LIM);
			ans=(ans+A.query((int)sqrtl(n-i*i)+1)*4)%p;
		}
	}
	printf("%lld\n",ans);
	return 0;
}