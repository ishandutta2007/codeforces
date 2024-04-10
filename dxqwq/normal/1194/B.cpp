// Problem: B. Yet Another Crosses Problem
// Contest: Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1194/problem/B
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
string s[100003];
int a[100003],b[100003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=0; i<m; ++i) b[i]=0;
		for(int i=1; i<=n; ++i) cin>>s[i],a[i]=0;
		int ans=9999999;
		for(int i=1; i<=n; ++i) 
		{
			for(int j=0; j<m; ++j) a[i]+=(s[i][j]=='.'),b[j]+=(s[i][j]=='.');
		}
		for(int i=1; i<=n; ++i)for(int j=0; j<m; ++j)
		ans=min(ans,a[i]+b[j]-(s[i][j]=='.'));
		printf("%lld\n",ans);
	}
    return 0;
}