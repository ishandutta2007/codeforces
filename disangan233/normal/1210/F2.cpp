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
#define fi first
#define se second
#define vint vector<int>
#define pv pair<vint,int>
const int N=8,p=1e9+7;
int n,tot,ans,a[N][N],b[N][1<<N];vector<pv>v;
map<vint,int>mp;vint st;
in void M(int &x) {x-=p;x+=x>>31&p;}
in int qpow(int a,int b) {int c=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)c=1ll*a*c%p;return c;}
int main()
{
	n=read(),tot=1<<n,v.pb({vint({0}),1});
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j]=1ll*read()*qpow(100,p-2)%p; 
	for(int i=0;i<n;i++) for(int j=0;j<tot;j++)
	{
		b[i][j]=1;
		for(int k=0;k<n;k++) b[i][j]=1ll*b[i][j]*((j&(1<<k))?a[i][k]:p+1-a[i][k])%p;
	}
	for(int i=0;i<n;i++)
	{
		mp.clear();
		for(int s=0;s<tot;s++) for(pv e:v)
		{
			vint nt=e.fi;int o=e.se;st.clear();
			for(int t:nt) for(int j=0;j<n;j++) if(s&(1<<j)&&!(t&(1<<j))) st.pb(t|(1<<j));
			sort(st.begin(),st.end());st.resize(unique(st.begin(),st.end())-st.begin());
			if(st.size()) M(mp[st]+=1ll*o*b[i][s]%p);
		}
		v.clear();for(pv e:mp) v.pb(e);
	}for(pv e:v) M(ans+=e.se);write(ans,'\n');
	return ot(),0;
}
//Author: disangan233