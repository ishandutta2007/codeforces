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
const int MX=240;

int Sign(int x){return x<0?-1:x>0;}
void mian()
{
	int N;
	scanf("%d",&N);
	Fr(x,0,N-1)Fr(y,x+1,N-1)printf("%d ",Sign((x-y+N)%N-(y-x+N)%N));
	putchar('\n');
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}