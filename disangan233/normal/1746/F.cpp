// LUOGU_RID: 90780725
#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
	in db gf() {int a=read(),b=(nc!='.')?0:read(),c=ceil(log10(b));return (b?a+(db)b/pow(10,c):a);}
	in int gs(char *s) {char c,*t=s;while(c=gc(),c<32);*s++=c;while(c=gc(),c>32)*s++=c;return s-t;}
	template <typename T>
	in void write(T x,char t)
	{
		int y=0;if(x<0) y=1,x=-x;while(z[++Z]=x%10+48,x/=10);
		if(y) z[++Z]='-';while(sr[++C]=z[Z],--Z);sr[++C]=t;
	}
	in void write(char *s) {int l=strlen(s);for(int i=0;i<l;i++,*s++)sr[++C]=*s;sr[++C]='\n';}
	in void ot() {fwrite(sr,1,C+1,stdout);C=-1;}
};
using namespace fast_io;
const int N=6e5+5;
int n,m,a[N],tot;
unordered_map<int,int>mp;
mt19937 rd(time(0));
struct bit{
	int t[N];bit(){}
	in void add(int x,int y) {for(;x<=n;x+=x&-x)t[x]+=y;}
	in int ask(int x) {int y=0;for(;x;x-=x&-x)y+=t[x];return y;}
}t[41];
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) if(!mp[a[i]=read()]) mp[a[i]]=rd();
	for(int i=1;i<=40;i++) for(int j=1;j<=n;j++) t[i].add(j,mp[a[j]]>>i&1);
	while(m--)
	{
		int op=read(),l=read(),r=read();
		if(op==1)
		{
			for(int i=1;i<=40;i++) t[i].add(l,-(mp[a[l]]>>i&1));
			if(!mp[a[l]=r]) mp[r]=rd();
			for(int i=1;i<=40;i++) t[i].add(l,mp[a[l]]>>i&1);
		}
		else
		{
			int ans=1,k=read();
			if(k==1) {write("YES");continue;}
			for(int i=1;ans&&i<=40;i++) ans&=((t[i].ask(r)-t[i].ask(l-1))%k==0);
			ans?write("YES"):write("NO");
		}
	}
	return ot(),0;
}