// Problem: Compressed Bracket Sequence
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1556/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int f[1003][1003],ff[1003][1003],s[1003][1003];
int a[1003];
signed main()
{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();	
		if(n==1)
		{
			puts("0");
			return 0;
		}
		if(n&1) --n;
	int c=0;
	for(int l=2; l<n; l+=2)
	{
		int g=0,ps=0;
		for(int r=l; r+1<n; r+=2)
		{
			g=max(g,ps+a[r]);
			ps+=a[r]-a[r+1];
			f[l][r+1]=g;
			s[l][r+1]=ps;
		}
	}
	for(int l=3; l<=n; l+=2)
	{
		int g=0,ps=0;
		for(int r=l; r-1>1; r-=2)
		{
			g=max(g,ps+a[r]);
			ps+=a[r]-a[r-1];
			ff[r-1][l]=g;
		}
	}
	for(int l=2; l<n; l+=2)
	{
		for(int r=l+1; r<n; r+=2)
		{
			if(s[l][r]>=0)
			{
			int A=f[l][r],B=ff[l][r];
			c+=max(0ll,min(a[l-1]-s[l][r],a[r+1])-max(A-s[l][r],B)+1);
			}
			else
			{
			int A=f[l][r],B=ff[l][r];
			c+=max(0ll,min(a[l-1],a[r+1]+s[l][r])-max(A,B+s[l][r])+1);
			}
		}
	}
	for(int i=1; i<n; i+=2) c+=min(a[i],a[i+1]);
	printf("%lld\n",c);
	return 0;
	
}