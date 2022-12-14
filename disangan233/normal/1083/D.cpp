#pragma GCC optimize(2,3,"Ofast","unroll-loops")
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
}
using namespace fast_io;
#define pb push_back
const int N=1e5+5,p=1e9+7;
int n,t,ans,a[N],mp[N],lst[N],cnt[N],pre[N],suc[N],fp[N],fs[N],q[N],top,s[N<<2][4],nt[N<<2][2];
in void M(int &x) {x-=p;x+=x>>31&p;}
in int s2(int x) {return 1ll*x*(x+1)/2%p;}
in int S(int l,int r) {int x=s2(r)+p-s2(l-1);return M(x),x;}
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
#define mid ((l+r)>>1)
in void up(int x) {for(int i=0;i<4;i++) M(s[x][i]=s[ls(x)][i]+s[rs(x)][i]);}
in void add(int x,int l,int r,int v,int op) 
{
	s[x][2]=1ll*s[x][op^1]*v%p;s[x][op]=(r-l+1ll)*v%p; 
	nt[x][op]=v;if(!op) s[x][3]=1ll*S(l,r)*v%p;
}
in void down(int p,int l,int r)
{
	for(int i=0;i<2;i++) if(nt[p][i]) 
	add(ls(p),l,mid,nt[p][i],i),add(rs(p),mid+1,r,nt[p][i],i),nt[p][i]=0;
}
void add(int p,int l,int r,int L,int R,int v,int op)
{
	if(R<l||r<L) return; if(L<=l&&r<=R) return add(p,l,r,v,op);down(p,l,r);
	add(ls(p),l,mid,L,R,v,op);add(rs(p),mid+1,r,L,R,v,op);up(p);
}
int ask(int p,int l,int r,int L,int R,int op)
{
	if(R<l||r<L) return 0; if(L<=l&&r<=R) return s[p][op];down(p,l,r);
	int x=ask(ls(p),l,mid,L,R,op)+ask(rs(p),mid+1,r,L,R,op);return M(x),x;	
}
int main()
{
	n=read();for(int i=1;i<=n;i++) mp[i]=a[i]=read(); 
	sort(mp+1,mp+n+1);int tot=unique(mp+1,mp+n+1)-mp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(mp+1,mp+tot+1,a[i])-mp,pre[i]=lst[a[i]]+1,lst[a[i]]=i;
	for(int i=1;i<=tot;i++) lst[i]=n+1;
	for(int i=n;i;i--) suc[i]=lst[a[i]]-1,lst[a[i]]=i;
	for(int i=n;i;i--) {while(t&&pre[i]>pre[q[t]])t--;fp[i]=t?q[t]-1:n;q[++t]=i;}t=0;
	for(int i=n;i;i--) {while(t&&suc[i]<suc[q[t]])t--;fs[i]=t?q[t]-1:n;q[++t]=i;}
	for(int i=n,j=n;i;i--)
	{
		add(1,1,n,i,fp[i],pre[i],0);add(1,1,n,i,fs[i],suc[i],1);cnt[a[i]]++;
		while(cnt[a[i]]>1) cnt[a[j]]--,j--;
		M(ans+=ask(1,1,n,i,j,3));M(ans+=p-ask(1,1,n,i,j,2));
		M(ans+=1ll*i*ask(1,1,n,i,j,1)%p);M(ans+=p-1ll*i*S(i,j)%p);
	}
	write(ans,'\n');
	return ot(),0;
}
//Author: disangan233