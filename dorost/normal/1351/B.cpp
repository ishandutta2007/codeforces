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
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if ((a == c && a == b + d) || (a == d && a == c + b) || (b == c && b == a + d) || (b == d && b == c + a))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}