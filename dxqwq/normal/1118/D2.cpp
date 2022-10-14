// Problem: D2. Coffee and Coursework (Hard Version)
// Contest: Codeforces - Codeforces Round #540 (Div. 3)
// URL: https://codeforces.com/contest/1118/problem/D2
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
int a[1000003];
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
bool cmp(int x,int y){return x>y;}
int n=read(),m=read();
bool check(int x)
{
	int s=0;
	for(int i=0; i<n; ++i)
	{
		s+=max(0ll,a[i]-(i/x));
	}
	return s>=m;
}
signed main()
{
	
	for(int i=0; i<n; ++i) a[i]=read();
	sort(a,a+n,cmp);
	int l=1,r=n,ans=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}