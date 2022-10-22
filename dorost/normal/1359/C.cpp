/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main(){
	int t = 1;
	cin >> t;
	while (t--){
		ld h, c, t;
		cin >> h >> c >> t;
		ld a = (h + c) / 2.0;
		if (t <= a){
			cout << 2 << endl;
			continue;
		}
		ld in = t - c;
		ld on = h - t;
		ld ans = 1.0 / (1.0 - (on / in));
		ld an1 = floor(ans);
		ld an2 = ceil(ans);
		ld ans1 = (h + ((an1 - 1) * (c + h))) / (an1 * 2 - 1);
		ld ans2 = (h + ((an2 - 1) * (c + h))) / (an2 * 2 - 1);
		ld ans3 = h;
		ld d1 = abs(ans1 - t);
		ld d2 = abs(ans2 - t);
		ld d3 = abs(ans3 - t);
		if (d3 <= d1 && d3 <= d2){
			cout << 1 << endl;
		}else if (d1 <= d2){
			cout << an1 * 2 - 1 << endl;
		}else{
			cout << an2 * 2 - 1 << endl;
		}
	}
}