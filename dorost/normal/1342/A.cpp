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
		int x, y, a, b, ans = 0;
		cin >> x >> y >> a >> b;
		if (x < 0 && y < 0){
			int f = max(x, y), h = min(x, y);
			ans += (-1 * f) * b;
			ans += ((h - f) * -1 * a);
		}else if (x > 0 && y > 0){
			int f = max(x, y), h = min(x, y);
			ans += (h * b);
			ans += (f - h) * a;
		}else{
			ans += (abs(x) + abs(y)) * a;
		}
		cout << min(abs(x) * a + abs(y) * a, ans) << endl;
	}
}