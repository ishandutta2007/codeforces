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
const int MX=1000;

int N,X[MX];
int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",X+i);
	int x=*min_element(X+1,X+1+N);
	int cnt=0;
	Fr(i,1,N)if(X[i]!=x)++cnt;
	printf("%d\n",cnt);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}