#include <cstdio>
#include <cstring>

const int mod = 1000000007;

int m;
int dm[16];

long long cnt[16];

long long gogo( int par, int msum, long long us[] )
{
	if ( par > 6 )
		return 1;
	
	long long sol = 0;
	for ( int i = 0; i <= msum; i++ )
	{
		if ( us[i] < cnt[i] )
		{
			us[i]++;
			sol = sol + (long long)(cnt[i]-(us[i]-1))*gogo( par+1, msum-i, us );
			if ( sol >= mod ) sol %= mod;
			us[i]--;
		}
	}
	return sol;
}

int main()
{
	int i, j, k, l;
	int ma;
	
	scanf( "%d", &m );
	k = m;
	for ( i = 0; i < 10; i++ )
	{
		dm[9-i] = m % 10;
		m = m / 10;
	}
	m = k;
	
	memset( cnt, 0, sizeof( cnt ) );
	for ( ma = 0; ma < (1<<9); ma++ )
	{
		k = ma*2;
		l = 0;
		for ( i = 0; i < 10; i++ )
			if ( k&(1<<i) )
				l++;
		if ( l == 0 ) continue;
		for ( i = 0; i < 10; i++ )
		{
			bool fl = 0;
			if ( k&(1<<i) )
			{
				for ( j = 4; j <= 7; j += 3 )
				{
					if ( j == dm[i] )
						fl = 1;
					if ( j < dm[i] )
					{
						//add_all i+1..9
						int add = 1;
						for ( int s = i+1; s < 10; s++ )
						{
							if ( k&(1<<s) )
								add *= 2;
							else add *= 8;
						}
//						printf( "GOGO1 MA %d %d %d %d %d\n", k, l, j, i, add );
						cnt[l] += add;
					}
				}
			}
			else
			{
				for ( j = 0; j < 10; j++ )
				{
					if ( j == 4 || j == 7 ) continue;
					if ( j == dm[i] )
						fl = 1;
					if ( j < dm[i] )
					{
						//add_all i+1..9
						int add = 1;
						for ( int s = i+1; s < 10; s++ )
						{
							if ( k&(1<<s) )
								add *= 2;
							else add *= 8;
						}
//						printf( "GOGO2 MA %d %d %d %d\n", k, l, j, add );
						cnt[l] += add;
					}
				}
			}
			if ( !fl ) break;
		}
		if ( i == 10 )
		{
//			printf( "END %d %d __ %d %d\n", k, l, dm[7], k&(1<<7) );
			cnt[l]++;
		}
	}
	
	cnt[0] = 0;
	for ( i = 1; i <= 10; i++ )
		cnt[0] += cnt[i];
	if ( cnt[0] > m ) while ( 1 ) ;
	cnt[0] = m-cnt[0];
		
	long long us[16];
	memset( us, 0, sizeof( us ) );
	
	long long ans = 0;
	for ( i = 9; i > 0; i-- )
	{
//		printf( "%d %d\n", i, cnt[i] );
		memset( us, 0, sizeof( us ) );
		ans = ans + (long long)( cnt[i]*gogo( 1, i-1, us ))%mod;
		if ( ans >= mod ) ans %= mod;
	}
	printf( "%d\n", (int) ans );
	return 0;
}