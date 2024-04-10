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
	in db find() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
const int N=1e6+5;
ll n,k,a[N],b[N],c[N],p[N],q[N];
int main()
{
	n=read(),k=read();memset(p,63,sizeof(p));
	for(int i=1;i<=n;i++) {a[i]=read();if(p[a[i]]>1e9) p[a[i]]=i;q[a[i]]=i;}
	for(int i=1;i<=k;i++) c[i]=max(c[i-1],q[i]);
	b[k]=p[k],b[k+1]=1e9;for(int i=k-1;i;i--) b[i]=min(b[i+1],p[i]);
	ll r=k-1,ans=0;while(r&&q[r]<b[r+1]) r--;
	for(int l=1;l<=k;l++)
	{
		if(l>2&&p[l-1]<c[l-2]) break;
		while(r<=k&&(r<l||c[l-1]>b[r+1])) r++;
		ans+=k-r+1;
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233