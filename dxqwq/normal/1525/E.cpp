// Problem: E. Assimilation IV
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/E
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
int a[23][100003];
int c[23];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=m; ++j) a[i][j]=read();
	int ans=m;
	int F=1;
	for(int i=1; i<=n; ++i) F=F*i%p;
	F=qp(F,p-2);
	for(int j=1; j<=m; ++j)
	{
		for(int i=1; i<=n; ++i)c[i]=a[i][j]-1;
		sort(c+1,c+n+1);
		int S=1;//S is failed count
		for(int i=1; i<=n; ++i) if(c[i]>=i)
		{
			S=S*(c[i]-i+1)%p;
		}
		else
		{
			S=0;
			break;
		}
		ans=(ans+p-(F*S%p))%p;
	}
	printf("%lld\n",ans);
	return 0;
}