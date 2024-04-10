#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,M;

struct SegmentTree{int c,l,r;ll x,y;}T[MX*32];
int tc;
void Ins(int& i,int l,int r,int x,int y)
{
	if(!i)i=++tc;
	++T[i].c,T[i].x+=x,T[i].y+=y;
	if(l==r)return;
	int m=(l+r)>>1;
	if(x<=m)Ins(T[i].l,l,m,x,y);
	else Ins(T[i].r,m+1,r,x,y);
}
void Ask(int i,int l,int r,int a,int b,ll& c,ll& x,ll& y)
{
	if(!i)return;
	if(a<=l&&r<=b){c+=T[i].c,x+=T[i].x,y+=T[i].y;return;}
	int m=(l+r)>>1;
	if(a<=m)Ask(T[i].l,l,m,a,b,c,x,y);
	if(b>m)Ask(T[i].r,m+1,r,a,b,c,x,y);
}

int I[MX];
ll ans;

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)Fr(j,1,M)
	{
		int a;
		scanf("%d",&a);
		ll cl=0,xl=0,yl=0;
		ll cr=0,xr=0,yr=0;
		Ask(I[a],1,M,1,j,cl,xl,yl);
		if(j<M)Ask(I[a],1,M,j+1,M,cr,xr,yr);
		ans+=i*(cl+cr)-(yl+yr);
		ans+=j*cl-xl;
		ans+=xr-j*cr;
		Ins(I[a],1,M,j,i);
	}
	printf("%lld\n",ans);
	return 0;
}