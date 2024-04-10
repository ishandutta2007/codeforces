// Problem: B. Resource Distribution
// Contest: Codeforces - Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3)
// URL: https://codeforces.com/contest/966/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
pair<int,int> a[1000003];
#define fi first
#define se second
int R[1000003];
int LA[1000003],RA[1000003];
int LB[1000003],RB[1000003];
void print(int l1,int r1,int l2,int r2)
{
	puts("Yes");
	printf("%lld %lld\n",r1-l1+1,r2-l2+1);
	for(int i=l1; i<=r1; ++i) printf("%lld ",a[i].se);
	puts("");
	for(int i=l2; i<=r2; ++i) printf("%lld ",a[i].se);
	puts("");
	exit(0);
	return ;
}
signed main()
{
	int n=read();
	int A=read(),B=read();
	for(int i=1; i<=n; ++i) a[i].fi=read(),a[i].se=i;
	//1 for A
	sort(a+1,a+n+1);
	for(int l=1,r=1; l<=n; ++l)
	{
		r=l+(A-1)/a[l].first;
		if(r<=n) R[l]=r; else R[l]=1e12;
	}
	LA[n+1]=n+1,RA[n+1]=1e12;
	for(int i=n; i>=1; --i) 
	{
		LA[i]=LA[i+1],RA[i]=RA[i+1];
		if(R[i]<RA[i])
		{
			LA[i]=i,RA[i]=R[i];
		}
	}
	for(int l=1,r=1; l<=n; ++l)
	{
		r=l+(B-1)/a[l].first;
		if(r<=n) R[l]=r; else R[l]=1e12;
	}
	LB[n+1]=n+1,RB[n+1]=1e12;
	for(int i=n; i>=1; --i) 
	{
		LB[i]=LB[i+1],RB[i]=RB[i+1];
		if(R[i]<RB[i])
		{
			LB[i]=i,RB[i]=R[i];
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(RA[i]<n&&RB[RA[i]+1]<=n) print(LA[i],RA[i],LB[RA[i]+1],RB[RA[i]+1]);
	}
	for(int i=1; i<=n; ++i)
	{
		if(RB[i]<n&&RA[RB[i]+1]<=n) print(LA[RB[i]+1],RA[RB[i]+1],LB[i],RB[i]);
	}
	puts("No");
	return 0;
}