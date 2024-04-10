#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long S;
int n;
long long a[32];

int mx;

int us[32];

int pr = 0;

long long t[8][8];

bool cmag()
{
	int i, j, k, s;
			s = 0;
			for ( i = 0; i < n; i++ )
				s = s + t[0][i];
			
			for ( i = 0; i < n; i++ )
			{
				k = 0;
				for ( j = 0; j < n; j++ )
					k = k + t[i][j];
				
				if ( k != s ) return 0;
				
				k = 0;
				for ( j = 0; j < n; j++ )
				{
					k = k + t[j][i];
				}
				if ( k != s ) return 0;
			}
	
	k = 0;
	for ( i = 0; i < n; i++ )
	{
		k = k + t[i][i];
	}
	if ( k != s ) return 0;
	
	 k = 0;
	for ( i = 0; i < n; i++ )
	{
		k = k + t[i][n-i-1];
	}
	if ( k != s ) return 0;
	
	return 1;
}

void pf()
{
	cout << "FR: ";
	for ( int i = 0; i < n*n; i++ )
		if ( !us[i] )
			cout << a[i] << " ";
	cout << endl;
}

inline int mark( long long val )
{
	for ( int i = 0; i < n*n; i++ )
	{
		if ( ( a[i] == val ) && ( us[i] == 0 ) )
		{
			us[i] = 1;
			return i;
		}
	}
	return -1;
}

inline void unmark( long long val )
{
	int i;
	for ( i = 0; i < n*n; i++ )
	{
		if ( ( a[i] == val ) && ( us[i] == 1 ) )
		{
			us[i] = 0;
			break;
		}
	}
//	if ( i >= n*n ) while ( 1 ); // ne vliza tuk.
}

bool make4( int st )
{
	if ( st > mx ) mx = st;
	int x;
	if ( st > 7 )
	{
		return cmag();
	}
	if ( st <= 1 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[0][st] = a[i];
					if ( make4( st+1 ) )
						return 1;
				us[i] = 0;
			}
		}
		return 0;
	}
	else if ( st == 2 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[0][2] = a[i];
					t[0][3] = S - t[0][0] - t[0][1] - t[0][2];
					x = mark( t[0][3] );
					if ( x != -1 )
					{
						if ( make4( st+1 ) ) return 1;
						us[x] = 0;
					}
				us[i] = 0;
			}
		}
		return 0;
	}
	else if ( st == 3 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[1][0] = a[i];
				if ( make4( st+1 ) ) return 1;
				us[i] = 0;
			}
		}
		return 0;
	}
	else if ( st == 4 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[2][0] = a[i];
				t[3][0] = S - t[0][0] - t[1][0] - t[2][0];
				x = mark( t[3][0] );
				if ( x != -1 )
				{
					if ( make4( st+1 ) ) return 1;
					us[x] = 0;
				}
				us[i] = 0;
			}
		}
		return 0;
	}
	else if ( st == 5 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[1][2] = a[i];
				t[2][1] = S - t[3][0] - t[1][2] - t[0][3];
				x = mark( t[2][1] );
				if ( x != -1 )
				{
					if ( make4( st+1 ) )
						return 1;
					us[x] = 0;
				}
				us[i] = 0;
			}
		}
		return 0;
	}
	else if ( st == 6 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[2][2] = a[i];
				t[2][3] = S - t[2][0] - t[2][1] - t[2][2];
				t[3][2] = S - t[0][2] - t[1][2] - t[2][2];
				int y;
				x = mark( t[3][2] );
				if ( x != -1 )
				{
					y = mark( t[2][3] );
					if ( y != -1 )
					{
						if ( make4( st+1 ) )
							return 1;
						us[y] = 0;
					}
					us[x] = 0;
				}
				us[i] = 0;
			}
		}
		return 0;
	}
	else if ( st == 7 )
	{
		for ( int i = 0; i < n*n; i++ )
		{
			if ( us[i] == 0 )
			{
				us[i] = 1;
				t[1][1] = a[i];
				t[1][3] = S - t[1][0] - t[1][1] - t[1][2];
				t[3][1] = S - t[0][1] - t[1][1] - t[2][1];
				t[3][3] = S - t[0][0] - t[1][1] - t[2][2];
				
				x = mark( t[3][1] );
				if ( x != -1 )
				{
					int y = mark( t[1][3] );
					if ( y != -1 )
					{
						int z = mark( t[3][3] );
						if ( z != -1 )
						{
							if ( make4( st+1 ) )
								return 1;
							us[z] = 0;
						}
						us[y] = 0;
					}
					us[x] = 0;
				}
				us[i] = 0;
			}
		}
		return 0;
	}
	return 0;
}

int main()
{
	memset( t, 0, sizeof( t ) );
	int i, j;
	long long s;
	
	cin >> n;
	S = 0;
	for ( i = 0; i < n*n; i++ )
	{
		cin >> a[i];
		S = S + a[i];
	}
	
	S = S / n;
	
	memset( us, 0, sizeof( us ) );
	
	mx = -1;
	if ( n <= 3 )
	{
		sort( a, a + n*n );
		do
		{
			for ( i = 0; i < n; i++ )
			{
				for ( j = 0; j < n; j++ )
				{
					t[i][j] = a[ n*i + j ];
				}
			}
			
			if ( cmag() ) break;
		}
		while ( next_permutation( a, a + n*n ) );
	}
	else
	{
		make4( 0 );
	}

			s = 0;
			for ( i = 0; i < n; i++ )
				s = s + t[i][3-i];
	
/*				if ( t[1][2] + t[2][1] + t[3][0] + t[0][3] != S && n == 4 )
				{
					if ( mx == 6 )
						while ( 1 );
				}*/

	/*if ( ( S != s ) && ( n == 4 ) )
	{
		while ( 1 ); // vliza tuka -> ne e qko!
	}*/

	s = S;
	cout << s << endl;
	for ( i = 0; i < n; i++ )
	{
		cout << t[i][0];
		for ( j = 1; j < n; j++ )
			cout << " " << t[i][j];
		printf( "\n" );
	}
	return 0;
}