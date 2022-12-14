#include <cstdio>
#include <cstring>

char a[100020];
char d[100020], c[100020];
int bc[16], bd[16];
int m[16];

int min( int x, int y )
{
	if ( x < y ) return x;
	return y;
}

int main()
{
	int i, j, k, l;
	int p, b9, b0;
	
	scanf( "%s", a );
	
	memset( bc, 0, sizeof( bc ) );
	memset( bd, 0, sizeof( bd ) );
	
	l = strlen( a );
	for ( i = 0; i < l; i++ )
	{
//		printf( "OP %d\n", i );
		bc[a[i]-'0']++;
		bd[a[i]-'0']++;
	}
	
	memset( m, 0, sizeof( m ) );
	for ( i = 1; i <= 5; i++ )
	{
		m[i] = 0;
		if ( bc[i] > 0 && bd[10-i] > 0 )
		{
			bc[i]--;
			bd[10-i]--;
			m[i]++;
			for ( j = 0; j <= 4; j++ )
			{
				m[i] = m[i] + min( bc[j], bd[9-j] ) + min( bc[9-j], bd[j] );
			}
			bc[i]++;
			bd[10-i]++;
		}
	}
	k = 0;
	for ( i = 1; i <= 5; i++ )
	{
		if ( m[i] > m[k] ) k = i;
	}
	d[l] = '\0'; c[l] = '\0';
	p = l-1;
	if ( k == 1 ) b9 = bc[9]-1;
	else b9 = bc[9];
	b0 = bc[0]-b9;
	while ( b0 > 0 )
	{
		d[p] = '0';
		c[p] = '0';
		bc[0]--;
		bd[0]--;
		b0--;
		p--;
	}
//	printf( "%d %d %d\n", k, m[0], m[1] );
	if ( k != 0 )
	{
		c[p] = k+'0';
		d[p] = 10-k+'0';
		bc[k]--;
		bd[10-k]--;
		p--;
	}
	for ( j = 0; j <= 9; j++ )
	{
		while ( bc[j] > 0 && bd[9-j] > 0 )
		{
			bc[j]--;
			bd[9-j]--;
			c[p] = j+'0';
			d[p] = 9-j+'0';
			p--;
		}
	}
	while ( 1 )
	{
		for ( j = 0; j <= 9; j++ )
		{
			if ( bc[j] > 0 )
				break;
		}
		for ( k = 0; k <= 9; k++ )
			if ( bd[k] > 0 )
				break;
		if ( j <= 9 && k <= 9 )
		{
			bc[j]--;
			bd[k]--;
			c[p] = j+'0';
			d[p] = k+'0';
			p--;
		}
		else break;
	}
//	printf( "END!!\n" );
	printf( "%s\n", c );
	printf( "%s\n", d );
	return 0;
}