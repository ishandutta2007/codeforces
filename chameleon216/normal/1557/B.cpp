#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MX=100100;
int N,K,A[MX],id[MX],rk[MX];

bool Comp(int a,int b)
{
	return A[a]<A[b];
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d%d",&N,&K);
		Fr(i,1,N)scanf("%d",&A[i]);
		Fr(i,1,N)id[i]=i;
		sort(id+1,id+1+N,Comp);
		Fr(i,1,N)rk[id[i]]=i;
		int cnt=1;
		Fr(i,2,N)if(rk[i]-rk[i-1]!=1)++cnt;
		printf(cnt<=K?"Yes\n":"No\n");
	}
	return 0;
}