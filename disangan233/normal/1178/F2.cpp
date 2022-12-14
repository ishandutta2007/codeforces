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
const int N=1e3+5,K=3e6+5,p=998244353;
int n,m,q,a[K],l[K],r[K],f[N][N];
in void M(int &x) {x-=p;x+=x>>31&p;}
int main()
{
	n=read();q=read();memset(l,63,sizeof(l));
	for(int i=1,x;i<=q;i++) x=read(),x^a[m]?a[++m]=x:0;
	if(m>2*n) return write("0"),ot(),0;
	for(int i=1;i<=m;i++) l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
	for(int i=1;i<=m;i++) if(l[a[i]]==i&&r[a[i]]==i) f[i][i]=1;
	for(int i=0;i<=m;i++) f[i+1][i]=1;
	for(int L=2;L<=m;L++) for(int i=1;i<=m-L+1;i++)
	{
		int j=i+L-1,mn=i;
		for(int k=i+1;k<=j;k++) if(a[k]<a[mn]) mn=k;
		int x=l[a[mn]],y=r[a[mn]],s1=0,s2=0,pr=0;
		if(x<i||y>j) continue;
		for(int k=i;k<=x;k++) M(s1+=1ll*f[i][k-1]*f[k][x-1]%p);
		for(int k=y;k<=j;k++) M(s2+=1ll*f[y+1][k]*f[k+1][j]%p);
		f[i][j]=1ll*s1*s2%p;
		for(int k=i;k<=j;k++) if(a[k]==a[mn])
		{
			if(pr) f[i][j]=1ll*f[i][j]*f[pr+1][k-1]%p;
			pr=k;
		}
	}
	write(f[1][m],'\n'); 
	return ot(),0;
}
//Author: disangan233