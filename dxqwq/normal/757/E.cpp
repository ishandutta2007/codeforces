// Problem: E. Bash Plays with Functions
// Contest: Codeforces - Codecraft-17 and Codeforces Round #391 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/contest/757/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int fac[1500003],ifac[1500003];
const int N=1500000,M=1e6;
vector<int> v[1000003];
bool vis[1000003];
int d[1000003];
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
int F(int x,int y)
{
	if(x==0) return 1;
	if(y==0) return 0;
	--y,x=x+y;
	return C(x,y);
}
int Q(int i,int r)
{
	int sum=F(i,r);
	for(int j=1; j<=i; ++j)
		sum=(sum+F(i-j,r)*2)%p;
	return sum;
}
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=N; ++i) fac[i]=fac[i-1]*i%p;
	ifac[N]=qp(fac[N],p-2);
	for(int i=N-1; i>=1; --i) ifac[i]=ifac[i+1]*(i+1)%p;
	for(int i=2; i<=M; ++i) if(!vis[i])
	{
		for(int j=1; i*j<=M; ++j)
		{
			vis[i*j]=1;
			d[i*j]=(j%i)?1:(d[j]+1);
			v[i*j].push_back(d[i*j]);
		}
	}
	for(int T=read();T--;)
	{
		int r=read(),n=read();
		int ans=1;
		for(int i:v[n]) ans=ans*Q(i,r)%p;
		printf("%lld\n",ans);
	}
	return 0;
}