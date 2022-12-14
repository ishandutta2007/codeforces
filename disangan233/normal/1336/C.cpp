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
const int N=3e3+5,p=998244353;
int n,m,f[N][N],ans;
char s[N],t[N];
in int solve(int a,int b) {return b>m?1:s[a]==t[b];}
in void M(int &x) {if(x>=p)x-=p;if(x<0)x+=p;}
int main() 
{
	n=gs(s+1);m=gs(t+1);for(int i=1;i<=n;i++) f[i][i]=solve(1,i);
	if(m==1) ans=f[1][1];
	for(int i=2;i<=n;i>=m?M(ans+=f[1][i]):void(),i++) for(int l=1,r=i-1;r<=n;l++,r++)
	{
		if(l&&solve(i,l-1)) M(f[l-1][r]+=f[l][r]);
		if(r^n&&solve(i,r+1)) M(f[l][r+1]+=f[l][r]); 
    }
    write(2*ans%p,'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.