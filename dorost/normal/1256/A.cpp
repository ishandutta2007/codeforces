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
		int a, b, n, x;
		cin >> a >> b >> n >> x;
		if (a * n + b >= x && x % n <= b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}