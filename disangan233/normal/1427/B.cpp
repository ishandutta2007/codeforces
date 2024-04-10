#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,Ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
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
const int N=1e6+5;
int t,n,m,q[N],r1,r2,k,ans;
char s[N];
int main()
{
	t=read();
	while(t--)
	{
		n=read();m=read();gs(s+1);s[n+1]='L';k=ans=0;
		int now=0,op=0;
		for(int i=1;i<=n;i++) if(s[i]=='W')
		{
			if(!op) op=1,now=0;
			else if(now) q[++k]=now,now=0;
		}else now++;
		for(int i=1;i<=n;i++) if(s[i]=='W') ans+=(s[i]==s[i-1])+1;
		sort(q+1,q+k+1);
		for(int i=1;i<=k;i++) if(q[i]>m) ans+=m<<1,m=0; else ans+=q[i]<<1|1,m-=q[i];
		op=0;for(int i=1;i<=n;i++) op|=(s[i]=='W');
		if(!op) {write(max(0,2*m-1),'\n');continue;}
		ans+=m<<1;write(min(ans,2*n-1),'\n');
	}
	return ot(),0;
}
//Author: disangan233