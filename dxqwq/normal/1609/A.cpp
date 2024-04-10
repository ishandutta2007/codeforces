// Problem: A. Divide and Multiply
// Contest: Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[10003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),s=0;
		for(int i=1; i<=n; ++i) 
		{
			a[i]=read();
			while((a[i]&1)==0
			) a[i]>>=1,++s;
		}
		sort(a+1,a+n+1);
		for(int i=1; i<=s; ++i) a[n]<<=1;
		int S=0;
		for(int i=1; i<=n; ++i) S+=a[i];
		printf("%lld\n",S);
	}
	return 0;
}