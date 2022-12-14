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
const int N=4e3+5;
int n,T,tot,dfn[N];char a[N][N];
vector<int>v,e[N];
void dfs(int u)
{
	v.push_back(u);dfn[u]=tot;
	for(int v:e[u]) if(!dfn[v]) dfs(v);
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();for(int i=1;i<=n;i++) e[i].clear(),dfn[i]=0;
		for(int i=1;i<=n;i++) gs(a[i]+1);
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(a[i][j]^'0') e[j].push_back(i);
		tot=0;int ln=0,po=0,nt=0;
		for(int i=1;i<=n;i++) if(!dfn[i])
		{
			tot++;v.clear();dfs(i);int k=v.size();
			for(int j:v) if(e[j].size()!=k-1) nt=j;
			if(k==n) ln=1;
			if(k==1) po=i;
		}
		if(ln) write("0");
		else if(po) write(1,'\n'),write(po,'\n');
		else if(nt) write(1,'\n'),write(nt,'\n');
		else if(tot>2)
		{
			write(2,'\n'),write(1,' ');
			for(int i=1;i<=n;i++) if(dfn[i]^dfn[1]) {write(i,'\n');break;}
		}
		else
		{
			int k=0;for(int i=1;i<=n;i++) k+=dfn[i]==1;
			if(k<=n-k)
			{
				write(k,'\n');for(int i=1,t=1;i<=n;i++) if(dfn[i]==1) write(i," \n"[(t++)==k]);
			}
			else
			{
				write(n-k,'\n');for(int i=1,t=1;i<=n;i++) if(dfn[i]==2) write(i," \n"[(t++)==n-k]);
			}
		}
	}
	return ot(),0;
}