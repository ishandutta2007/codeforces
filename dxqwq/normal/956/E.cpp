// Problem: E. Wardrobe
// Contest: Codeforces - Codeforces Round #472 (rated, Div. 1, based on VK Cup 2018 Round 2)
// URL: https://codeforces.com/contest/956/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int f[10003];
int a[10003],b[10003];
int c[10003];
signed main()
{
	memset(f,-1,sizeof(f));
	f[0]=0;
	int n=read(),l=read(),r=read();
	int s=0;
	for(int i=1; i<=n; ++i) a[i]=read(),s+=a[i];
	for(int i=1; i<=n; ++i) b[i]=read();
	vector<int> v,vv;
	for(int i=1; i<=n; ++i) if(!b[i])
		vv.push_back(a[i]);
	else v.push_back(a[i]);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	r=s-r,l=s-l;
	swap(l,r);
	//printf("%d %d\n",l,r);
	for(int i:vv)
	{
		for(int j=r; j>=i; --j)
			(f[j-i]==0)&&(f[j]=0);
	}
	for(int i:v)
	{
		for(int j=r; j>=l&&j>=i; --j)
			(f[j-i]!=-1)&&(f[j]=max(f[j],f[j-i]+1));
		for(int j=l-1; j>=i; --j)
			(f[j-i]==0)&&(f[j]=0);
	}
	int g=0;
	for(int i=l; i<=r; ++i) g=max(g,f[i]);
	printf("%d\n",g);
	return 0;
}