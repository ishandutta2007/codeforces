#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=1000100,W=19;
int M,F[MX][W],D[MX],tc;

int Grow(int f)
{
	int x=++tc;
	F[x][0]=f,D[x]=D[f]+1;
	Fr(i,1,W-1)F[x][i]=F[F[x][i-1]][i-1];
	return x;
}

int LCA(int x,int y)
{
	if(D[x]<D[y])swap(x,y);
	Fl(i,W-1,0)if(D[x]-D[y]>=1<<i)
		x=F[x][i];
	if(x==y)return x;
	Fl(i,W-1,0)if(F[x][i]!=F[y][i])
		x=F[x][i],y=F[y][i];
	return F[x][0];
}

int Dis(int x,int y)
{
	int z=LCA(x,y);
	return D[x]+D[y]-2*D[z];
}

int main()
{
	scanf("%d",&M);
	D[++tc]=1;
	Fr(i,2,4)Grow(1);
	int u=2,v=3,d=2;
	Fr(i,1,M)
	{
		int f;
		scanf("%d",&f);
		int x=Grow(f);
		int du=Dis(x,u),dv=Dis(x,v),m=max(d,max(du,dv));
		if(du==m)d=du,v=x;
		else if(dv==m)d=dv,u=x;
		Grow(f);
		printf("%d\n",d);
	}
	return 0;
}