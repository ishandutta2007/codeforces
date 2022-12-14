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
};
using namespace fast_io;
#define pb push_back
const int N=1e5+5;
int n,m,d,B,G,b[N],g[N];vector<int>a[N<<1],f[N<<1];ll ans;
in int gcd(int a,int b) {return !b?a:gcd(b,a%b);}
in int exgcd(int a,int b,int &x,int &y,int d=0) {return !b?(x=1,y=0,a):(d=exgcd(b,a%b,y,x),y-=a/b*x,d);}
struct pii{ll a,b;in bool operator<(pii x)const{return a^x.a?a<x.a:b<x.b;}};
in ll solve(vector<int>a,vector<int>b)
{
	vector<int>s=a;for(int x:b)s.pb(x);sort(s.begin(),s.end());
	int k=unique(s.begin(),s.end())-s.begin(),x,y;
	if(n==k)
	{
		int c[m];memset(c,0,4*m);
		for(int x:a) if(x<m) c[x]++; for(int x:b) if(x<m) c[x]++;
		for(int i=m-1;~i;i--) if(c[i]==1) return i;
		return -1;
	}
	vector<pii>e[k<<1|1];
	for(int i=0;i<k;i++) e[k<<1].pb({i,s[i]}),e[i+k].pb({i,m});
	exgcd(m,n,x,y);x=(x%n+n)%n;pii p[k];for(int i=0;i<k;i++) p[i]={1ll*x*(s[i]-s[0])%n,i};
	sort(p,p+k);for(int i=0,j=1%k;i<k;i++,j=(++j==k)?0:j) e[p[i].b].pb({p[j].b+k,1ll*m*(p[j].a-p[i].a-1+(p[j].a-p[i].a-1<0?n:0))});
	unordered_map<int,int>h;for(int i=0;i<k;i++) h[s[i]]=i;
	for(int i=0,j;i<k;i++) if(h.find((s[i]+m)%n)!=h.end())
	j=h[(s[i]+m)%n],e[i].pb({j+k,0}),e[j+k].pb({i,0});
	priority_queue<pii>q;int v[k<<1|1];ll d[k<<1|1],nw=0;
	memset(v,0,sizeof(v));memset(d,63,sizeof(d));q.push({0,k<<1});d[k<<1]=0;
	while(q.size())
	{
		int x=q.top().b;q.pop();if(v[x]) continue;v[x]=1;nw=max(nw,d[x]);
		for(auto y:e[x]) if(d[y.a]>d[x]+y.b) d[y.a]=d[x]+y.b,q.push({-d[y.a],y.a});
	}
	return nw;
}
int main()
{
	n=read(),m=read();
	B=read();for(int i=1;i<=B;i++) b[i]=read();
	G=read();for(int i=1;i<=G;i++) g[i]=read();
	if(n<m) swap(n,m),swap(B,G),swap(b,g);
	if((d=gcd(n,m))>B+G) return write("-1"),ot(),0;
	n/=d,m/=d;
	for(int i=1;i<=B;i++) a[b[i]%d].pb(b[i]/d);
	for(int i=1;i<=G;i++) f[g[i]%d].pb(g[i]/d);
	for(int i=0;i<d;i++) if(!a[i].size()&&!f[i].size()) return write("-1"),ot(),0;
	for(int i=0;i<d;i++) ans=max(ans,solve(a[i],f[i])*d+i);
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233