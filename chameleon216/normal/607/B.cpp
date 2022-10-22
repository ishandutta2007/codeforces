#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
#define Fill(x,n) memset((x),(n),sizeof(x))
using namespace std;
typedef long long ll;
const int MX=600,Inf=0x3f3f3f3f;
int N,A[MX];
int dp[MX][MX];



int main()
{
	scanf("%d",&N);
	Fr(i,1,N)scanf("%d",A+i);
	Fl(l,N,1)Fr(r,l,N)
	{
		int &d=dp[l][r],c=0;
		d=Inf;
		while(l+c<=r-c&&A[l+c]==A[r-c])++c;
		if(r-l+1<=2*c){d=1;continue;}
		Fr(k,1,c)d=min(d,dp[l+k][r-k]);
		Fo(k,l,r)d=min(d,dp[l][k]+dp[k+1][r]);
	}
	printf("%d\n",dp[1][N]);
	return 0;
}