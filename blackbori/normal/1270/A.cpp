#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t, n, x, y, v, f;
	
	cin >> t;
	
	for(; t --; ){
		cin >> n >> x >> y;
		
		for(f = 0; x --; ){
			cin >> v;
			if(v == n) f = 1;
		}
		
		for(; y --; ){
			cin >> v;
		}
		
		cout << (f? "YES" : "NO") << "\n";
	}
	
	return 0;
}