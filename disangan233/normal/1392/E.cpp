#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	// in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	#define gc getchar
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
#define pii pair<int,int>
#define fi first
#define se second
const int N=26;
int n,q,o[123456][2],tot;ll a[N][N],b[N][N];
in void dfs(int x,int y,ll s)
{
	o[++tot][0]=x,o[tot][1]=y;if(x==n&&y==n) return;
	if(x==n) return dfs(x,y+1,s); if(y==n) return dfs(x+1,y,s);
	s-=a[x][y];s<=b[x][y+1]?dfs(x,y+1,s):dfs(x+1,y,s);
}
int main()
{
	n=read();for(int i=2;i<=n;i++) a[i][n-1]=1;
	for(int j=n-2;j;j--) for(int i=2;i<=n;i++)
	{
		ll s=1;
		for(int k=i-1;k<=n;k++) s+=a[k][j+1];
		for(int k=j+2;k<=n;k++) s+=a[n][k];
		for(int k=j+1;k<=n;k++) s-=a[i][k];
		for(int k=i+1;k<=n;k++) s-=a[k][n];
		a[i][j]=s;
	}
	for(int i=n;i;i--) b[n][i]=b[n][i+1]+a[n][i];
	for(int i=n-1;i;i--) for(int j=1;j<=n;j++) b[i][j]=b[i+1][j]+a[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%lld",a[i][j]),putchar(" \n"[j==n]);
	fflush(stdout);q=read();
	while(q--)
	{
		ll x=read();tot=0;dfs(1,1,x);
		for(int i=1;i<=tot;i++) printf("%d %d\n",o[i][0],o[i][1]);
		fflush(stdout);
	}
	return ot(),0;
}
//Author: disangan233