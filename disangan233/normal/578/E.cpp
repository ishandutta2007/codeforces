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
}
using namespace fast_io;
#define pb push_back
#define pob pop_back
const int N=1e5+5;
int n,cnt;char s[N];vector<int>v[N],id[2],ve[2][2];
in void adj()
{
	if(!ve[0][0].size()||!ve[0][1].size()||ve[1][0].size()||ve[1][1].size()) return;
	int a=ve[0][0].back(),b=ve[0][1].back();
	if(v[a].back()<v[b].back()) v[a].pb(v[b].back()),v[b].pob(); else v[b].pb(v[a].back()),v[a].pob();
	ve[0][0].pob();ve[0][1].pob();ve[1][0].pb(b);ve[1][1].pb(a);
}
in void print(int x) {for(auto y:v[x]) write(y,' ');}
int main()
{
	n=gs(s+1);
	for(int i=1,c,t;i<=n;i++)
	{
		c=s[i]=='R';if(!id[c^1].size()) id[c^1].pb(++cnt);
		t=id[c^1].back();v[t].pb(i);id[c^1].pob(),id[c].pb(t);
	}
	write(cnt-1,'\n');
	for(int i=1;i<=cnt;i++) ve[v[i].size()&1][s[v[i].back()]=='R'].pb(i);
	adj();
	int t=(ve[1][0].size()^ve[1][1].size())?ve[1][1].size()>ve[1][0].size():ve[0][0].size()>ve[0][1].size();
	while(ve[0][t^1].size()) print(ve[0][t^1].back()),ve[0][t^1].pob();
	while(ve[1][t].size())
	{
		print(ve[1][t].back()),ve[1][t].pob();
		while(ve[0][t].size()) print(ve[0][t].back()),ve[0][t].pob();
		t^=1;
	}
	return ot(),0;
}
//Author: disangan233