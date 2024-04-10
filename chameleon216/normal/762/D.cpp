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

template<typename T1,typename T2>
inline void max_eq(T1& a,T2 b){if(a<b)a=b;}
template<typename T1,typename T2>
inline void min_eq(T1& a,T2 b){if(b<a)a=b;}

const int MX=100100;
//const Inf=0x3f3f3f3f3f3f3f3f;
int N;
ll A[MX][3],dp[MX][5];

/*
*  0 1 2 3  4
*  > o o >1 >3
*  o > o <2 <2
*  o o > >3 >1
*/

int main()
{
	scanf("%d",&N);
	Fo(i,0,3)Fr(j,1,N)scanf("%lld",&A[j][i]);
	memset(dp,0xc0,(N+2)*sizeof(dp[0]));
	dp[0][0]=0;
	Fr(i,1,N)
	{
		ll *d=dp[i-1],*e=dp[i],*a=A[i];
		max_eq(e[0],d[0]+a[0]);
		max_eq(e[1],d[0]+a[0]+a[1]);
		max_eq(e[2],d[0]+a[0]+a[1]+a[2]);
		max_eq(e[3],d[0]+a[0]+a[1]+a[2]);
		max_eq(e[0],d[1]+a[0]+a[1]);
		max_eq(e[1],d[1]+a[1]);
		max_eq(e[2],d[1]+a[1]+a[2]);
		max_eq(e[0],d[2]+a[0]+a[1]+a[2]);
		max_eq(e[1],d[2]+a[1]+a[2]);
		max_eq(e[2],d[2]+a[2]);
		max_eq(e[4],d[2]+a[0]+a[1]+a[2]);
		max_eq(e[2],d[3]+a[0]+a[1]+a[2]);
		max_eq(e[3],d[3]+a[0]+a[1]+a[2]);
		max_eq(e[0],d[4]+a[0]+a[1]+a[2]);
		max_eq(e[4],d[4]+a[0]+a[1]+a[2]);
	}
	printf("%lld\n",dp[N][2]);
	return 0;
}