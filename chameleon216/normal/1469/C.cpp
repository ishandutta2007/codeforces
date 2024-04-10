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
const int MX=2e5+100;
int N,K,H[MX];
int U[MX],D[MX];

int mian()
{
	scanf("%d%d",&N,&K);
	Fr(i,1,N)scanf("%d",H+i);
	U[1]=D[1]=H[1]+1;
	Fr(i,2,N)
	{
		U[i]=min(U[i-1]+K-1,H[i]+K);
		D[i]=max(D[i-1]-K+1,H[i]+1);
		if(D[i]>U[i])return 0;
	}
	//Fr(i,1,N)printf("%d %d\n",U[i],D[i]);
	if(!(D[N]<=H[N]+1&&H[N]+1<=U[N]))return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)printf(mian()?"YES\n":"NO\n");
}