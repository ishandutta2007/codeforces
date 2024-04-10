#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fe(i,u,v) for(int i=H[u],v=E[i].y;i;i=E[i].nx,v=E[i].y)
using namespace std;
typedef long long ll;

const int MX=100100;
int N,A[MX];

bool Check()
{
	int b=1;
	Fr(i,1,N)if(A[i]==1){b=0;break;}
	if(b)return 1;
	Fr(i,2,N)if(A[i]-A[i-1]==1)return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	Fr(t_,1,t)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]);
		sort(A+1,A+N+1);
		N=unique(A+1,A+N+1)-A-1;
		printf(Check()?"YES\n":"NO\n");
	}
	return 0;
}