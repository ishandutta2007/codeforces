#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

typedef pair<int,int> pii;

int h, m, n;

pii pos[ 200020 ];

map<int,pii> mp;

int la;
vector< vector<int> > it;

void add( int tr, int pos, int val )
{
	for ( int i = pos, sz = it[tr].size(); i < sz; i = i+(i&(-i)) )
	{
		it[tr][i] = it[tr][i] + val;
	}
}

int query( int tr, int pos )
{
	int res = 0;
	for ( int i = pos; i > 0; i = i-(i&(-i)) )
	{
		res = res + it[tr][i];
	}
	return res;
}

int query( int tr, int le, int ri )
{
	return query( tr, ri ) - query( tr, le-1 );
}

int main()
{
	int i, j, k, tr;
	int le, ri, mi, st;
	long long sol = 0;
	
	char op[8];
	
	scanf( "%d %d %d", &h, &m, &n );
	
	memset( pos, -1, sizeof( pos ) );
	la = -1;
	for ( i = 0; i < h; i++ )
	{
		if ( pos[i].first == -1 )
		{
			la++;
			it.push_back( vector<int>() );
			it[la].push_back( 0 );
			
			pos[i] = make_pair( la, 1 );
			it[la].push_back( 0 );
			
			for ( j = i+m, k = 2; j != i; j=j+m )
			{
				if ( j >= h ) j = j - h;
				if ( j == i ) break;
				
				pos[j] = make_pair( la, k );
				k++;
				it[la].push_back( 0 );
			}
		}
	}
	
	//for ( i = 0; i < h; i++ )
		//printf( "POS %d :: %d %d\n", i, pos[i].first, pos[i].second );
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%s", op );
		if ( op[0] == '+' )
		{
			scanf( "%d %d", &j, &k );
			tr = pos[k].first;
			if ( query( tr, pos[k].second, it[tr].size()-1 ) == (int)it[tr].size()-1 - pos[k].second + 1 )
			{
				le = 0; ri = pos[k].second-1;
				st = 1;
			}
			else
			{
				le = pos[k].second-1; ri = it[tr].size()-1;
				st = pos[k].second;
			}
			
			while ( le + 1 < ri )
			{
				mi = (le+ri)/2;
				if ( ( query( tr, st, mi ) == mi-st+1 ) || ( mi < st ) )
				{
					le = mi;
				}
				else ri = mi;
			}
			
			mp[ j ] = make_pair( tr, ri );
			if ( st == pos[k].second )
			{
				sol = sol + ri-st;
//				printf( "ADD %d\n", ri-st );
			}
			else
			{
				sol = sol + ri + (int)it[tr].size()-pos[k].second-1;
//				printf( "ADD2 %d\n", ri + (int)it[tr].size()-pos[k].second-1 );
			}
			add( tr, ri, 1 );
		}
		else if ( op[0] == '-' )
		{
			scanf( "%d", &j );
			add( mp[j].first, mp[j].second, -1 );
			mp.erase( j );
		}
	}
	
	cout << sol << endl;
	return 0;
}