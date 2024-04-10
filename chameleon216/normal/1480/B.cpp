#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=300000;

int N;
struct Pt{ll a,h;}H,M[MX];
bool operator<(const Pt& x,const Pt& y)
{
	return x.a<y.a;
}

int mian()
{
	scanf("%lld%lld%d",&H.a,&H.h,&N);
	Fr(i,1,N)scanf("%lld",&M[i].a);
	Fr(i,1,N)scanf("%lld",&M[i].h);
	sort(M+1,M+1+N);
	Fr(i,1,N)
	{
		if(H.h<=0)return 0;
		int e=(M[i].h-1)/H.a+1;
		H.h-=(e-1)*M[i].a;
		if(H.h<=0)return 0;
		H.h-=M[i].a;
	}
	return 1;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int res=mian();
		if(res)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}