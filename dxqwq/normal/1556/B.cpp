// Problem: B. Take Your Places!
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/B
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
int a[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),A=0;
		for(int i=1; i<=n; ++i) a[i]=read()%2,A+=(a[i]==1);
		int B=n-A;
		if(abs(A-B)>1)
		{
			puts("-1");
			continue;
		}
		else if(A==B)
		{
			int s1=0,pa=1,pb=2;
			for(int i=1; i<=n; ++i) if(a[i]) s1+=abs(pa-i),pa+=2;
			else s1+=abs(pb-i),pb+=2;
			int s2=0;pa=2,pb=1;
			for(int i=1; i<=n; ++i) if(a[i]) s2+=abs(pa-i),pa+=2;
			else s2+=abs(pb-i),pb+=2;
			printf("%lld\n",min(s1,s2)/2);
		}
		else if(A>B)
		{
			int s1=0,pa=1,pb=2;
			for(int i=1; i<=n; ++i) if(a[i]) s1+=abs(pa-i),pa+=2;
			else s1+=abs(pb-i),pb+=2;
			printf("%lld\n",s1/2);
		}
		else
		{
			int s1=0,pa=2,pb=1;
			for(int i=1; i<=n; ++i) if(a[i]) s1+=abs(pa-i),pa+=2;
			else s1+=abs(pb-i),pb+=2;
			printf("%lld\n",s1/2);
		}
		
	}
	return 0;
}