#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(i,x) memset((i),(x),sizeof(i))
using namespace std;
typedef long long ll;
const int MX=2e5+100,INF=0x7fffffff;

int L=-INF,R=INF;
int N,K[MX],X[MX];

void solve()
{
//	Fr(i,1,N)printf("%d\n",X[i]);
	Fr(i,0,N-1)
	{
		switch(K[i+1])
		{
		case 1:L=max(L,1900-X[i]);break;
		case 2:R=min(R,1899-X[i]);break;
		}
		if(L>R){printf("Impossible\n");return;}
	}
	if(R==INF)printf("Infinity\n");
	else printf("%d\n",R+X[N]);
}

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d%d",X+i,K+i);
	Fr(i,1,N)X[i]+=X[i-1];
	solve();
	return 0;
}