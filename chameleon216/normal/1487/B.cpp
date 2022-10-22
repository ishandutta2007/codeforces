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


int mian()
{
	int N,K;
	scanf("%d%d",&N,&K),--K;
	if(N&1)
	{
		int e=N/2;
		K+=K/e;
		printf("%d\n",K%N+1);
	}
	else
	{
		printf("%d\n",K%N+1);
	}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}