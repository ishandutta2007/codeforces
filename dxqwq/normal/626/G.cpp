// Problem: G. Raffles
// Contest: Codeforces - 8VC Venture Cup 2016 - Elimination Round
// URL: https://codeforces.com/problemset/problem/626/G
// Memory Limit: 256 MB
// Time Limit: 5000 ms
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
int p[1000003],l[1000003],a[1000003];
double F(int x,int y)
{
	return p[x]*(1.0*y/(l[x]+y)-1.0*(y-1)/(l[x]+y-1));
}
struct cmp0{bool operator()(const int&x,const int&y)const{
	return (F(x,a[x])<F(y,a[y]))
	||(F(x,a[x])==F(y,a[y])&&x<y);
}};
struct cmp1{bool operator()(const int&x,const int&y)const{
	return (F(x,a[x]+1)>F(y,a[y]+1))
	||(F(x,a[x]+1)==F(y,a[y]+1)&&x<y);
}};
set<int,cmp0> s0;
set<int,cmp1> s1;
double ans=0;
double getmn()
{
	if(s0.empty()) return 1e9;
	int x=*s0.begin();
	return F(x,a[x]);
}
double getmx()
{
	if(s1.empty()) return -1e9;
	int x=*s1.begin();
	return F(x,a[x]+1);
}
void delmn()
{
	int t=*s0.begin();
	if(a[t]!=l[t]) s1.erase(t);
	s0.erase(t);
	ans-=F(t,a[t]--);
	if(a[t]) s0.insert(t);
	s1.insert(t);
	return ;
}
void insmx()
{
	int t=*s1.begin();
	if(a[t]) s0.erase(t);
	s1.erase(t);
	ans+=F(t,++a[t]);
	if(a[t]!=l[t]) s1.insert(t);
	s0.insert(t);
	return ;
}
signed main()
{
	int n=read(),m=read(),q=read();
	for(int i=1; i<=n; ++i) p[i]=read();
	for(int i=1; i<=n; ++i) l[i]=read();
	for(int i=1; i<=n; ++i) s1.insert(i);
	for(int x,y; q--;)
	{
		y=read(),x=read();
		auto it0=s0.find(x);
		if(it0!=s0.end()) s0.erase(it0);
		auto it1=s1.find(x);
		if(it1!=s1.end()) s1.erase(it1);
		ans-=1.0*p[x]*a[x]/(a[x]+l[x]);
		if(y==1) ++l[x]; else --l[x];
		int t=min(a[x],l[x]);
		m+=a[x]-t,a[x]=t,ans+=1.0*p[x]*a[x]/(a[x]+l[x]);
		if(l[x]!=a[x]) s1.insert(x);
		if(a[x]) s0.insert(x); 
		while(!s1.empty()&&m) insmx(),--m;
		while(getmx()>getmn()) delmn(),insmx();
		printf("%.10lf\n",ans);
	}
	return 0;
}