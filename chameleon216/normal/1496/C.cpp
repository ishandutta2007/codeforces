#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#include <cmath>
#define rg register
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=110000;
ll Abs(ll x){return x>=0?x:-x;}
int N;

double A[MX],B[MX];

int mian()
{
	scanf("%d",&N);
	int ac=0,bc=0;
	Fr(i,1,2*N)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=Abs(x),y=Abs(y);
		if(!x)A[++ac]=y;
		else B[++bc]=x;
	}
	sort(A+1,A+1+N);
	sort(B+1,B+1+N);
	double ans=0;
	Fr(i,1,N)ans+=sqrt(A[i]*A[i]+B[i]*B[i]);
	printf("%.15f\n",ans);
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)mian();
	return 0;
}