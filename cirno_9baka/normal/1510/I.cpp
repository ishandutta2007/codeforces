#include "iostream"
#include "algorithm"
#include "cstring"
#include "cstdio"
#include "cmath"
#include "vector"
#include "map"
#include "set"
#include "queue"
#include "ctime"
using namespace std;
#define MAXN 100006
//#define int long long
#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x) (x).begin() , (x).end()
#define mem( a ) memset( a , 0 , sizeof a )
typedef long long ll;
int n , m;

char S[MAXN];
int fl[MAXN];
int mn[2];

void solve() {
	cin >> n >> m;
	rep( i , 1 , m ) {
		scanf( "%s" , S + 1 );
		mn[0] = mn[1] = 0x3f3f3f3f;
		int s0 = 0;
		rep( j , 1 , n ) {
			mn[S[j] - '0'] = min( mn[S[j] - '0'] , fl[j] );
			if( S[j] - '0' == 0 ) ++ s0;
		}
		int mm = min( mn[0] , mn[1] );
		double s[2];
		s[0] = s[1] = 0;
		rep( j , 1 , n ) {
			s[S[j] - '0'] += pow( 0.9 , fl[j] - mm );
		}
		if( s[0] > s[1] * 2 ) {
			puts( "0" );
		} else if( s[1] > s[0] * 2 )
			puts("1");
		else puts( rand() % 2 ? "1" : "0" );
		fflush( stdout );
		int cc = 0;
		scanf("%d",&cc);
		rep( j , 1 , n ) if( S[j] - '0' != cc ) ++ fl[j];
	}
}

signed main() {
	srand(time(0));
//   int T;cin >> T;while( T-- ) solve();
	solve();
}