#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0);
	string s, t;
	cin >> s;
	cin >> t;
	int pos = 0;
	for(int i=0;i<t.length();++i)
	{
		if(s.at(pos) == t.at(i))
			++pos;
	}
	cout << pos+1 << endl;
	return 0;
}