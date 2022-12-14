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
	in ll read()
	{
		ll x=0;Ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)Ny=-1;Bi=1;if(nc<0)return nc;
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
const int N=1e6+5;
int t,n,m,mex,a[N],l[N],r[N],q[N],p[N],vis[N];
char s[N];
void get()
{
	memset(vis,0,4*(n+3));for(int i=1;i<=n;i++) vis[a[i]]++;
	for(int i=0;i<=n;i++) if(!vis[i]) return mex=i,void();
}
int check()
{
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) return 0;
	return 1;
}
int main()
{
	t=read();
	while(t--)
	{
		n=read();m=0;int mx=0;
		for(int i=1;i<=n;i++) a[i]=read();
		while(!check())
		{
			get();
			if(mex==n)
			{
				for(int i=1;i<=n;i++) p[a[i]]=i;
				for(int i=n-1;~i;i--) if(p[i]^(i+1)) {q[++m]=p[i],a[p[i]]=mex;break;}
			}
			else q[++m]=mex+1,a[mex+1]=mex;
		}
		for(int i=n;i>1;i--) if(a[i]<a[i-1]) a[i]=n+1,q[++m]=i;
		write(m,'\n');for(int i=1;i<=m;i++) write(q[i]," \n"[i==m]);if(m==0) sr[++C]='\n';
	}
	return ot(),0;
}
//Author: disangan233