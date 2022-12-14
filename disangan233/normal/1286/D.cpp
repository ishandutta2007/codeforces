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
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
const int N=1e5+5,p=998244353;
int n,m,ans,la,a[N],b[N],q[N][2],vis[N][2][2],s[N<<2][2][2],md[N<<2],bl[N];
struct did{int x,i,j,l,v;}c[N*2];
in void M(int &x) {x-=p;x+=x>>31&p;}
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
in void up(int u)
{
	for(int i=0;i<2;i++) for(int j=0;j<2;j++)
	{
		s[u][i][j]=0;for(int x=0;x<2;x++) for(int y=0;y<2;y++) 
		if(!vis[md[u]][x][y]) M(s[u][i][j]+=1ll*s[ls(u)][i][x]*s[rs(u)][y][j]%p);
	}
}
void build(int p,int l,int r)
{
	if(l==r) return s[p][0][0]=q[l][0],s[p][1][1]=q[l][1],void();
	md[p]=mid,bl[mid]=p,build(ls(p),l,mid),build(rs(p),mid+1,r),up(p);
}
int main()
{
	n=read();int iv=qpow(100,p-2);
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),q[i][1]=1ll*iv*read()%p,M(q[i][0]=p+1-q[i][1]);
	build(1,1,n);
	for(int i=2;i<=n;i++)
	{
		c[++m]={i-1,1,0,a[i]-a[i-1],b[i-1]+b[i]};
		if(b[i-1]>b[i]) c[++m]={i-1,1,1,a[i]-a[i-1],b[i-1]-b[i]};
		if(b[i-1]<b[i]) c[++m]={i-1,0,0,a[i]-a[i-1],b[i]-b[i-1]};
	}sort(c+1,c+m+1,[](did a,did b){return 1ll*a.l*b.v<1ll*b.l*a.v;});
	for(int i=la=1;i<=m;i++)
	{
		vis[c[i].x][c[i].i][c[i].j]=1;for(int u=bl[c[i].x];u;u>>=1) up(u);
		int tmp=(0ll+s[1][0][0]+s[1][0][1]+s[1][1][0]+s[1][1][1])%p;
		M(ans+=1ll*c[i].l*qpow(c[i].v,p-2)%p*(la-tmp+p)%p),la=tmp;
	}write(ans,'\n');
	return ot(),0;
}
//Author: disangan233