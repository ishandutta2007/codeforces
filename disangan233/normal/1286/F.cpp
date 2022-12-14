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
const int N=1<<20;
int n,ans[N],siz[N],vis[N];ll a[N],s[N];
int main()
{
	n=read();for(int i=0;i<n;i++) if(!(a[i]=read())) n--,i--;
	int tot=1<<n;
	for(int i=0;i<tot;i++) for(int j=0;j<n;j++) if(i&(1<<j)) s[i]+=a[j];
	for(int i=0;i<tot;i++)
	{
		siz[i]=siz[i>>1]+(i&1);
		for(int j=(i-1)&i;j&&(j<<1)>=i;j=(j-1)&i)
		{
			int t=i^j;ll d=abs(s[j]-s[t]);
			if(d<siz[i]&&(siz[i]-d)&1) {vis[i]=1;break;}
		}
	}
	for(int i=1;i<tot;i++) if(vis[i])
	{
		ans[i]=max(ans[i],1);int t=(tot-1)^i;
		for(int j=t;j;j=(j-1)&t) ans[i|j]=max(ans[i|j],ans[j]+1);
	}
	write(n-*max_element(ans+1,ans+tot),'\n');
	return ot(),0;
}
//Author: disangan233