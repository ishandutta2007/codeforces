#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <cmath>
#define Fo(i,a,b) for(int i=(a);i<(b);i++)
#define Fr(i,a,b) for(int i=(a);i<=(b);i++)
#define Fl(i,a,b) for(int i=(a);i>=(b);i--)
#define Fill(x,n) memset((x),(n),sizeof(x))
typedef long long ll;
using namespace std;
const int MX=2e5+1000;
int x[MX],y[MX],cnt;
void mian3()
{
	printf(R"(2
3 2
3 2
)");
}
void mian(int N)
{
	int ans=0;
	cnt=0;
	int a=N,b=exp2(0.618*log2(N));
	Fr(i,3,N)if(i!=a&&i!=b)ans++,x[++cnt]=i,y[cnt]=N;
	int ai=a,bi=b;
	while(b!=1)
	{
		a=ceil((double)a/b);
		x[++cnt]=ai,y[cnt]=bi;
		ans++;
		if(a<b)swap(ai,bi),swap(a,b);
	}
	while(a!=1&&ai!=2)ans++,x[++cnt]=ai,y[cnt]=2,a=ceil((double)a/2);
	printf("%d\n",ans);
	Fr(i,1,cnt)printf("%d %d\n",x[i],y[i]);
	//return ans;
}

int main()
{
	//Fr(i,4,100000)if(mian(i)>i+5)printf("%d\n",i);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n==3)mian3();
		else mian(n);
	}
}