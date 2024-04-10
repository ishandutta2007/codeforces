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
const int MX=1100;
int N,A[MX];
int stk[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%d",&A[i]);
		int tp=0;
		Fr(i,1,N)
		{
			if(A[i]==1)stk[++tp]=A[i];
			else
			{
				while(stk[tp]+1!=A[i])--tp;
				++stk[tp];
			}
			Fr(j,1,tp)printf("%d%c",stk[j],".\n"[j==tp]);
		}
	}
	return 0;
}