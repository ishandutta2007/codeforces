#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in int read()
	{
		int x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;Bi=1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*y;
	}
	in db gf() {int a=read(),b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi):a);}
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
const int N=1e6+5;
int n,ans,a[N],l[N],r[N];
char s[N];
int main()
{
	n=gs(s+1);
	for(int i=1;i<=n;i++) l[i]=s[i]=='(',r[i]=s[i]==')';
	for(int i=1;i<=n;i++) l[i]+=l[i-1];
	for(int i=n;i;i--) r[i]+=r[i+1];
	for(int i=1;i<n;i++) ans=max(ans,min(l[i],r[i+1]));
	if(!ans) return write("0"),ot(),0;
	write(1,'\n');write(ans*2,'\n');
	for(int i=1,j=ans;i<=n&&j;i++) if(s[i]=='(') j--,write(i,' ');
	for(int i=n,j=ans;i&&j;i--) if(s[i]==')') j--,a[++a[0]]=i;
	for(int i=ans;i;i--) write(a[i]," \n"[i==1]);
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.