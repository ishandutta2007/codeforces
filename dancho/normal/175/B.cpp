#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, string> pis;

int n;
map<string,int> mp;
map<string,string> cat;

vector<pis> v;

int main()
{
	int i, j, k;
	string pl;
	
	map<string,int>::iterator it, jt;
	
	cin >> n;
	for ( i = 1; i <= n; i++ )
	{
		cin >> pl >> k;
		if ( mp.find( pl ) == mp.end() ) mp[pl] = k;
		else
		{
			if ( mp[pl] < k ) mp[pl] = k;
		}
	}
	
	for ( it = mp.begin(), j = 1; it != mp.end(); it++, j++ )
	{
		pl = (it->first);
		k = (it->second);
		v.push_back( make_pair( k, pl ) );
	}
	sort( v.begin(), v.end() );
	
	cout << mp.size() << endl;
	for ( j = 0; j < (int)v.size(); j++ )
	{
		pl = v[j].second;
		k = v[j].first;
		for ( i = j; i < (int) v.size(); i++ )
		{
			if ( v[i].first != k )
				break;
		}
		
		i = i - j;
		if ( 2*(i+j) < (int)mp.size() )
		{
			cat[pl] = "noob";
		}
		else if ( 5*(mp.size()-i-j) > mp.size() )
		{
			cat[pl] = "random";
		}
		else if ( 10*(mp.size()-i-j) > mp.size() )
		{
			cat[pl] = "average";
		}
		else if ( 100*(mp.size()-i-j) > mp.size() )
		{
			cat[pl] = "hardcore";
		}
		else
		{
			cat[pl] = "pro";
		}
		
		cout << pl << " " << cat[pl] << "\n";
	}
	return 0;
}