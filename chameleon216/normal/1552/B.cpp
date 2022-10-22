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

const int MX=50100,Inf=0x3f3f3f3f;
int N;
struct Item{int x[5];}P[MX];
bool operator<(const Item& a,const Item& b)
{
	int sum=0;
	Fo(i,0,5)sum+=a.x[i]<b.x[i];
	return sum>=3;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)Fo(j,0,5)scanf("%d",&P[i].x[j]);
		int o=1;
		Fr(i,2,N)if(P[i]<P[o])o=i;
		int b=1;
		Fr(i,1,N)if(o!=i&&P[i]<P[o]){printf("-1\n"),b=0;break;}
		if(b)printf("%d\n",o);
	}
	return 0;
}