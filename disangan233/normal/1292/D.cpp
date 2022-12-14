#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define in inline
namespace fast_io
{
	char buf[1<<12],*p1=buf,*p2=buf,sr[1<<23],z[23],nc;int C=-1,Z=0,Bi=0,ny;
	in char gc() {return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<12,stdin),p1==p2)?EOF:*p1++;}
	in ll read()
	{
		ll x=0;ny=1;while(nc=gc(),(nc<48||nc>57)&&nc!=EOF)if(nc==45)ny=-1;Bi=1;if(nc<0)return nc;
		x=nc-48;while(nc=gc(),47<nc&&nc<58&&nc!=EOF)x=(x<<3)+(x<<1)+(nc^48),Bi++;return x*ny;
	}
	in db gf() {int a=read(),y=ny,b=(nc!='.')?0:read();return (b?a+(db)b/pow(10,Bi)*y:a);}
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
const int N=5e3+5;
int n,c[N],f[N][N],p[N],s[N];ll ans,nw; 
int main() 
{
	n=read();for(int i=1;i<=n;i++) c[read()]++;
	for(int i=2;i<N;i++)
	{
		memcpy(f[i],f[i-1],sizeof(f[i]));
		for(int j=2,k=i;j<=k;j++) while(!(k%j)) f[i][j]++,k/=j;
	}
	for(int i=1;i<N;i++) if(!c[i]) p[i]=1;
	else for(int j=1;j<=i;j++) if(f[i][j]) p[i]=j,nw+=1ll*f[i][j]*c[i];
	ans=nw;
	while(*max_element(p+1,p+N)>1)
	{
		memset(s,0,sizeof(s));for(int i=0;i<N;i++) s[p[i]]+=c[i];
		int o=max_element(s+1,s+N)-s,w=s[o];if(w*2<=n||o==1) break;
		ans=min(ans,nw-=w*2-n);
		for(int i=0;i<N;i++)
		{
			if(p[i]^o) p[i]=1;if(p[i]==1) continue;
			f[i][p[i]]--;while(p[i]>1&&!f[i][p[i]]) p[i]--;
		}
	}write(ans,'\n');
	return ot(),0;
}
//Author: disangan233