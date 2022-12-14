// !!! %I64d !!!

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

long long MAX( long long a, long long b )
{
	if ( a > b ) return a;
	return b;
}

int n, m;
long long r[200020], psr[200020];
int li[200020], ri[200020];
long long pi[200020];

vector<int> iv[200020];

long long dp[200020];

long long itmx[1<<19];
long long itsm[1<<19];

void upd( int nd, int nl, int nr, int l, int r, long long v )
{
	if ( ( nl > r ) || ( l > nr ) ) return;
	if ( ( l <= nl ) && ( nr <= r ) )
	{
		itsm[nd] += v;
		itmx[nd] += v;
		return;
	}
	
	long long k = itsm[nd];
	itsm[nd] = 0;
	itsm[2*nd] += k;
	itmx[2*nd] += k;
	itsm[2*nd+1] += k;
	itmx[2*nd+1] += k;
	upd( 2*nd, nl, (nl+nr)/2, l, r, v );
	upd( 2*nd+1, (nl+nr)/2+1, nr, l, r, v );
	itmx[nd] = MAX( itmx[2*nd], itmx[2*nd+1] );
}

long long queryMin()
{
	return itmx[1];
}

void update( int l, int r, long long v )
{
	if ( r < l ) return;
//	cout << "ADD " << l << " " << r << " " << v << endl;
	upd( 1, 1, (1<<18), l, r, v );
}

int main()
{
	int i, j, k;
	long long ans = 0, all = 0;
	
	scanf( "%d %d", &n, &m );
	psr[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		r[i] = k;
		psr[i] = psr[i-1] + r[i];
	}
	
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d %d", &li[i], &ri[i], &j );
//		cout << "INTERVAL " << li[i] << " " << ri[i] << " " << j << endl;
		pi[i] = j;
		
		iv[ri[i]].push_back( i );
	}
	
	memset( itmx, 0, sizeof( itmx ) );
	memset( itsm, 0, sizeof( itsm ) );
	
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 0; (unsigned)j < iv[i].size(); j++ )
		{
			k = iv[i][j];
			update( 1, li[k]-1, pi[k] );
			all += pi[k];
		}
		dp[i] = MAX( 0, -psr[i] + itmx[1] );
		dp[i] = MAX( dp[i], all - psr[i] );
//		cout << i << " " << dp[i] << " " << itmx[1] << " " << psr[i] << " __ " << all << endl;
		update( i, i, ans + psr[i] );
		ans = MAX( ans, dp[i] );
//		update( i, i, dp[i] + psr[i] );
	}
	cout << ans << endl;
	return 0;
}