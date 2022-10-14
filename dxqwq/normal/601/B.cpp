// Problem: B. Lipshitz Sequence
// Contest: Codeforces Round #333 (Div. 1)
// URL: https://codeforces.com/contest/601/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003],b[1000003];
int ld[1000003],rd[1000003];
signed main()
{
	int n=read(),q=read();
	for(int i=1; i<=n; ++i) b[i]=read();
	for(int i=1; i<n; ++i) a[i]=abs(b[i]-b[i+1]);
	a[0]=a[n+1]=1e18;
	stack<int> st;
	st.push(0);
	for(int i=1; i<=n; ++i)
	{
		while(a[st.top()]<a[i]) st.pop();
		ld[i]=st.top();
		st.push(i);
	}
	while(!st.empty()) st.pop();
	st.push(n+1);
	for(int i=n; i>=1; --i)
	{
		while(a[st.top()]<=a[i]) st.pop();
		rd[i]=st.top();
		st.push(i);
	}
	for(int l,r; q--;)
	{
		l=read(),r=read()-1;
		int ans=0;
		// for(int i=l; i<=r; ++i)
			// for(int j=i,s=0; j<=r; ++j)
			// {
				// s=max(a[j],s);
				// ans+=s;
			// }
		for(int i=l; i<=r; ++i)
			ans+=a[i]*max(0ll,min(rd[i]-1,r)-i+1)*max(0ll,i-max(ld[i]+1,l)+1);
		printf("%lld\n",ans);
	}
	return 0;
}