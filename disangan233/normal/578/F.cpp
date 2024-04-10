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
const int N=5e2+5; 
int n,m,p,k,f[N][N],fa[N*N],b[N*N];char s[N][N];
in void M(int &x) {x-=p;x+=x>>31&p;}
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
in void merge(int u,int v) {u=find(u),v=find(v),u^v?fa[u]=v:0;} 
struct mat
{
	int n,a[N][N];in void add(int x,int y) {a[x][x]++,a[y][y]++,a[x][y]--,a[y][x]--;}
	in int det()
	{
		int ans=1;for(int i=1;i<n;i++) for(int j=1;j<n;j++) M(a[i][j]=a[i][j]%p+p);
		for(int i=1;i<n;i++)
		{
			int k=i;while(!a[k][i]&&k<n) k++;
			if(i^k) swap(a[k],a[i]),ans=p-ans;
			for(int j=i+1;j<n;j++) 
			{
				int t=1ll*a[j][i]*qpow(a[i][i],p-2)%p;
				for(int k=i;k<n;k++) M(a[j][k]+=p-1ll*a[i][k]*t%p);
			}
		}
		for(int i=1;i<n;i++) ans=1ll*ans*a[i][i]%p;return ans;
	}
}g[2];
int main()
{
	n=read(),m=read(),p=read();for(int i=1;i<=n;i++) gs(s[i]+1);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) f[i][j]=++k,fa[k]=k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
	if(s[i][j]=='/') merge(f[i+1][j],f[i][j+1]);
	else if(s[i][j]=='\\') merge(f[i][j],f[i+1][j+1]);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) if(find(f[i][j])==f[i][j]) b[f[i][j]]=++g[(i+j)&1].n;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='*')
	g[(i+j)&1].add(b[find(f[i][j])],b[find(f[i+1][j+1])]),g[(i+j+1)&1].add(b[find(f[i+1][j])],b[find(f[i][j+1])]);
	write((g[0].det()+g[1].det())%p,'\n');
	return ot(),0;
}
//Author: disangan233