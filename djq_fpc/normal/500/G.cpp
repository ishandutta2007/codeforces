#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,dep[200005],fi[200005],ti;
int mi[400005][19],fa[200005],lg[400005];
vector<int> bi[200005];
int gmi(int x,int y)
{
	return (dep[x]<dep[y]?x:y);
}
int gmx(int x,int y)
{
	return (dep[x]>dep[y]?x:y);
}
int lca(int x,int y)
{
	x=fi[x];y=fi[y];
	if(x>y)swap(x,y);
	int t=lg[y-x+1];
	return gmi(mi[x][t],mi[y-(1<<t)+1][t]);
}
void dfs(int x,int p)
{
	mi[fi[x]=++ti][0]=x;
	fa[x]=p;
	ff(bi[x],it)if(*it!=p){
		dep[*it]=dep[x]+1;dfs(*it,x);
		mi[++ti][0]=x;
	}
}
int gtdis(int x,int y,int z=0)
{
	if(!z) z=lca(x,y);
	return dep[x]+dep[y]-2*dep[z];
}
int exgcd(int x,int y,int &a,int &b)
{
	if(!y){
		a=1;b=0;return x;
	}
	int s=exgcd(y,x%y,b,a);
	b-=x/y*a;return s;
}

// mini ans
// ans = k1*p1+a1
// ans = k2*p2+a2
long long solve_same(int p1,int a1,int p2,int a2)
{
	int g=__gcd(p1,p2),d=a2-a1;
	if(d%g!=0) return 0x3f3f3f3f3f3f3f3fll;
	long long mod=1ll*p1/g*p2;
	int np1=p1/g,np2=p2/g,nd=d/g,k1,k2;
	exgcd(np1,np2,k1,k2);
	k1=1ll*k1*nd%np2;
	return (1ll*k1*p1%mod+mod+a1)%mod;
}

// mini k2
// p1*k1+l <= p2*k2 <= p1*k1+r
// p2*k2-r <= p1*k1 <= p2*k2-l
// p2*k2'-r%p2 <= (p1%p2)*k1 <= p2*k2'-l%p2
long long solve(int p1,int p2,int l,int r)
{
	if(l==0) return 0;
	if((l+p2-1)/p2<=r/p2) return (l+p2-1)/p2;
	long long k1=solve(p2,p1%p2,(p2-r%p2)%p2,(p2-l%p2)%p2);
	if(k1==0x3f3f3f3f3f3f3f3fll) return 0x3f3f3f3f3f3f3f3fll;
	return (k1*p1+l+p2-1)/p2;
}

// ans=k1*p1+a1+dis(c1,z)
// ans=k2*p2+a2+dis(c2,z)
// ans=(k1*p1+a1+k2*p2+a2+dis(c1,c2))/2
// mini ans
// k1*p1+a1-len <= k2*p2+a2 <= k1*p1+a1+len
// k1*p1+a1-a2-len <= k2*p2 <= k1*p1+a1-a2+len
// a1-a2-len <= k2*p2 <= a1-a2+len (mod p1)
//  
long long solve_diff(int p1,int a1,int p2,int a2,int len)
{
	if((a1-a2+len)&1==1) return 0x3f3f3f3f3f3f3f3fll;
	int l=((a1-a2-len)%p1+p1)%p1;
	int r=((a1-a2+len)%p1+p1)%p1;
	long long k2=0;
	if(len*2!=p1&&l<=r&&l>0){
		int g=__gcd(p1,p2);
		if((l+g-1)/g>r/g) return 0x3f3f3f3f3f3f3f3fll;
		k2=solve(p1,p2%p1,l,r);
	}
	long long k1=(k2*p2-(a1-a2-len))/p1;
	return (k1*p1+a1+k2*p2+a2+len)/2;
}
int main()
{
	fz(i,2,400000) lg[i]=lg[i/2]+1;
	read(n);
	fz1(i,n-1){
		int x,y;
		read(x);read(y);
		bi[x].push_back(y);
		bi[y].push_back(x);
	}
	dfs(1,0);
	fz1(j,18)fz1(i,ti-(1<<j)+1) mi[i][j]=gmi(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
	read(m);
	while(m--){
		int x1,y1,x2,y2;
		read(x1);read(y1);
		read(x2);read(y2);
		int z1=lca(x1,y1),z2=lca(x2,y2);
		if(dep[z1]>dep[z2]){
			swap(x1,x2);
			swap(y1,y2);
			swap(z1,z2);
		}
		if(lca(z1,z2)!=z1){
			puts("-1");continue;
		}
		int c1=gmx(lca(x2,x1),lca(x2,y1));
		int c2=gmx(lca(y2,x1),lca(y2,y1));
		if(dep[z2]>dep[c1]||dep[z2]>dep[c2]){
			puts("-1");continue;
		}
		
		long long ans=0x3f3f3f3f3f3f3f3fll;
		int len1=gtdis(x1,y1,z1)*2;
		int len2=gtdis(x2,y2,z2)*2;
		int lj=gtdis(c1,c2);
		int l1=gtdis(x1,c1),l2=gtdis(x1,c2);
		int l3=gtdis(x2,c1),l4=gtdis(x2,c2);
		if(l1>l2) l1=len1-l1; else l2=len1-l2;
		if(l3>l4) l3=len2-l3; else l4=len2-l4;
		ans=min(ans,solve_same(len1,l1,len2,l3));
		ans=min(ans,solve_same(len1,l2,len2,l4));
		ans=min(ans,solve_diff(len1,l1,len2,l4,lj));
		ans=min(ans,solve_diff(len1,l2,len2,l3,lj));
		if(ans==0x3f3f3f3f3f3f3f3fll) puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}