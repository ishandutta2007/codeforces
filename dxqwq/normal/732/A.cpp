// Problem: A. Buy a Shovel
// Contest: Codeforces - Codeforces Round #377 (Div. 2)
// URL: https://codeforces.com/contest/732/problem/A
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

signed main()
{
	int n=read(),m=read();
	int g=0,p=0;
	while(1)
	{
		g+=n,p++;
		if(g%10==m||g%10==0) printf("%lld\n",p),exit(0);
	}
    return 0;
}