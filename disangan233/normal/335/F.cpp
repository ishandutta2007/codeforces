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
#define pii pair<int,int>
#define fi first
#define se second
const int N=5e5+5;
int n,m,tot,a[N],c[N],s[N],t[N];ll ans;priority_queue<int>q; 
int main()
{
	n=read();for(int i=1;i<=n;i++) a[i]=read(),ans+=a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++) (i==1||a[i]^a[i-1])?s[++m]=a[i],c[m]++:c[m]++;
	for(int i=1;i<=m;i++)
	{
		int ok=min(tot-(int)q.size()*2,c[i]),r=min(c[i]-ok,tot-ok),k=0;
		for(int j=1;j<=ok;j++) t[++k]=s[i];
		for(int j=1;j<=r;j+=2)
		{
			int x=-q.top();q.pop();
			if(x<s[i]) t[++k]=s[i],j<r?t[++k]=s[i]:0;
			else t[++k]=x,j<r?t[++k]=2*s[i]-x:0;
		}
		for(int j=1;j<=k;j++) if(t[j]>=0) q.push(-t[j]);
		tot+=c[i];
	}
	while(!q.empty()) ans+=q.top(),q.pop();
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233