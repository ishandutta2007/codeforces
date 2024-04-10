// I AK IOI
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MX=105,MY=100100;
int N,X[MX],dp[MY];

int main()
{
	scanf("%d",&N);
	int sum=0;
	Fr(i,1,N)scanf("%d",&X[i]),sum+=X[i];
	if(sum&1){printf("0\n");return 0;}
	dp[0]=1;
	Fr(i,1,N)Fl(j,sum/2,X[i])dp[j]|=dp[j-X[i]];
	if(!dp[sum/2]){printf("0\n");return 0;}
	int a=1;
	Fr(i,2,N)if((X[i]&-X[i])<(X[a]&-X[a]))a=i;
	printf("1\n%d\n",a);
	return 0;
}