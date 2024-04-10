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
int lowbit(int x){return x&-x;}

void mian()
{
	int X,Y,N;
	scanf("%d%d%d",&X,&Y,&N);
	if(lowbit(X)*lowbit(Y)>=N)printf("YES\n");
	else printf("NO\n");
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
}