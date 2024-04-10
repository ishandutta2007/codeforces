// Problem: B. Jumps
// Contest: Codeforces - Educational Codeforces Round 99 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1455/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		int l=1,r=1e9,ans=0;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(mid*(mid+1)/2<n) l=mid+1;
			else ans=mid,r=mid-1;
		}
		int A=ans*(ans+1)/2;
		printf("%lld\n",ans+(A-n==1));
	}
	return 0;
}