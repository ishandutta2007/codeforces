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
		ll x=0,y=1;while(nc=gc(),(nc<48||nc>57)&&nc!=-1) if(nc==45) y=-1;
		x=nc-48;while(nc=gc(),47<nc&&nc<58) x=(x<<3)+(x<<1)+(nc^48);return x*y;
	}
	in db gf() {re a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		re y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {re l=strlen(s);for(re i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=3e5+5;
int n,m;
char s[N],t[N];
struct ACAM{
	int ch[N][26],sum[N],rt,tot,fail[N],q[N],val[N];
	in void init() {rt=tot=1;}
	in void ins(char *s,re n)
	{
		re p=rt;
		for(re i=1;i<=n;i++)
		{
			re c=s[i]-'a';
			if(!ch[p][c]) ch[p][c]=++tot;
			p=ch[p][c];
		}
		sum[p]++;
	}
	in void build_ac()
	{
		re h=0,t=0;q[++t]=rt;
		while(h<t)
		{
			re u=q[++h];
			for(re i=0;i<26;i++) if(ch[u][i])
			{
				re v=ch[u][i],p=fail[u];q[++t]=v;
				while(p&&!ch[p][i]) p=fail[p];
				if(!p) fail[v]=rt; else fail[v]=ch[p][i];
				sum[v]+=sum[fail[v]];
			}
		}
	}
	in void find(char *s,re n)
	{
		re p=rt;
		for(re i=1;i<=n;i++)
		{
			re c=s[i]-'a';while(p&&!ch[p][c]) p=fail[p];
			val[i]=sum[p=(p?ch[p][c]:rt)];
		}
	}
}t1,t2;
int main()
{
	re len=gs(t+1);n=read();t1.init();t2.init();
	for(re i=1;i<=n;i++)
	{
		re m=gs(s+1);t1.ins(s,m);
		reverse(s+1,s+m+1);t2.ins(s,m);
	}
	t1.build_ac();t2.build_ac();
	t1.find(t,len);reverse(t+1,t+len+1);t2.find(t,len);
	ll ans=0;
	for(re i=1;i<=len;i++) ans+=(ll)t1.val[i]*t2.val[len-i];
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233