#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int x, n, m;
		cin >> x >> n >> m;
		int i = 0;
		while(x / 2 + 10 < x && i < n){
			i++;
			x = x / 2 + 10;
		}
		x -= (m * 10);
		if (x <= 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}