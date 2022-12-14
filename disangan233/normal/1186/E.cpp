#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
#define ld long db
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
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define cnt __builtin_popcountll
const int N=1e3+5;
ll n,m,q,a[N][N],s[N][N];char ch[N];
in bool rev(ll x,ll y){return (cnt(x-1)+cnt(y-1))&1;}
in ll ask(ll x,ll y)
{
	if(!x||!y) return 0;
	ll fx=(x+n-1)/n,fy=(y+m-1)/m,ans=(fx-1)*(fy-1)/2*n*m,gx=x-n*(fx-1),gy=y-m*(fy-1);
	if(!(fx&1)&&!(fy&1)) ans+=rev(fx-1,fy-1)?n*m-s[n][m]:s[n][m];
	ans+=(fx-1)/2*n*gy;
	if(!(fx&1)) ans+=rev(fx-1,fy)?n*gy-s[n][gy]:s[n][gy];
	ans+=(fy-1)/2*m*gx;
	if(!(fy&1)) ans+=rev(fx,fy-1)?m*gx-s[gx][m]:s[gx][m];
	ans+=rev(fx,fy)?gx*gy-s[gx][gy]:s[gx][gy];
	return ans;
}
int main()
{
	n=read(),m=read(),q=read();
	for(int i=1;i<=n;i++) {gs(ch+1);for(int j=1;j<=m;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(a[i][j]=ch[j]-'0');}
	while(q--)
	{
		ll a=read(),b=read(),c=read(),d=read();
		write(ask(a-1,b-1)+ask(c,d)-ask(a-1,d)-ask(c,b-1),'\n'); 
	}
	return ot(),0;
}
//Author: disangan233