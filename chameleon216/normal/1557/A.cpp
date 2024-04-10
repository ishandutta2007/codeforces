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
int N;
ll A[MX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)scanf("%lld",&A[i]);
		sort(A+1,A+1+N);
		Fr(i,1,N)A[i]+=A[i-1];
		double res=A[1]+(double)(A[N]-A[1])/(N-1);
		Fr(i,1,N)res=max(res,(double)A[i]/i+(double)(A[N]-A[i])/(N-i));
		printf("%.10f\n",res);
	}
	return 0;
}