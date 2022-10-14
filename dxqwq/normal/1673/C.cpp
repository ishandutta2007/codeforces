// Problem: C. Palindrome Basis
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int ff(int x)
{
	vector<int> a;
	while(x) a.push_back(x%10),x/=10;
	vector<int> b=a;
	reverse(b.begin(),b.end());
	return a==b;
}
int f[100003];
signed main()
{
	f[0]=1;
	const int n=40000;
	for(int i=1; i<=n; ++i) if(ff(i))
	{
		for(int j=i; j<=n; ++j)
			f[j]=(f[j]+f[j-i])%p;
	}
	for(int T=read();T--;)
	{
		printf("%d\n",f[read()]);
	}
	return 0;
}