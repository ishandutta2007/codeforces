// Problem: A. Maximum splitting
// Contest: Codeforces - Codeforces Round #440 (Div. 1, based on Technocup 2018 Elimination Round 2)
// URL: https://codeforces.com/contest/871/problem/A
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

signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		if(n&1)
		{
			if(n==9) puts("1");
			else 
			if(n<=11) puts("-1");
			else
			{
				//4 4 4 4 9
				printf("%lld\n",(n-9)/4+1);
			} 
		}
		else
		{
			if(n<=3) puts("-1");
			else printf("%lld\n",n/4);
		}
	}
	return 0;
}