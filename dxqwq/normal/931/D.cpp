// Problem: D. Peculiar apple-tree
// Contest: Codeforces - Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
// URL: https://codeforces.com/contest/931/problem/D
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
int d[1000003];
int c[1000003];
signed main()
{
	int n=read();
	++c[0];
	int ans=0;
	for(int i=2; i<=n; i++) a[i]=read(),d[i]=d[a[i]]+1,++c[d[i]];
	for(int i=0; i<=1000000; i++) if(c[i]%2!=0)
	{
		++ans;
	}
	printf("%lld\n",ans);
    return 0;
}