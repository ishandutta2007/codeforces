#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, i, x;

	cin >> t;

	for(; t --; ){
		cin >> n;
		for(i = 1; i <= n; i ++){
			cin >> x; x = abs(x);
			if(i & 1) cout << -x << " ";
			else cout << x << " ";
		}
		cout << "\n";
	}	

	return 0;
}