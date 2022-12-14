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
const int N=2e3+5;
int n,l1,l2,ans,tot=1,ch[N<<3][10],s[N<<3][N],fa[N<<3],f[N][N<<3],q[N*N];bool c[N][N<<3];char l[N],r[N]; 
in int get(int x,int y) {return !ch[x][y]?ch[x][y]=++tot:ch[x][y];}
in void insert()
{
	int u=1,v=1;
	if(l1==l2)
	{
		for(int i=1;i<=l1;i++) 
		if(u==v)
		{
			for(int j=l[i]-47;j<r[i]-48;j++) s[get(u,j)][l1-i]++;
			u=get(u,l[i]-48),v=get(v,r[i]-48);
		}
		else
		{
			for(int j=l[i]-47;j<10;j++) s[get(u,j)][l1-i]++;u=get(u,l[i]-48);
			for(int j=(i==1);j<r[i]-48;j++) s[get(v,j)][l2-i]++;v=get(v,r[i]-48);
		}
		s[u][0]++,s[v][0]+=u!=v;
	}
	else
	{
		for(int i=1;i<=l1;i++) {for(int j=l[i]-47;j<10;j++) s[get(u,j)][l1-i]++;u=get(u,l[i]-48);}
		for(int i=1;i<=l2;i++) {for(int j=(i==1);j<r[i]-48;j++) s[get(v,j)][l2-i]++;v=get(v,r[i]-48);}
		for(int i=l1+1;i<l2;i++) for(int j=1;j<10;j++) s[get(1,j)][i-1]++;
		s[u][0]++,s[v][0]++;
	}
}
in void build()
{
	int l=0,r=0;
	for(int i=0;i<10;i++) !ch[1][i]?ch[1][i]=1:fa[q[++r]=ch[1][i]]=1;
	while(l<r)
	{
		int u=q[++l];
		for(int i=0;i<l2;i++) s[u][i]+=s[fa[u]][i];
		for(int i=0;i<10;i++) !ch[u][i]?ch[u][i]=ch[fa[u]][i]:fa[q[++r]=ch[u][i]]=ch[fa[u]][i];
	}
	for(int i=1;i<=tot;i++) for(int j=1;j<n;j++) s[i][j]+=s[i][j-1]; 
}
int main()
{
	l1=gs(l+1),l2=gs(r+1),n=read();
	insert();build();memset(f,-63,sizeof(f));f[0][1]=0;
	for(int i=0;i<n;i++) for(int j=1;j<=tot;j++) if(f[i][j]>=0) for(int k=0;k<10;k++) 
	f[i+1][ch[j][k]]=max(f[i+1][ch[j][k]],f[i][j]+s[ch[j][k]][n-i-1]); 
	for(int i=1;i<=tot;i++) ans=max(ans,f[n][i]);
	write(ans,'\n');for(int i=1;i<=tot;i++) c[n][i]=(f[n][i]==ans);
	for(int i=n-1;~i;i--) for(int j=1;j<=tot;j++) if(f[i][j]>=0)for(int k=0;!c[i][j]&&k<10;k++)
	c[i][j]=c[i+1][ch[j][k]]&&(f[i+1][ch[j][k]]==f[i][j]+s[ch[j][k]][n-i-1]);
	for(int i=1,u=1;i<=n;i++) for(int j=0;j<10;j++) if(c[i][ch[u][j]]&&(f[i][ch[u][j]]==f[i-1][u]+s[ch[u][j]][n-i])) {sr[++C]=j+48,u=get(u,j);break;}
	return ot(),0;
}
//Author: disangan233