#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j, ik;
	map<string,int> mp;
	string s;
	
	scanf( "%d %d 0.%d", &n, &m, &ik );
	
	for ( i = 1; i <= n; i++ )
	{
		cin >> s >> j;
		if ( (int)(ik*j) >= 10000 )
		{
			mp[s] = (int)(ik*j);
		}
	}
	
	for ( i = 1; i <= m; i++ )
	{
		cin >> s;
		if ( mp.find( s ) == mp.end() )
			mp[s] = 0;
	}
	printf( "%d\n", mp.size() );
	for ( map<string,int>::iterator it = mp.begin(); it != mp.end(); it++ )
	{
		cout << (it->first) << " " << (it->second)/100 << endl;
	}
	return 0;
}