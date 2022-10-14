// Problem: E. Fixed Points
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/E
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
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int a[2003];
int f[2003][2003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=1; i<=n; ++i)
			for(int j=1; j<=i; ++j)
				f[i][j]=0;
		for(int i=1; i<=n; ++i)
		{
			f[i][1]=max(f[i-1][1],(int)(a[i]==1));
			for(int j=2; j<=i; ++j)
				f[i][j]=max(f[i-1][j-1]+(a[i]==j),f[i-1][j]);
		}
		bool F=0;
		for(int i=n; i>=1; --i) if(f[n][i]>=k)
		{
			printf("%lld\n",n-i);
			F=1;
			break;
		}
		if(!F) puts("-1");
		//ij
	}
	return 0;
}