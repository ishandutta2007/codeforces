#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define in inline
namespace fast_io
{
    char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0;
    in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
    in ll read()
    {
        ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1)if(nc==45)y=-1;
        x=nc-48;while(nc=gc(),47<nc&&nc<58)x=(x<<3)+(x<<1)+(nc^48);return x*y;
    }
    in db gf() {re a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
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
};
using namespace fast_io;
int n,m,k,r,ans,a[1005],b[1005],c[1005],d[1005],f[60005];
int main()
{
	n=read();r=read();memset(f,-63,sizeof(f));f[r]=0;
	for(re i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=i;
	sort(c+1,c+n+1,[](re x,re y){return ((b[x]>0)^(b[y]>0))?b[x]>b[y]:((b[x]>0)?a[x]<a[y]:((a[x]+b[x]==a[y]+b[y])?a[x]>a[y]:a[x]+b[x]>a[y]+b[y]));});
	for(re i=1;i<=n;i++)
	{
		if(b[c[i]]>0) for(re j=60000-b[c[i]];j>=a[c[i]];j--) f[j+b[c[i]]]=max(f[j+b[c[i]]],f[j]+1);
		else for(re j=max(a[c[i]],-b[c[i]]);j<=60000;j++) f[j+b[c[i]]]=max(f[j+b[c[i]]],f[j]+1);
	}
	for(re i=0;i<=60000;i++) ans=max(ans,f[i]);
	write(ans,'\n');
	return ot(),0;
}