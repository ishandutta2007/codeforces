#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,M;
int F[MX],sz[MX];
int Find(int x){return F[x]==x?x:F[x]=Find(F[x]);}

int Z[MX];
int Count(int n)
{
	int zc=0;
	Fr(x,1,N)if(F[x]==x)
		Z[++zc]=sz[x];
	sort(Z+1,Z+zc+1);
//	printf("Z ");Fr(i,1,zc)printf("%d ",Z[i]);putchar('\n');
	int sum=0;
	Fl(i,zc,max(zc-n,1))sum+=Z[i];
	return sum-1;
}

int main()
{
	scanf("%d%d",&N,&M);
	Fr(i,1,N)F[i]=i,sz[i]=1;
	int num=0;
	Fr(i,1,M)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=Find(x),y=Find(y);
		if(x!=y)F[x]=y,sz[y]+=sz[x];
		else ++num;
		printf("%d\n",Count(num));
	}
	return 0;
}