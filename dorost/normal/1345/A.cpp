#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t;
	cin >> t;
	while (t--){
		int n, m;
		cin >> n >> m;
		int d = n * (m - 1) + m * (n - 1), x = (n + m) * 2;
		if (x >= n * m * 3 - d)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}