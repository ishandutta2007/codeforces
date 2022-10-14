// Problem: B. A Perfectly Balanced String?
// Contest: Codeforces - Codeforces Round #785 (Div. 2)
// URL: https://codeforces.com/contest/1673/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
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
int a[26],A[26];
signed main()
{
	for(int T=read();T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		bool f=1;
		for(int i=0; i<26; ++i) A[i]=0;
		for(int i=1; i<=n; ++i) A[s[i]-'a']=1;
		for(int i=0; i<26; ++i)
		{
			for(int j=0; j<26; ++j) a[j]=0;
			int ss=n+1;
			for(int j=n; j>=1; --j) if(s[j]=='a'+i) ss=j;
			for(int j=ss+1; j<=n; ++j) 
			{
				++a[s[j]-'a'];
				if(s[j]=='a'+i)
				{
					for(int j=0; j<26; ++j) if(A[j])
					{if(!a[j]) f=0;
					else a[j]=0;}
				}
			}
		}
		if(f) puts("YES"); else puts("NO");
	}
	return 0;
}