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
const int N=18,sgn[2]={1,-1};
int n,l,a[N][N],c[1<<N],tg[1<<N];ll f[N][1<<N],g[N+1][1<<N],t[N+1][1<<N],h[1<<N];
char ch[N];map<vector<int>,ll>mp;
in void dot(ll *a,ll *b,ll *c){for(int i=0;i<l;i++)c[i]=a[i]*b[i];}
in void fwt(ll *t) {for(int i=1;i<l;i<<=1)for(int j=0;j<l;j++)if(j&i)t[j]+=t[j^i];}
in void ifwt(ll *t) {for(int i=1;i<l;i<<=1)for(int j=0;j<l;j++)if(j&i)t[j^i]-=t[j];}
void dfs(int p,int x,int s)
{
	static vector<int>nw;
	if(!s) {ll r=0;for(int i=0;i<l;i++)r+=t[p][i]*tg[i];return mp[nw]=r,void();}
	for(int i=x;i<=s;i++) dot(t[p],g[i],t[p+1]),nw.pb(i),dfs(p+1,i,s-i),nw.pop_back(); 
} 
in ll div(int x)
{
	vector<int> nw;int k=1;for(int i=0;i<n;i++) (~x>>i&1)&&(nw.pb(k),k=0),k++;
	return nw.pb(k),sort(nw.begin(),nw.end()),mp[nw];
}
int main()
{
	n=read(),l=1<<n,tg[0]=sgn[n&1];
	for(int i=0;i<n;i++)
	{
		gs(ch);f[i][1<<i]=1;
		for(int j=0;j<n;j++) a[i][j]=ch[j]-48;
	}
	for(int i=1;i<l;i++) c[i]=c[i>>1]+(i&1),tg[i]=sgn[i&1]*tg[i>>1],t[0][i]=1;
	for(int i=1;i<l;i++) for(int j=0;j<n;j++) for(int k=0;k<n;k++) if(!(i>>k&1)&&a[j][k]) f[k][1<<k|i]+=f[j][i];
	for(int i=0;i<n;i++) for(int j=1;j<l;j++) g[c[j]][j]+=f[i][j];
	for(int i=1;i<n;i++) fwt(g[i]);
	dfs(0,1,n--),l>>=1;for(int i=0;i<l;i++) h[i]=div(i);
	ifwt(h);for(int i=0;i<l;i++) write(h[i],' ');
	return ot(),0;
}
//Author: disangan233