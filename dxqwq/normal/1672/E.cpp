// Problem: E. notepad.exe
// Contest: Codeforces Global Round 20
// URL: https://codeforces.com/contest/1672/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int query(int x)
{
	printf("? %lld\n",x);fflush(stdout);
	return read();
}
void answer(int x)
{
	printf("! %lld\n",x);fflush(stdout);
	exit(0);
	return ;
}
signed main()
{
	int n=read();
	int l=1,r=5000000,res=5000001;
	int ans=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		int c=query(mid);
		if(c!=0) ans=min(ans,c*mid);
		if(c>1||c==0) l=mid+1;
		else res=mid,r=mid-1;
	}
	for(int i=1; i<=n; ++i)
	{
		int d=res/i,c=query(d);
		if(c!=0) ans=min(ans,c*d);
	}
	answer(ans);
	return 0;
}