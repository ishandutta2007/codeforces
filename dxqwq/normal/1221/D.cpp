// Problem: D. Make The Fence Great Again
// Contest: Codeforces - Educational Codeforces Round 73 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1221/problem/D
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
int a[1000003],b[1000003];
int f[1000003][4];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read(),b[i]=read();
		for(int i=1; i<=n; ++i) 
		for(int j=0; j<4; ++j) 
		for(int k=0; k<4; ++k) f[i][j]=0x3f3f3f3f3f3f3f3f;
		a[0]=-100;
		for(int i=1; i<=n; ++i) 
		for(int j=0; j<4; ++j) 
		for(int k=0; k<4; ++k) if(a[i-1]+j!=a[i]+k)
		f[i][k]=min(f[i][k],f[i-1][j]+k*b[i]);
		int ans=0x3f3f3f3f3f3f3f3f;
		for(int i=0; i<4; ++i) ans=min(ans,f[n][i]);
		printf("%lld\n",ans);
	}
    return 0;
}