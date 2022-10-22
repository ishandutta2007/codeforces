#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

int N,M;

struct Fenwick
{
	int v[1005][1005];
	void Add(int x,int y,int a)
	{
		for(int i=x;i<=N;i+=i&-i)
			for(int j=y;j<=N;j+=j&-j)
				v[i][j]^=a;
	}
	int Ask(int x,int y)
	{
		int r=0;
		for(int i=x;i;i-=i&-i)
			for(int j=y;j;j-=j&-j)
				r^=v[i][j];
		return r;
	}
}T[2][2];


int main()
{
	scanf("%d%d",&N,&M);
	int o,u,d,l,r,w;
	Fr(i,1,M)
	{
		scanf("%d%d%d%d%d",&o,&u,&l,&d,&r);
		if(o==1)
		{
			int q=0;
			q^=T[(u-1)&1][(l-1)&1].Ask(u-1,l-1);
			q^=T[(u-1)&1][r&1].Ask(u-1,r);
			q^=T[d&1][(l-1)&1].Ask(d,l-1);
			q^=T[d&1][r&1].Ask(d,r);
			printf("%d\n",q);
		}
		else
		{
			scanf("%d",&w);
			T[u&1][l&1].Add(u,l,w);
			T[u&1][(r+1)&1].Add(u,r+1,w);
			T[(d+1)&1][l&1].Add(d+1,l,w);
			T[(d+1)&1][(r+1)&1].Add(d+1,r+1,w);
		}
	}
	return 0;
}