#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;
const int MX=200100;
int N,F[MX],D[MX],X[MX],xc;

struct Edge{int y,nx;}E[MX<<1];
int H[MX],ec;
void Add(int x,int y){E[++ec].y=y,E[ec].nx=H[x],H[x]=ec;}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(x,1,N)scanf("%d",&F[x]),++D[F[x]],Add(F[x],x);
		int c=N;
		Fr(x,1,N)if(D[x]>1)
		{
			int z=0,d=N+1;
			Fe(i,x,y)if(D[y]<d)z=y,d=D[y];
			Fe(i,x,y)if(y!=z)F[y]=0,--D[x],--c;
		}
		xc=0;
		Fr(x,1,N)if(!D[x])X[++xc]=x;
		if(xc)
		{
			int x=X[xc],i=0;
			while(x)
			{
				if(!F[x])
				{
					F[x]=X[++i];
					if(i==xc)break;
				}
				x=F[x];
			}
		}
		printf("%d\n",c);
		Fr(x,1,N)printf("%d ",F[x]);putchar('\n');
		
		memset(F,0,(N+1)*sizeof(int));
		memset(D,0,(N+1)*sizeof(int));
		memset(H,0,(N+1)*sizeof(int)),ec=0;
	}
	return 0;
}