#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string x, y, z;
	cin >> x >> y;
	int bad = 0;
	if(x.length() != y.length())
		bad = 1;
	for(int i=0;i<x.length() && bad == 0;++i)
	{
		if(y.at(i) > x.at(i))
		{
			bad = 1;
			break;
		}
		z += y.at(i);
	}
	if(bad == 1)
		cout << -1 << endl;
	else
		cout << z << endl;


	return 0;
}