#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#define rg register
#define Fo(i,a,b) for(int i=(a);i< (b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=120000;

int N;
int X[MX];
int cnt[MX];
int mian()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",X+i);
	int x=N,y=N;
	Fl(i,N,1)
	{
		if(X[i]==x)
		{
			Fr(j,i,y)cnt[X[j]]=1,printf("%d ",X[j]);
			y=i-1;
			while(cnt[x])--x;
		}
	}
	putchar('\n');
	Fr(i,1,N)cnt[i]=X[i]=0;
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}