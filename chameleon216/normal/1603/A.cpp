#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
typedef long long ll;

const int MX=300100;
int N,A[MX];

int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",&A[i]);
	Fr(i,1,N)
	{
		int b=1;
		Fr(j,1,i)if(A[i]%(j+1)){b=0;break;}
		if(b)return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		int r=mian();
		printf(r?"YES\n":"NO\n");
	}
	return 0;
}