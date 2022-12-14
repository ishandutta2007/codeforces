#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
};
using namespace fast_io;
const int N=1e5+5,K=25;
int n,k,l=1,r,cur,a[N],cnt[N];
ll f[N][K],ans;
in void calc(re L,re R)
{
	while(l<L) cnt[a[l]]--,ans-=cnt[a[l++]];
	while(r>R) cnt[a[r]]--,ans-=cnt[a[r--]];
	while(l>L) ans+=cnt[a[--l]],cnt[a[l]]++;
	while(r<R) ans+=cnt[a[++r]],cnt[a[r]]++;
}
void solve(re l,re r,re L,re R)
{
	if(l>r) return;
	re mid=(l+r)>>1,pos=0;
	for(re i=L;i<=min(R,mid-1);i++)
	{
		calc(i+1,mid);
		if(f[mid][cur]>f[i][cur-1]+ans) f[mid][cur]=f[i][cur-1]+ans,pos=i;
	}
	solve(l,mid-1,L,pos);solve(mid+1,r,pos,R);
}
int main()
{
	n=read();k=read();memset(f,127,sizeof(f));
	for(re i=1;i<=n;i++) a[i]=read(),calc(1,i),f[i][1]=ans;
	for(re i=2;i<=k;i++) cur=i,solve(1,n,0,n-1);
	write(f[n][k],'\n');
	return ot(),0;
}
//Author: disangan233
//In my dream's scene,I can see the everything that in Cyaegha.