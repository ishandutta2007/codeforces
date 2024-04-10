// Problem: B. Lost Array
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// zhoukangyang 
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
int a[1000003];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	int C=0;
	for(int i=1; i<=n; ++i)
	{int f=1;
		for(int j=1; j<=i; ++j)
		for(int k=i+j; k<=n; k+=i)
		if(a[k]-a[k-1]!=a[j]-a[j-1]) f=0;
		if(f) ++C;
	}
	printf("%lld\n",C);
	for(int i=1; i<=n; ++i)
	{int f=1;
		for(int j=1; j<=i; ++j)
		for(int k=i+j; k<=n; k+=i)
		if(a[k]-a[k-1]!=a[j]-a[j-1]) f=0;
		if(f)printf("%lld ",i);
	}
    return 0;
}