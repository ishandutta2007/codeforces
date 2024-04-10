#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MX=600100;

int N,M;
int U[MX],uc;
int F[MX],dp[MX],B[MX];

struct Query{int l,r,nx;}Q[MX];
int Hq[MX];
void Link(int i,int x){Q[i].nx=Hq[x],Hq[x]=i;}

int Max(int i,int j){return dp[i]>dp[j]?i:j;}

struct SegmentTree{int v,z;}T[MX<<2];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
void Modify(int i,int l,int r,int a,int b,int x)
{
	T[i].v=Max(T[i].v,x);
	if(a<=l&&r<=b){T[i].z=Max(T[i].z,x);return;}
	if(a<=mid)Modify(li,l,mid,a,b,x);
	if(b>mid)Modify(ri,mid+1,r,a,b,x);
}
void Ask(int i,int l,int r,int a,int b,int &res)
{
	if(a<=l&&r<=b){res=Max(res,T[i].v);return;}
	res=Max(res,T[i].z);
	if(a<=mid)Ask(li,l,mid,a,b,res);
	if(b>mid)Ask(ri,mid+1,r,a,b,res);
}


int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,M)
	{
		int x;
		scanf("%d%d%d",&x,&Q[i].l,&Q[i].r);
		U[++uc]=Q[i].l,U[++uc]=Q[i].r;
		Link(i,x);
	}
	sort(U+1,U+uc+1);
	uc=unique(U+1,U+uc+1)-U-1;
	
	Fr(i,1,N)
	{
		for(int j=Hq[i];j;j=Q[j].nx)
		{
			Q[j].l=lower_bound(U+1,U+uc+1,Q[j].l)-U;
			Q[j].r=lower_bound(U+1,U+uc+1,Q[j].r)-U;
			Ask(1,1,uc,Q[j].l,Q[j].r,F[i]);
		}
//		printf("F[%d]=%d\n",i,F[i]);
		dp[i]=dp[F[i]]+1;
		for(int j=Hq[i];j;j=Q[j].nx)
			Modify(1,1,uc,Q[j].l,Q[j].r,i);
	}
	
	int x=T[1].v;
	printf("%d\n",N-dp[x]);
	while(x)B[x]=1,x=F[x];
	Fr(i,1,N)if(!B[i])printf("%d ",i);
	putchar('\n');
	
	return 0;
}