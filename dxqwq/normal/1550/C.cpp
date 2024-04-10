// Problem: C. Manhattan Subarrays
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/C
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i)
		{
			a[i]=read();
		}
		int ans=n;
		for(int i=1; i<=n; ++i)
		{
			for(int j=i+1; j<=n; ++j)
			{
				bool f=1;
				for(int k=i; k<j; ++k)
					for(int l=k+1; l<j; ++l)
					{
						if(a[k]<=a[l]&&a[l]<=a[j]) f=0;
						if(a[k]>=a[l]&&a[l]>=a[j]) f=0;
					}
				if(!f) break;
				++ans;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}