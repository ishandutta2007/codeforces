// Problem: E. Gerald and Path
// Contest: Codeforces - Codeforces Round #313 (Div. 1)
// URL: https://codeforces.com/problemset/problem/559/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
pair<int,int> a[103];
int f[103][103][2];
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i].first=read(),a[i].second=read();
	sort(a+1,a+n+1);
	a[0].first=-1e9;
	for(int i=0; i<n; ++i)
		for(int j=0; j<=i; ++j)
			for(int k=0; k<=1; ++k)
				for(int l=i+1,mx=(a[j].first+a[j].second*k),tx=j,ty=k; l<=n; ++l)	
				{
					int tmx=mx,ttx=tx,tty=ty;
					(a[l].first>tmx)&&(tmx=a[l].first,ttx=l,tty=0);
					f[l][ttx][tty]=max(f[l][ttx][tty],f[i][j][k]+tmx-max(a[j].first+a[j].second*k,a[l].first-a[l].second));
					(a[l].first+a[l].second>mx)&&(mx=a[l].first+a[l].second,tx=l,ty=1);
					f[l][tx][ty]=max(f[l][tx][ty],f[i][j][k]+mx-max(a[j].first+a[j].second*k,a[l].first));
				}
	int ans=0;
	for(int i=0; i<=n; ++i)
		for(int j=0; j<=n; ++j)
			for(int k=0; k<=1; ++k)
				// (f[i][j][k]>ans)&&(printf("%d %d %d\n",i,j,k)),
				ans=max(ans,f[i][j][k]);
	printf("%lld\n",ans);
	return 0;
}