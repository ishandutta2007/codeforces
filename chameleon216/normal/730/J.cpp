#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;
const int MX=105,W=10000,Inf=0x3f3f3f3f;
int N,K;
struct Bottle{int a,b;}P[MX];
bool operator<(const Bottle& x,const Bottle& y)
	{ return x.b>y.b; }

int D[MX][MX*MX];


int main()
{
	scanf("%d",&N);
	int sum=0,svm=0;
	Fr(i,1,N)scanf("%d",&P[i].a),sum+=P[i].a;
	Fr(i,1,N)scanf("%d",&P[i].b);
	sort(P+1,P+1+N);
	while(svm<sum)svm+=P[++K].b;
	Fr(i,1,N)P[i].b-=P[i].a;
	memset(D,0x3f,sizeof(D));
	D[0][0]=0;
	Fr(n,1,N)
	{
		Fl(k,min(K,n),0)Fr(s,0,W)
		{
			D[k][s]+=P[n].a;
			if(k&&s>=P[n].b)D[k][s]=min(D[k][s],D[k-1][s-P[n].b]);
		}
	}
	int ans=Inf;
	Fr(s,0,W)if(s>=D[K][s])ans=min(ans,D[K][s]);
	printf("%d %d\n",K,ans);
	return 0;
}