#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PQ priority_queue
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define cls(ar,val) memset ( ar, val, sizeof ( ar ) )
#define debug(a) cerr<<#a<<"=="<<a<<endl
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))
const int inf = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int maxn = 1e3 + 10;
int a[maxn];
int n, k;
int main() {
	scanf("%d%d",&n,&k);
	lp(i,0,k)
		scanf("%d",a + i);
	int xx=n, yy=2*n;
	lp(i,0,k) {
		int d = min(a[i]/4,xx);
		xx -= d;
		a[i] -= 4 * d;
	}
	yy += xx;
	lp(i,0,k){
		int d = min(a[i]/2, yy);
		yy-=d;
		a[i]-=2 * d;
	}
	int c=yy+xx;
	lp(i,0,k)	c-=a[i];
	printf("%s\n", c >= 0 ? "YES" : "NO");
	return 0;
}