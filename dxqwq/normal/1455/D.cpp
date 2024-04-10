// Problem: D. Sequence and Swaps
// Contest: Codeforces - Educational Codeforces Round 99 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1455/problem/D
// Memory Limit: 512 MB
// Time Limit: 1500 ms
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
int a[100003],s[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),x=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		s[n+1]=1e12;
		for(int i=n; i>=1; --i) s[i]=min(a[i],s[i+1]);
		int ans=0,lst=-1;
		for(int i=1; i<=n; ++i) 
		{
			if(a[i]>x&&lst==-1)
			{
				lst=i;
			}
			if(s[i]!=a[i])
			{
				if(x>s[i])
				{
					ans=-1;
					break;
				}
				else
				{
					if(lst==-1)
					{
						ans=-1;
						break;
					}
					for(int j=i; j>lst; --j) if(a[j]==a[j-1]) --ans;
					ans+=i-lst+1,lst=-1;
					x=a[i];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}