#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;Ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)Ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*Ny;
	}
	in db gf() {int a=read(),y=Ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+5;
int n,a[N],b[N],tot,op;
vector<int>s[N],ans[N];
in void rev(int l,int r)
{
	if(l==1&&r==n) return; op^=1;ans[++tot].clear();
	for(int i=1;i<=n;i++) s[i].clear();
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=l||i>r) res++,ans[tot].pb(0);
		s[res].pb(a[i]),ans[tot].back()++;
	}
	reverse(s+1,s+res+1);res=0;
	for(int i=1;i<=n;i++) for(int x:s[i]) a[++res]=x;
}
int main()
{
	n=read();for(int i=1;i<=n;i++) a[i]=read();
	if(n==1) return write("0"),ot(),0;
	if(n&1) {for(int i=1;i<=n;i++)if(a[i]==1){rev(i,n);break;}}
	else {for(int i=1;i<=n;i++)if(a[i]==1){rev(1,i);break;}}
	op=n&1;
	for(int i=2;i<=n;i++)
	{
		if(op) {for(int j=1;j<=n;j++)if(a[j]==i){rev(i,j);break;}}
		else {for(int j=1;j<=n;j++)if(a[j]==i){rev(j,n-i+1);break;}}
	}
	write(tot,'\n');
	for(int i=1;i<=tot;i++)
	{
		write((int)ans[i].size(),' ');
		for(int x:ans[i]) write(x,' ');
		sr[++C]='\n';
	}
	return ot(),0;
}
//Author: disangan233