// Problem: A. Elections
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/A
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
	int MX=0;
	for(int i=1; i<=n; ++i) a[i]=read(),MX=max(MX,a[i]);
	for(int A=MX; ; ++A)
	{
		int S=0,T=0;
		for(int i=1;i<=n; ++i)S+=a[i],T+=(A-a[i]);
		if(S<T) printf("%lld\n",A),exit(0);
	}
    return 0;
}