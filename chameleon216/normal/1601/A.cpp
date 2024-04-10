#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

int GCD(int a,int b){return b?GCD(b,a%b):a;}

const int W=30;

int mian()
{
	int N;
	scanf("%d",&N);
	int cnt[40];
	memset(cnt,0,sizeof(cnt));
	Fr(i,1,N)
	{
		int a;
		scanf("%d",&a);
		Fo(j,0,W)cnt[j]+=a>>j&1;
	}
//	Fo(i,0,W)printf("%d ",cnt[i]);putchar('\n');
	int g=0;
	Fo(i,0,W)g=GCD(g,cnt[i]);
	Fr(i,1,N)if(g%i==0)printf("%d ",i);
	putchar('\n');
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t --> 0)
	{
		mian();
	}
}