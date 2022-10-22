#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;

int stk[1200],tp;
int mian()
{
	int n,k;tp=0;
	scanf("%d%d",&n,&k);
	Fl(i,n,k+1)stk[++tp]=i;
	int t=(k+1)/2;
	Fl(i,k-1,t)stk[++tp]=i;
	printf("%d\n",tp);
	Fr(i,1,tp)printf("%d ",stk[i]);
	putchar('\n');
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}