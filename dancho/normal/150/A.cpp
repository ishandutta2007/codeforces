#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long,int> pii;

vector<pii> fac;

void split( long long q, long long ld )
{
	int j;
	for ( long long i = ld; i*i <= q; i++ )
	{
		if ( q%i == 0 )
		{
			j = 0;
			while ( q%i == 0 )
			{
				q = q / i;
				j++;
			}
			fac.push_back( make_pair( i, j ) );
			split( q, i+1 );
			return;
		}
	}
	if ( q > 1 )
	{
		fac.push_back( make_pair( q, 1 ) );
	}
}


int main()
{
	long long q;
	long long k;
	cin >> q;
	if ( q == 1 )
	{
		cout << 1 << endl << 0 << endl;
		return 0;
	}
	split( q, 2 );
	
	/*for ( int i = 0; i < fac.size(); i++ )
	{
		cout << i << " " << fac[i].first << " " << fac[i].second << endl;
	}*/
	
	if ( fac.size() > 2 )
	{
		k = fac[0].first*fac[1].first;
//		k = q/k;
		cout << 1 << endl << k << endl;
		return 0;
	}
	if ( fac.size() == 2 )
	{
		if ( fac[0].second > 1 )
		{
			k = fac[0].first*fac[0].first;
//			k = q/k;
			cout << 1 << endl << k << endl;
		}
		else if ( fac[1].second > 1 )
		{
			k = fac[1].first*fac[1].first;
//			k = q/k;
			cout << 1 << endl << k << endl;
		}
		else
			cout << 2 << endl;
		return 0;
	}
	if ( fac.size() == 1 )
	{
		if ( fac[0].second == 1 )
		{
			cout << 1 << endl << 0 << endl;
		}
		else if ( fac[0].second == 2 )
		{
			cout << 2 << endl;
		}
		else
		{
			k = fac[0].first*fac[0].first;
//			k = q/k;
			cout << 1 << endl << k << endl;
		}
	}
	return 0;
}