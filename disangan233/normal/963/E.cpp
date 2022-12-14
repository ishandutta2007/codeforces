#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
	in int read()
	{
		int x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
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
const int N=8e3+5,P=2e2+5,K=1e2+5,p=1e9+7;
#define pb push_back
int n,A,B,a[K][K],tot,f[N],s[N][P],val[N],ans[N],c[5],res,dx[]={-1,0,1,0},dy[]={0,-1,0,1};
in int sqr(int x) {return x*x;}
in void M(int &x) {x-=p;x+=x>>31&p;}
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
int det()
{
	for(int i=1;i<=tot;i++) for(int j=i+1,k=1;j<=tot&&k<=A;j++,k++) if(s[j][A-k])
	{
		int res=1ll*s[j][A-k]*qpow(s[i][A],p-2)%p;
		for(int x=A,y=A-k;x<=B;x++,y++) M(s[j][y]+=p-1ll*res*s[i][x]%p);
		M(val[j]+=p-1ll*res*val[i]%p);
	}
	for(int i=tot;i>=a[n][n];i--)
	{
		ans[i]=1ll*val[i]*qpow(s[i][A],p-2)%p;
		for(int j=i-1,k=1;j&&k<=A;j--,k++) if(s[j][A+k])
		M(val[j]+=p-1ll*ans[i]*s[j][A+k]%p);
	}
	return ans[a[n][n]];
}
int main()
{
	n=read(),A=n<<1,B=A<<1;for(int i=0;i<4;i++) res+=(c[i]=read());
	for(int i=0;i<=A;i++) for(int j=0;j<=A;j++) if(sqr(i-n)+sqr(j-n)<=sqr(n)) a[i][j]=++tot;
	for(int i=0;i<=A;i++) for(int j=0;j<=A;j++) if(a[i][j]) 
	{
		for(int k=0;k<4;k++)
		{
			int x=i+dx[k],y=j+dy[k];
			if(a[x][y]) s[a[i][j]][a[x][y]-a[i][j]+A]=c[k];
		}
		s[a[i][j]][A]=val[a[i][j]]=p-res;
	}
	write(det(),'\n');
	return ot(),0;
}
//Author: disangan233