#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		int a, b, c, d, x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool f = ((x1 == x2 && (a + b)) || (y1 == y2 && (c + d)));
		if ((b - a) + x <= x2 && x + (b - a) >= x1 && y + (d - c) <= y2 && y + (d - c) >= y1 && f == false){
			cout << "YES";
		}else{
			cout << "NO";
		}
		cout << '\n';
	}
}