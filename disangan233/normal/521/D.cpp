#pragma GCC optimize(2,3,"Ofast","unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
};
using namespace fast_io;
#define pb push_back
#define fi first
#define se second
const int N=1e5+5;
int n,m,k,a[N],b[N],t[N],j[N];
pair<int,int>p[N];vector<pair<int,int>>ad[N];vector<pair<long db,int>>ml;
int main()
{
	k=read(),n=read(),m=read();for(int i=1;i<=k;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		t[i]=read(),j[i]=read(),b[i]=read();
		if(t[i]==1) p[j[i]]=max(p[j[i]],make_pair(b[i],i));
		else if(t[i]==2) ad[j[i]].emplace_back(b[i],i);
		else ml.emplace_back(b[i],i);
	}
	for(int i=1;i<=k;i++) if(p[i].fi>a[i]) ad[i].emplace_back(p[i].fi-a[i],p[i].se);
	for(int i=1;i<=k;i++)
	{
		sort(ad[i].begin(),ad[i].end(),greater<pair<int,int>>());
		ll v=a[i];
		for(auto x:ad[i]) ml.emplace_back(1.0L*(v+x.fi)/v,x.se),v+=x.fi;
	}
	sort(ml.begin(),ml.end(),greater<pair<long db,int>>());
	int x=min(m,(int)ml.size());
	sort(ml.begin(),ml.begin()+x,[](auto x,auto y){return t[x.se]<t[y.se];});
	cout<<x<<endl;for(int i=0;i<x;i++) write(ml[i].se," \n"[i==x-1]);
	return ot(),0;
}
//Author: disangan233