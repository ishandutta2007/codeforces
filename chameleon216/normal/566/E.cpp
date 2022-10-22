#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <bitset>
#include <vector>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=1005;
int N,B[MX];
bitset<MX> G[MX],E[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)
	{
		int n,x;
		scanf("%d",&n);
		Fr(j,1,n)scanf("%d",&x),G[i][x]=1;
	}
	
	int c=0;
	Fr(i,1,N)Fr(j,i+1,N)
	{
		bitset<MX> g=G[i]&G[j];
		int x=g._Find_first();
		if(x==g.size())continue;
		int y=g._Find_next(x);
		if(y==g.size())continue;
		if(g._Find_next(y)!=g.size())continue;
		if(!E[x][y])
		{
			printf("%d %d\n",x,y);
			E[x][y]=E[y][x]=1,B[x]=B[y]=1,++c;
		}
	}
	
	if(c==0)
	{
		Fr(x,2,N)printf("1 %d\n",x);
	}
	else if(c==1)
	{
		int u=0,v=0,b=0;
		bitset<MX> h;
		Fr(x,1,N)if(B[x])
		{
			if(u)v=x;
			else u=x;
		}
		Fr(x,1,N)if(!B[x])
		{
			bitset<MX> g;
			Fr(i,1,N)if(G[i][x])g[i]=1;
			if(!b)b=1,h=g;
			printf("%d %d\n",g==h?u:v,x);
		}
	}
	else
	{
		Fr(x,1,N)if(!B[x])
		{
			bitset<MX> g;
			int z=MX;
			Fr(i,1,N)if(G[i][x])
			{
				int zz=G[i].count();
				if(zz<z)g=G[i],z=zz;
			}
			Fr(y,1,N)if(!B[y])g[y]=0;
			Fr(y,1,N)if(B[y])
			{
				bitset<MX> h=E[y];
				h[y]=1;
				if(g==h){printf("%d %d\n",x,y);break;}
			}
		}
	}
	return 0;
}