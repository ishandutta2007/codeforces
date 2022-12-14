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
const int N=5e5+5,K=1e7+5,p=1e9+7;
int n,m,tot,ans,a[N],c[K],pw[N],g[K],pr[K/10],s[K],mu[K];bool v[K];
in void M(int &x) {x-=p;x+=x>>31&p;}
int main()
{
	n=read();pw[0]=1;for(int i=1;i<=n;i++) M(pw[i]=pw[i-1]<<1),c[a[i]=read()]++;
	m=*max_element(a+1,a+n+1);mu[1]=1;
	for(int i=2;i<=m;i++)
	{
		if(!v[i]) pr[++tot]=i,mu[i]=p-1;
		for(int j=1;j<=tot&&i*pr[j]<=m;j++)
		{
			v[i*pr[j]]=1;if(i%pr[j]==0) break;
			mu[i*pr[j]]=p-mu[i];
		}
	}
	for(int i=1;i<=tot;i++) for(int j=m/pr[i];j;j--) M(c[j]+=c[pr[i]*j]);
	for(int i=1;i<=m;i++) g[i]=1ll*c[i]*mu[i]%p;
	for(int i=1;i<=tot;i++) for(int j=1;pr[i]*j<=m;j++) M(g[pr[i]*j]+=g[j]);
	for(int i=1;i<=m;i++) M(s[i]=pw[c[i]]+p-1);
	for(int i=tot;i;i--) for(int j=1;pr[i]*j<=m;j++) M(s[j]+=p-s[pr[i]*j]);
	for(int i=m;i>1;i--) M(ans+=1ll*s[i]*g[i]%p);
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233