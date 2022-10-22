#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=200100;
int N,A[MX],id[MX],P[MX];
bool cmp(int i,int j){return A[i]>A[j];}

void Work()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,N)id[i]=i;
	sort(id+1,id+N+1,cmp);
	ll res=0;
	Fr(j,1,N)
	{
		int i=id[j];
		int p=(j+1)/2;
		res+=(ll)2*A[i]*p;
		P[i]=j&1?p:-p;
	}
	printf("%lld\n",res);
	Fr(i,0,N)printf("%d ",P[i]);
	putchar('\n');
	Fr(i,0,N)A[i]=id[i]=P[i]=0;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(i,1,t)Work();
	return 0;
}