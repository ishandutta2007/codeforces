// Problem: E. Arranging The Sheep
// Contest: Codeforces - Codeforces Round #719 (Div. 3)
// URL: https://codeforces.com/contest/1520/problem/E
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
char s[1000003];
int b[1000003];
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s+1);
		int ans=1e15;
		int c=0,ss=0;
		for(int i=1; i<=n; ++i)
		{
			ss+=c;
			if(s[i]=='*') ++c;
			a[i]=ss-c*(c-1)/2;
		}
		c=0,ss=0;
		for(int i=n; i>=1; --i)
		{
			ss+=c;
			if(s[i]=='*') ++c;
			b[i]=ss-c*(c-1)/2;
		}
		for(int i=0; i<=n; ++i) ans=min(ans,a[i]+b[i+1]);
		printf("%lld\n",ans);
	}
	return 0;
}