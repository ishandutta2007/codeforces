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
ll A[MX];

int mian()
{
	int N;
	scanf("%d",&N);
	Fr(i,1,N)scanf("%lld",A+i);
	sort(A+1,A+1+N);
	ll a=0,b=0;
	int now=1;
	Fl(i,N,1)
	{
		if(now)
		{
			if(A[i]%2==0)a+=A[i];
		}
		else
		{
			if(A[i]%2==1)b+=A[i];
		}
		now^=1;
	}
	if(a>b)printf("Alice\n");
	else if(a==b)printf("Tie\n");
	else printf("Bob\n");
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}