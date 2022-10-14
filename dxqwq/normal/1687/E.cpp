// Problem: E. Become Big For Me
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1687/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
bool vis[1000003],flg[1000003];
int a[1000003],A[1000003];
const int N=1e6;
#define ll long long
ll work(int x)
{
	ll res=0;
	for(int i=0; i<15; ++i) if(i!=x)
		for(int j=i; j<15; ++j) if(j!=x)
			res=__gcd(res,1ll*A[a[i]]*A[a[j]]);
	return res;
}
signed main()
{
	int n=read(),m=0;
	for(int i=1; i<=n; ++i) A[i]=a[i]=read();
	bool empty_check=1;
	for(int i=2; i<=N; ++i) if(!vis[i])
	{
		int f1=114,f2=514,p1=-1,p2=-1;
		for(int j=1,t; f2&&j<=n; ++j) 
		{
			for(t=0; a[j]%i==0; ++t,a[j]/=i);
			if(t<f1) p2=p1,f2=f1,p1=j,f1=t;
			else if(t<f2) p2=j,f2=t;
		}
		if(f2) empty_check=0;
		flg[p1]=flg[p2]=1;
		for(int j=2; i*j<=N; ++j) vis[i*j]=1;
	}
	if(empty_check) puts("0"),exit(0);
	for(int i=1; i<=n; ++i) if(flg[i]) a[m++]=i;
	if(m==15)
	{
		ll A=work(15);
		for(int i=0; i<15; ++i)
			if(work(i)==work(15))
			{
				for(int j=i; j<14; ++j) a[j]=a[j+1];
				--m;
				break;
			}
	}
	assert(m<=14),n=m,m=1<<m;
	vector<vector<int>> ans;
	for(int i=1; i<m; ++i)
	{
		int o=__builtin_popcount(i)-2;
		(o&1)&&(o=-o);
		if(o>=0) for(int T=1; T<=o; ++T)
		{
			vector<int> tmp;
			tmp.push_back(0),tmp.push_back(__builtin_popcount(i));
			for(int j=0; j<n; ++j)
				if((i>>j)&1) tmp.push_back(a[j]);
			ans.push_back(tmp);
		}
		else for(int T=1; T<=-o; ++T)
		{
			vector<int> tmp;
			tmp.push_back(1),tmp.push_back(__builtin_popcount(i));
			for(int j=0; j<n; ++j)
				if((i>>j)&1) tmp.push_back(a[j]);
			ans.push_back(tmp);
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto i:ans)
	{
		for(int j:i) printf("%d ",j);
		puts("");
	}
	return 0;
}