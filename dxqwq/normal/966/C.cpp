// Problem: C. Big Secret
// Contest: Codeforces - Codeforces Round #477 (rated, Div. 1, based on VK Cup 2018 Round 3)
// URL: https://codeforces.com/contest/966/problem/C
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
int a[1000003],ans[1000003];
stack<int> s[103];
int highbit(int x)
{
	for(int i=60; i>=0; --i) if((1ll<<i)&x) return i;
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i) s[highbit(a[i])].push(a[i]);
	int S=0;
	int C=0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<=60; ++j) if((1ll<<j)&S)
		{
			C=C+1;
		}
		else if(!s[j].empty())
		{
			int A=s[j].top();
			s[j].pop();
			S^=A;
			ans[i]=A;
			break;
		}
		if(!ans[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
	return 0;
}