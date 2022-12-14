// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
	in void flush() {if(C>1<<22) ot();}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0)y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y)z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;flush();
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++)sr[++C]=*s++;sr[++C]='\n';flush();}
}
using namespace fast_io;
const int N=5e5+5;
int n,t,ans[N],vis[N];
char a[N]; 
int main()
{
	t=read();
	for(int T=1;T<=t;T++)
	{
		n=gs(a+1);ans[0]=0;
		for(int i=1;i<=n;i++) 
		{
			if(i+2<=n&&a[i]=='t'&&a[i+1]=='w'&&a[i+2]=='o'&&a[i+3]^'o') vis[i+2]=T;
			else if(i+2<=n&&a[i]=='t'&&a[i+1]=='w'&&a[i+2]=='o') vis[i+1]=T;
			else if(i+2<=n&&a[i]=='o'&&a[i+1]=='n'&&a[i+2]=='e'&&(!i||(i>=1&&a[i-1]^'o'))) vis[i]=T;
			else if(i+2<=n&&a[i]=='o'&&a[i+1]=='n'&&a[i+2]=='e') vis[i+1]=T;
		}
		for(int i=1;i<=n;i++) if(vis[i]==T) ans[++ans[0]]=i;write(ans[0],'\n');
		for(int i=1;i<=ans[0];i++) write(ans[i]," \n"[i==ans[0]]);if(!ans[0]) sr[++C]='\n';
	}
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.