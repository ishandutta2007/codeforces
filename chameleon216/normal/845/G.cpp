#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=100100,W=26;
int N,M;


struct DisjointSet
{
	int f[MX],w[MX];
	void Build(){Fr(i,1,N)f[i]=i;}
	void Compress(int x)
	{
		if(f[x]==x)return;
		Compress(f[x]);
		w[x]^=w[f[x]];
		f[x]=f[f[x]];
	}
	int Union(int x,int y,int v)
	{
		Compress(x),Compress(y);
		if(f[x]==f[y])return w[x]^w[y]^v;
		w[f[x]]=w[x]^w[y]^v;
		f[f[x]]=f[y];
		return -1;
	}
}T;


int P[70];
void Ins(int x)
{
	Fl(i,W,0)if(x>>i&1)
	{
		if(P[i])x^=P[i];
		else {P[i]=x;return;}
	}
}

int MinXor(int r)
{
	Fl(i,W,0)if(P[i]&&(r>>i&1))
		r^=P[i];
	return r;
}


int main()
{
	scanf("%d%d",&N,&M);
	T.Build();
	Fr(i,1,M)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		int r=T.Union(x,y,w);
		if(r!=-1)Ins(r);
	}
	printf("%d\n",MinXor(T.Union(1,N,0)));
	return 0;
}