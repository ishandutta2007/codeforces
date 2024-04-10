#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=120000;
int N;
struct Pt{int a,b;}P[MX];
bool operator<(const Pt& x,const Pt& y)
	{return x.a<y.a;}
int R[MX],F[MX];
int Find(int x){return lower_bound(R+1,R+1+N,x)-R-1;}

int D[MX];

int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d%d",&P[i].a,&P[i].b);
	sort(P+1,P+1+N);
	Fr(i,1,N)R[i]=P[i].a;
	Fr(i,1,N)F[i]=Find(R[i]-P[i].b);
	int ans=0;
	Fr(i,1,N)D[i]=D[F[i]]+1,ans=max(ans,D[i]);
	printf("%d\n",N-ans);
	return 0;
}