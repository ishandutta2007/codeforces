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
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,cx,cy,i,j,a[200005];
struct mat{double a[3][3];}tr[800005];
double cmax(mat x){return max(max(x.a[0][0],x.a[0][1]),x.a[0][2]);}
void init(int x,double v)
{
	int i,j;fz0k(i,3)fz0k(j,3)tr[x].a[i][j]=-1e18;
	tr[x].a[0][0]=0;tr[x].a[1][0]=0;tr[x].a[2][0]=0;
	tr[x].a[0][1]=v/(cx+cy);tr[x].a[1][1]=v/(cx+cy);
	tr[x].a[0][2]=v/cy;
}
mat merge(mat a,mat b)
{
	mat c;int i,j,k;
	fz0k(i,3)fz0k(j,3)c.a[i][j]=-1e18;
	fz0k(i,3)fz0k(j,3)fz0k(k,3){
		c.a[i][k]=max(c.a[i][k],a.a[i][j]+b.a[j][k]);
	}
	return c;
}
void pushup(int x){tr[x]=merge(tr[x+x],tr[x+x+1]);}
void build(int x,int l,int r)
{
	if(l==r){init(x,a[l]);return;}int mid=(l+r)/2;
	build(x+x,l,mid);build(x+x+1,mid+1,r);pushup(x);
}
void update(int x,int l,int r,int y,int c)
{
	if(l==r){init(x,c);return;}int mid=(l+r)/2;
	if(y<=mid)update(x+x,l,mid,y,c);else update(x+x+1,mid+1,r,y,c);
	pushup(x);
}
mat query(int x,int l,int r,int ql,int qr)
{
	if(ql<=l&&r<=qr) return tr[x];int mid=(l+r)/2;
	if(qr<=mid)return query(x+x,l,mid,ql,qr);
	if(ql>mid)return query(x+x+1,mid+1,r,ql,qr);
	return merge(query(x+x,l,mid,ql,qr),query(x+x+1,mid+1,r,ql,qr));
}
int main()
{
	read(n);read(m);read(cx);read(cy);if(cx>cy)swap(cx,cy);
	fz1(i,n)read(a[i]);build(1,1,n);
	while(m--){
		int op;read(op);int x,y;read(x);read(y);
		if(op==1)update(1,1,n,x,y);
		else printf("%.10f\n",cmax(query(1,1,n,x,y)));
	}
	return 0;
}