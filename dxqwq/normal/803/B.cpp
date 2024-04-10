// Problem: B. Distances to Zero
// Contest: Codeforces - Educational Codeforces Round 20
// URL: https://codeforces.com/contest/803/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int d[1000003];
signed main()
{
	int n=read();
	memset(d,0x3f,sizeof(d));
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1,lst=-10000000; i<=n; i++) 
	{
		if(!a[i])lst=i;
		d[i]=min(d[i],i-lst);
	}
	for(int i=n,lst=10000000; i>=1; i--) 
	{
		if(!a[i])lst=i;
		d[i]=min(d[i],lst-i);
	}
	for(int i=1; i<=n; i++) printf("%lld ",d[i]);
	puts("");
    return 0;
}