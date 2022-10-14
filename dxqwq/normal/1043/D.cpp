// Problem: D. Mysterious Crime
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/D
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
int a[13][100003];
int F[13][100003];
int cur[13];
int tmp[13];
int L[13];
signed main()
{
	int n=read(),m=read();
	for(int j=1; j<=m; ++j)
	for(int i=1; i<=n; ++i) a[j][i]=read(),F[j][a[j][i]]=i;
	for(int i=1; i<=m; ++i) cur[i]=F[i][a[1][1]],L[i]=1;
	int ans=1;
	for(int r=2; r<=n; ++r)
	{
		for(int i=2; i<=m; ++i) tmp[i]=F[i][a[1][r]];
		for(int i=2; i<=m; ++i)if(tmp[i]!=cur[i]+1)
		{
			L[i]=r;
		}
		int l=1;
		for(int i=2; i<=m; ++i) l=max(l,L[i]),cur[i]=tmp[i];
		ans+=r-l+1;
	}
	printf("%lld\n",ans);
    return 0;
}