// Problem: C. Diluc and Kaeya
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/C
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
char s[1000003];
int a[1000003];
int b[1000003];
int ans[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		scanf("%s",s+1);
		for(int i=1; i<=n; ++i) ans[i]=1;
		map<pair<int,int>,int> mp;
		for(int i=1; i<=n; ++i)
		{
			a[i]=a[i-1],b[i]=b[i-1];
			if(s[i]=='D') ++a[i];
			else ++b[i];
			int s=__gcd(a[i],b[i]);
			printf("%lld ",++mp[make_pair(a[i]/s,b[i]/s)]);
		}
		puts("");
	}
	return 0;
}