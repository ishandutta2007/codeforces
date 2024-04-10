#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=100100,Mod=1000000007;
const ll Inf=0x3f3f3f3f3f3f3f3fll;

int K,N,M;
ll A[MX];

struct Change
{
	int o,p,n,id;
	long double r;
}X[MX],Y[MX],Z[MX];
int xc,yc,zc;

bool cmp1(const Change& x,const Change& y){return x.p!=y.p?x.p<y.p:x.n>y.n;}
bool cmp2(const Change& x,const Change& y){return x.n>y.n;}
bool cmp3(const Change& x,const Change& y){return x.r>y.r;}
bool cmp4(const Change& x,const Change& y){return x.o<y.o;}

void Solve()
{
	sort(X+1,X+xc+1,cmp1);
	Fr(i,1,xc)if(X[i].p!=X[i-1].p&&X[i].n>A[X[i].p])
		X[i].n-=A[X[i].p],Y[++yc]=X[i];
	sort(Y+1,Y+yc+1,cmp2);
	Fr(i,1,zc)Z[i].r=Z[i].n;
	Fr(i,1,yc)
	{
		int p=Y[i].p;
		Y[i].r=(long double)(A[p]+Y[i].n)/A[p];
		A[p]+=Y[i].n,Z[++zc]=Y[i];
	}
	sort(Z+1,Z+zc+1,cmp3);
}

int main()
{
	scanf("%d%d%d",&K,&N,&M);
	Fr(i,1,K)scanf("%lld",&A[i]);
	Fr(i,1,N)
	{
		Change c;
		scanf("%d%d%d",&c.o,&c.p,&c.n),c.id=i;
		if(c.o==1)X[++xc]=c;
		else if(c.o==2)Y[++yc]=c;
		else Z[++zc]=c;
	}
	Solve();
	int m=min(zc,M);
	sort(Z+1,Z+m+1,cmp4);
	printf("%d\n",m);
	Fr(i,1,m)printf("%d ",Z[i].id);
	putchar('\n');
	return 0;
}