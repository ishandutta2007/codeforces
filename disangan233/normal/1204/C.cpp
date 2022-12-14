// luogu-judger-enable-o2
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
const int N=2e6+5;
int n,m,k,f[105][105],a[N],b[N];
int main()
{
	n=read();memset(f,63,sizeof(f));
	for(re i=1;i<=n;i++) for(re j=1;j<=n;j++)
	{
		char c=gc();while(!isdigit(c)) c=gc();
		if(c=='1') f[i][j]=1;
	}
	m=read();
	for(re i=1;i<=m;i++) a[i]=read();
	for(re k=1;k<=n;k++) for(re i=1;i<=n;i++) for(re j=1;j<=n;j++)
	if(k!=i&&k!=j&&i!=j&&f[i][j]>f[i][k]+f[k][j]) f[i][j]=f[i][k]+f[k][j];
	b[++k]=a[1];
	for(re i=1,j;i<=m;i=j)
	{
		re sum=0;j=i;
		while(sum+f[a[j]][a[j+1]]==f[a[i]][a[j+1]]&&j<=m) sum+=f[a[j]][a[j+1]],j++;
		if(j<=m) b[++k]=a[j];
	}
	write(k,'\n');for(re i=1;i<=k;i++) write(b[i],(i==k)?'\n':' ');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.