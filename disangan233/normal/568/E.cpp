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
const int N=1e5+5;
int n,m,a[N],b[N],f[N],g[N],l[N],p[N],v[N],ans[N];
in int find(int x) {return lower_bound(b+1,b+m+1,x)-b-1;}
int main()
{
	n=read();for(int i=1;i<=n;i++) a[i]=read();a[++n]=1e9;
	m=read();for(int i=1;i<=m;i++) b[i]=read();sort(b+1,b+m+1);
	memset(f+1,63,4*n);
	for(int i=1;i<=n;i++)
	{
		if(~a[i])
		{
			int j=lower_bound(f+1,f+n+1,a[i])-f-1;
			l[i]=j+1,p[i]=g[j],f[j+1]=a[i],g[j+1]=i;
		}
		else
		{
			for(int x=m,j=n;x;x--) {while(f[j]>=b[x]) j--;f[j+1]=b[x],g[j+1]=i;}
		}
	}
	for(int len=l[n],pos=n,val=a[n];len;--len)
	{
		if(~a[pos])
		{
			if(~a[p[pos]]) pos=p[pos],val=a[pos];
			else {int t=find(a[pos]);v[t]=1,pos=p[pos],val=ans[pos]=b[t];}
		}
		else
		{
			int op=0;for(int k=pos-1;k;k--) if(~a[k]&&a[k]<val&&l[k]==len-1) {pos=k,val=a[k];op=1;break;}
			if(op) continue;
			for(int k=pos-1;k;k--) if(!~a[k]) {int t=find(val);v[t]=1;pos=k,val=ans[pos]=b[t];break;}
		}
	}
	for(int i=1,j=1;i<=n;i++)
	if(~a[i]) ans[i]=a[i];
	else if(!ans[i]) {while(v[j])j++;v[j]=1,ans[i]=b[j];}
	for(int i=1;i<n;i++) write(ans[i]," \n"[i==n-1]);
	return ot(),0;
}
//Author: disangan233