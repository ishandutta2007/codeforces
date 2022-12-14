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
const int N=1e3+5;
int n,vis[N],w[N],cnt,can=1;bitset<N>a[N],b[N],e[N];
int main()
{
	n=read();if(n==2) return write("1 2"),ot(),0;
	for(int i=1;i<=n;i++) {int k=read();can&=k==n;for(int j=1;j<=k;j++) a[i][read()]=1;}
	if(can) {for(int i=1;i<n;i++) write(i,' '),write(n,'\n');return ot(),0;}
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		bitset<N>b=a[i]&a[j];if(b.count()!=2) continue;
		int x=b._Find_first(),y=b._Find_next(x); if(e[x][y]) continue;
		write(x,' '),write(y,'\n');e[x][y]=e[y][x]=vis[x]=vis[y]=1;
	}
	for(int i=1;i<=n;i++)
	if(!vis[i])
	{
		int s=n+1,p=0;for(int j=1,c;j<=n;j++) if(!w[j]&&a[j][i]) c=a[j].count(),c<s?(s=c,p=j):0;
		b[i]=a[p],w[p]=1;
	}
	else e[i][i]=1,cnt++;
	if(cnt==2)
	{
		int x,y;
		for(int i=1;i<=n;i++) if(vis[i]) x=i;
		for(int i=n;i;i--) if(vis[i]) y=i;
		for(int i=1;i<=n;i++) if((int)a[i].count()^n)
		{for(int j=1;j<=n;j++) if(!vis[j]) a[i][j]?write(x,' '):write(y,' '),write(j,'\n');break;}
		return ot(),0;
	}
	for(int i=1;i<=n;i++) if(!vis[i])
	{
		for(int j=1;j<=n;j++) if(!vis[j]) b[i][j]=0;
		for(int j=1;j<=n;j++) if(vis[j]&&b[i]==e[j]) {write(i,' '),write(j,'\n');break;}
	}
	return ot(),0;
}
//Author: disangan233