// Problem: B. Maximum Cost Deletion
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/B
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
char s[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read(),k=read();
		scanf("%s",s+1);
		if(k>=0)
		printf("%lld\n",n*(m+k));
		else
		{
			int c=1;
			for(int i=2; i<=n; ++i) if(s[i]!=s[i-1]) ++c;
			printf("%lld\n",n*m+(c/2+1)*k);
		}
	}
	return 0;
}