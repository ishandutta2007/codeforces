#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
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
#define pb push_back
const int N=55,M=1e6+5;
int n,m,tot,a[N],c[M],f[N][M],g[N][3],s[N][M];
int main()
{
	n=read(),m=2*n;for(int i=1;i<=m;i++) tot+=(a[i]=read());
	sort(a+1,a+m+1);g[1][1]=a[1],g[n][2]=a[2],tot=(tot-a[1]-a[2])/2;
	f[0][0]=1;n--;for(int i=3;i<=m;i++) c[a[i]]++;
	for(int i=3;i<=m;i++) for(int j=min(n,i);j;j--) for(int k=tot;k>=a[i];k--) 
	if(!f[j][k]&&f[j-1][k-a[i]]) s[j][k]=a[i],f[j][k]=1;
	for(int i=tot;~i;i--) if(f[n][i])
	{
		int k=n,x=i;for(int j=1;j<=n;j++) c[g[j][2]=s[k][x]]--,x=x-s[k--][x];
		k=1;for(int j=0;j<=a[m];j++) while(c[j]) c[g[++k][1]=j]--;
		for(int i=1;i<=n+1;i++) write(g[i][1]," \n"[i==n+1]);
		for(int i=1;i<=n+1;i++) write(g[i][2]," \n"[i==n+1]);
		break;
	}
	return ot(),0;
}
//Author: disangan233