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
const int N=1e6+5;
ll n,p,k,c[N],d[N];
in int check(int x)
{
	ll i=2,j,t=1,l=0,s=k-n;memset(c+1,0,8*n);memset(d+1,0,8*n);
	while(i<=n) for(t*=x,l++,j=1;i<=n&&j<=t;i++,j++) c[l]++,d[i]=l,s-=l;
	if(s<0) return 0; j=n;
	while(s)
	{
		l++;if(c[d[j]]==1) j--;
		t=min(s,l-d[j]);c[d[j]]--;c[d[j]+=t]++;s-=t;j--;
	}
	return 1;
}
int main()
{
	n=read(),k=read();if(k<2*n-1||k>n*(n+1)/2) return write("No"),ot(),0;
	write("Yes");int l=1,r=n,mid;
	while(l<r) mid=(l+r)>>1,check(mid)?r=mid:l=mid+1;
	check(r);d[p=1]=0;sort(d+2,d+n+1);memset(c+1,0,8*n);
	for(int i=2;i<=n;i++) 
	{
		while(d[p]^(d[i]-1)||c[p]==r) p++;
		write(p,' ');c[p]++;
	} 
	return ot(),0;
}
//Author: disangan233