#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
}
using namespace fast_io;
#define pb push_back 
const int N=5e2+5;
int n,m,ans,odd[N],f[N],cnt[N][26];char s[N][N];
in bool cmp(int a,int b)
{
	if(odd[a]>1||odd[b]>1) return 0;
	for(int i=0;i<26;i++) if(cnt[a][i]^cnt[b][i]) return 0;
	return 1;
}
int main()
{
	n=read();m=read();for(int i=1;i<=n;i++) gs(s[i]+1);
	for(int l=1;l<=m;l++) 
	{
		for(int i=0;i<=n;odd[2*i-1]=0,i++) for(int j=0;j<26;j++) cnt[2*i-1][j]=0;
		for(int r=l;r<=m;r++) 
		{
			for(int i=1,c;i<=n;i++)
			cnt[2*i-1][c=s[i][r]-'a']++,odd[2*i-1]+=cnt[2*i-1][c]&1?1:-1; 
			memset(f,0,8*n+4);cnt[2*n+1][0]=-1;
			int p=0,q=0;
			for(int i=1;i<=2*n;i++) if(odd[i]<=1)
			{
				f[i]=q>i?min(f[p*2-i],q-i):1;
				while(cmp(i-f[i],i+f[i])) f[i]++;
				if(i+f[i]>q) q=(p=i)+f[i];ans+=f[i]/2;
			}
		}
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233