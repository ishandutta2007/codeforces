
// Problem: C. Travelling Salesman Problem
// Contest: Codeforces - Codeforces Round #712 (Div. 1)
// URL: https://codeforces.com/contest/1503/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
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
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
pii a[1000003];
int b[1000003];
int ans[1000003];
set<pair<pii,int> >s;
set<pii >s2; 
void add_new(int i)
{
	s.insert(mp(mp(a[i].fi+a[i].se,i),ans[i]-b[i]+a[i].se));
	s2.insert(mp(ans[i]-b[i]+a[i].se,i));
}
int getV(int x)
{
	return ans[x]-b[x]-a[x].fi;
}
signed main(){
	int n=read();
	for(int i=1; i<=n; i++) a[i].fi=read(),a[i].se=read();
	sort(a+1,a+n+1),ans[1]=a[n].se;
	for(int i=1; i<=n; i++) b[i]=b[i-1]+a[i].se;
	add_new(1);
	for(int i=2,mn=1e18; i<=n; i++)
	{
		while(1)
		{
			if(s.empty()) break;
			pair<pii,int> x=*s.begin();
			if(x.fi.fi-a[i].fi>0) break;
			s.erase(x);
			s2.erase(mp(x.se,x.fi.se));
			mn=min(mn,getV(x.fi.se));
		}
		if(!s2.empty()) 
		ans[i]=min(b[i-1]+(*s2.begin()).fi,b[i-1]+a[i].fi+mn);
		else ans[i]=b[i-1]+a[i].fi+mn;
		add_new(i);
	}
	printf("%lld\n",ans[n]);
	return 0;
}