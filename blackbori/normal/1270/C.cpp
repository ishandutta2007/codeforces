#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t, n, i, x, y, v;
	
	cin >> t;
	
	for(; t --; ){
		cin >> n;
		
		for(i = 0, x = 0, y = 0; i < n; i ++){
			cin >> v;
			x ^= v; y += v;
		}
		
		cout << "2\n" << x << " " << x + y << "\n";
	}
	
	return 0;
}