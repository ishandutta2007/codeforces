#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1) if(nc==45) y=-1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58) x=(x<<3)+(x<<1)+(nc^48);return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=1e3+5;
int n,m,K,a[N],b[N],fa[N],f[N];
vector<int>q[N];
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
in void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x^y) fa[x]=y;
}
int main()
{
	n=read(),m=read(),K=read();memset(f,-63,sizeof(f)),f[0]=0;
	for(int i=1;i<=n;i++) fa[i]=i,a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=m;i++) merge(read(),read());
	for(int i=1;i<=n;i++) q[find(i)].push_back(i);
	for(int i=1;i<=n;i++) if(q[i].size())
	for(int j=K;~j;j--)
	{
		int sa=0,sb=0;
		for(auto k:q[i]) sa+=a[k],sb+=b[k],j>=a[k]?f[j]=max(f[j],f[j-a[k]]+b[k]):0;
		if(j>=sa) f[j]=max(f[j],f[j-sa]+sb);
	}
	int ans=0;for(int i=1;i<=K;i++) ans=max(ans,f[i]);
	write(ans,'\n');
	return ot(),0;
}