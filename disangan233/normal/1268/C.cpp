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
#define par __builtin_parity
const int N=2e5+5;
int n,a[N],p[N];ll ans1,ans2;
struct bit
{
	ll c[N];
	in void add(int x,int y) {for(;x<=n;x+=x&-x)c[x]+=y;}
	in ll ask(int x) {ll y=0;for(;x;x-=x&-x)y+=c[x];return y;}
	in int find(int k)
	{
		int s=0;
		for(int j=20;~j;j--) if((s|1<<j)<=n) if(c[s|1<<j]<=k) s|=1<<j,k-=c[s];
		return s;
	}
}t1,t2;
int main() 
{
	n=read();for(int i=1;i<=n;i++) p[a[i]=read()]=i;
	for(int i=1,j;i<=n;i++)
	{
		t1.add(p[i],1),t2.add(p[i],p[i]),ans1+=i-t1.ask(p[i]),j=t1.find(i>>1)+1;
		int m1=i>>1,m2=i-m1-1;ans2=1ll*m1*j-t2.ask(j-1)-(1ll*m1*(m1+1)>>1);
		ans2+=t2.ask(n)-t2.ask(j)-1ll*m2*j-(1ll*m2*(m2+1)>>1);
		write(ans1+ans2,' '),ans2=0; 
	}
	return ot(),0;
}
//Author: disangan233