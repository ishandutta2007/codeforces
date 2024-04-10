#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, s, x;

	cin >> t;

	for(; t --; ){
		cin >> n >> s;
		for(; n --; ){
			cin >> x;
			s -= x;
		}
		cout << (s? "NO" : "YES") << "\n";
	}

	return 0;
}