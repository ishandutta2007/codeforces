#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <set>
using namespace std;

int n;
int a[16];
bool fr[16];

char ip[64];
char fip[64];

set<string> ips;

void ok( int len )
{
	int i, j;
	long long a;
	j = 0;
	fip[len] = '\0';
	for ( int p = 0; p < 4; p++ )
	{
		if ( j >= len ) return;
		i = j;
		while ( ( fip[i] != '.' ) && ( i < len ) )
		{
			i++;
		}
		if ( i == j ) return;
		if ( i-j > 1 && fip[j] == '0' )
			return;
		a = 0LL;
		for ( int l = j; l < i; l++ )
			a = a * 10LL + fip[l]-'0';
		if ( a > 255 )
			return;
		j = i+1;
	}
	fip[len] = '\0';
	ips.insert( fip );
}

void fin( int p, int fp, int len, int rd )
{
	if ( p >= len )
	{
		ok( len+3 );
		return;
	}
	if ( rd )
	{
		fip[fp] = '.';
		fin( p, fp+1, len, rd-1 );
	}
	fip[fp] = ip[p];
	fin( p+1, fp+1, len, rd );
}

void finish( int len )
{
	bool us[16];
	memset( us, 0, sizeof( us ) );
	for ( int i = 0; i < len; i++ )
		us[ ip[i]-'0' ] = 1;
	for ( int i = 0; i < 11; i++ )
		if ( us[i] != fr[i] )
			return;
	fin( 0, 0, len, 3 );
}

void gen( int p, int len )
{
	if ( p+p >= len )
	{
		finish( len );
		return;
	}
	for ( int i = 1; i <= n; i++ )
	{
		ip[p] = '0' + a[i];
		ip[len-1-p] = ip[p];
		gen( p+1, len );
	}
	return;
}

int main()
{
	int i;
	
	memset( fr, 0, sizeof( fr ) );
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		fr[ a[i] ] = 1;
	}
	
	for ( i = 3; i <= 12; i++ )
	{
		gen( 0, i );
	}
	
	printf( "%d\n", ips.size() );
	for ( set<string>::iterator it = ips.begin(); it != ips.end(); it++ )
	{
		printf( "%s\n", (*it).c_str() );
	}
	return 0;
}