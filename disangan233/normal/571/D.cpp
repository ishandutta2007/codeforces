#pragma GCC optimize(2,3,"Ofast")
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
	in int gst(char *s) {char c,*t=s;while(c=gc(),c<=32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
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
#define fi first
#define se second
const int N=5e5+5;
int n,m,c[N],f[N],g[N],fs[N],gs[N],ft[N],gt[N];char ch[5];
vector<pair<int,ll>>t[N]; 
int find(int *f,int x) {while(x^f[x])x=f[x];return x;}
in void merge(int *f,int *s,int *t,int u,int v,int k)
{
	u=find(f,u),v=find(f,v);if(s[u]<s[v]) swap(u,v);
	s[u]+=s[v],f[v]=u,t[v]=k; 
}
int main()
{
	n=read(),m=read();for(int i=1;i<=n;i++) fs[f[i]=g[i]=i]=gs[i]=1,t[i].pb({-1,0});
	for(int i=1;i<=m;i++)
	{
		gst(ch);int x=read(),y,k;
		if(ch[0]=='U') merge(f,fs,ft,x,read(),i);
		else if(ch[0]=='M') merge(g,gs,gt,x,read(),i);
		else if(ch[0]=='A') k=find(f,x),t[k].pb({i,fs[k]+t[k].back().se});
		else if(ch[0]=='Z') k=find(g,x),c[k]=i;
		else
		{
			int fx=x,tg=c[x],l;
			for(;g[fx]^fx;fx=g[fx]) if(c[g[fx]]>gt[fx]) tg=max(tg,c[g[fx]]);
			fx=x,l=lower_bound(t[x].begin(),t[x].end(),make_pair(tg,0ll))-t[x].begin();
			ll ans=t[x].back().se-t[x][l-1].se;
			for(int tf;f[fx]^fx;fx=tf) 
			{
				tf=f[fx],l=lower_bound(t[tf].begin(),t[tf].end(),make_pair(max(tg,ft[fx]),0ll))-t[tf].begin();
				ans+=t[tf].back().se-t[tf][l-1].se;
			}write(ans,'\n');
		}
	}
	return ot(),0;
}
//Author: disangan233