// Problem: C. Strange Radiation
// Contest: Codeforces - Codeforces Round #425 (Div. 2)
// URL: https://codeforces.com/problemset/problem/832/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
int a[1000003],b[1000003],c[1000003];
pair<int,int> Make_pair(double x,double y)
{
	x=ceil(x),y=floor(y);
	return make_pair((int)x,(int)y);
}
signed main()
{
	int n=read(),s=read();
	for(int i=1; i<=n; ++i)
	{
		a[i]=read(),b[i]=read(),c[i]=read();
		if(c[i]==2) a[i]=1e6-a[i];
	}
	double l=0,r=1e6;
	while(r-l>=1e-9)
	{
		double mid=(l+r)*0.5;
#define pdd pair<int,int>
#define fi first
#define se second
		vector<pdd> vl,vr;
		for(int i=1; i<=n; ++i)
			if(c[i]==1)
			{
				if(1.0*a[i]/b[i]<=mid)
					vl.push_back(Make_pair(0,1e6));
				else if(1.0*a[i]/(b[i]+s)<=mid)
					vl.push_back(Make_pair(a[i],
					a[i]+(mid-1.0*a[i]/(s+b[i]))/
					(1.0/(s-b[i])-1.0*b[i]/(s*s-b[i]*b[i]))
					));
			}
			else
			{
				if(1.0*a[i]/b[i]<=mid)
					vr.push_back(Make_pair(0,1e6));
				else if(1.0*a[i]/(b[i]+s)<=mid)
					vr.push_back(Make_pair(a[i],
					a[i]+(mid-1.0*a[i]/(s+b[i]))/
					(1.0/(s-b[i])-1.0*b[i]/(s*s-b[i]*b[i]))
					));
			}
		// if(!vl.empty()) puts("A");
		// if(!vr.empty()) puts("B");
		for(auto &it:vr)
			swap(it.fi,it.se),
			it.fi=1e6-it.fi,
			it.se=1e6-it.se;
		sort(vl.begin(),vl.end()),
		sort(vr.begin(),vr.end());
		// printf("%.9lf\n",mid);
		// for(auto it:vl) printf("%.3lf %.3lf\n",it.fi,it.se);
		bool flg=0;
		auto il=vl.begin(),ir=vr.begin();
		while(il!=vl.end()&&ir!=vr.end())
			if(max(il->fi,ir->fi)<=min(il->se,ir->se))
			{flg=1;break;}
			else if(il->se<ir->fi) ++il; else ++ir;
		if(flg) r=mid; else l=mid;
	}
	printf("%.9lf\n",r);
	return 0;
}