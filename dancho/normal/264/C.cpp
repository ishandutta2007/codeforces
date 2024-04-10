#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, q;
long long v[100020];
int c[100020];
long long a, b;

long long dp[100020];
long long mx[100020];
bool us[100020];
long long mxg1, mxc1, mxg2, mxc2;

int main()
{
	int i, j, k;
	
	long long ans = 0;
	scanf( "%d %d", &n, &q );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &k );
		v[i] = k;
	}

	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &c[i] );
	}
	
	for ( i = 1; i <= q; i++ )
	{
		ans = 0;
		scanf( "%d %d", &j, &k );
		a = j; b = k;
		mxg1 = mxg2 = -(1LL<<60);
		mxc1 = mxc2 = 0;
		memset( mx, 128, sizeof( mx ) );
//		cout << mx[0] << " " << mxg1 << " " << (mx[0] < mxg1) << endl;
//		cout << mx[0] - 10000000000LL << endl;
		memset( us, 0, sizeof( us ) );
		for ( j = 1; j <= n; j++ )
		{
			if ( us[ c[j] ] )
				dp[j] = a*v[j] + mx[ c[j] ];
			if ( !us[ c[j] ] )
				dp[j] = b*v[j];
			dp[j] = max( dp[j], b*v[j] );
			if ( mxc1 )
			{
				if ( mxc1 == c[j] )
				{
					if ( mxc2 )
					{
						dp[j] = max( dp[j], b*v[j] + mxg2 );
					}
				}
				else
					dp[j] = max( dp[j], b*v[j] + mxg1 );
			}
			ans = max( ans, dp[j] );
			mx[ c[j] ] = max( mx[ c[j] ], dp[j] );
			us[ c[j] ] = 1;
			
			if ( dp[j] >= mxg1 )
			{
				if ( c[j] == mxc1 )
				{
					mxg1 = dp[j];
				}
				else
				{
					mxg2 = mxg1;
					mxc2 = mxc1;
					mxg1 = dp[j];
					mxc1 = c[j];
				}
			}
			else if ( dp[j] > mxg2 && c[j] != mxc1 )
			{
				mxc2 = c[j];
				mxg2 = dp[j];
			}
//			cout << "DP " << j << " " << dp[j] << " (" << a << " " << b << " " << v[j] << ") " << endl;
		}
		cout << ans << endl;
	}
	return 0;
}