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

int N,A[15];
bool dfs(int n,int s,int c)
{
	if(c&&!s)return 1;
	if(n>N)return 0;
	Fr(i,-1,1)if(dfs(n+1,s+i*A[n],c+!!i))return 1;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		scanf("%d",&N);
		Fr(i,1,N)
		{
			scanf("%d",&A[i]);
			if(A[i]<0)A[i]=-A[i];
		}
		sort(A+1,A+N+1);
		printf(dfs(1,0,0)?"YES\n":"NO\n");
	}
	return 0;
}