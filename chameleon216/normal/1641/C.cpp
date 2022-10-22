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

const int MX=200100,Inf=0x3f3f3f3f;
int N,M;
struct Querys{int o,l,r;}Q[MX];

int F[MX],C[MX];
int Find(int x){return x==F[x]?x:F[x]=Find(F[x]);}

#define li (i<<1)
#define ri (i<<1|1)
int mx[MX*4];
void Build(int i,int l,int r)
{
	if(l==r){mx[i]=C[l];return;}
	int m=(l+r)>>1;
	Build(li,l,m),Build(ri,m+1,r);
	mx[i]=max(mx[li],mx[ri]);
}
int Query(int i,int l,int r,int a,int b)
{
	if(a<=l&&r<=b)return mx[i];
	int m=(l+r)>>1,res=0;
	if(a<=m)res=max(res,Query(li,l,m,a,b));
	if(b>m)res=max(res,Query(ri,m+1,r,a,b));
	return res;
}

int nx[MX],U[MX];

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int o;
		scanf("%d",&o);
		if(o==0)scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].o);
		else scanf("%d",&Q[i].l),Q[i].o=2;
	}
	
	Fr(i,1,N+1)F[i]=i;
	Fr(i,1,M)if(Q[i].o==0) //C 0
	{
		int l=Q[i].l,r=Q[i].r;
		for(int j=Find(l);j<=r;j=Find(j))
			C[j]=i,F[j]=j+1;
	}
//	Fr(i,1,N)printf("%d ",C[i]);putchar('\n');
	
	Build(1,1,N);
//	printf("%d %d %d\n",Query(1,1,N,1,3),Query(1,1,N,3,5),Query(1,1,N,3,3));
	
	nx[N+1]=N+1;
	Fl(i,N,1)nx[i]=(C[i]?nx[i+1]:i);
//	Fr(i,1,N)printf("%d ",nx[i]);putchar('\n');
	
	Fr(i,1,N)U[i]=Inf;
	Fr(i,1,M)if(Q[i].o==1)
	{
		int l=Q[i].l,r=Q[i].r;
		int o=nx[l],oo=nx[o+1];
		if(o<=r&&oo>r)U[o]=min(U[o],max(i,Query(1,1,N,l,r)));
	}
//	Fr(i,1,N)printf("%d ",U[i]);putchar('\n');
	
	Fr(i,1,M)if(Q[i].o==2)
	{
		int a=Q[i].l;
		if(C[a]&&C[a]<i)printf("NO\n");
		else if(U[a]<i)printf("YES\n");
		else printf("N/A\n");
	}
	return 0;
}