#include <bits/stdc++.h>
using namespace std;

int a[2020] = {}, b[2020] = {};
int main() {
	int p, q, l, r; cin >> p >> q >>l >>r;

	while(p--) {
		int aa, bb; cin >> aa >> bb;
		for(int i = aa; i <= bb; ++i) a[i]++;
	}
	while(q--) {
		int aa, bb; cin >> aa >> bb;
		for(int i = aa; i <= bb; ++i) if(i + l <= 1000) b[i + l]++;
	}

	int ans = 0;
	for(int k = 0; k < r - l + 1; ++k) {
//		cout << "rnd " << k << endl;
//		for(int i = 0; i <= 20; ++i) printf("%d %d\n", a[i], b[i]);
		for(int i = 0; i <= 1000; ++i) if(a[i] && b[i]) { ans++; break; }
		for(int i = 1000; i > 0; --i) b[i] = b[i-1]; b[0] = 0;
	}
	cout << ans << endl;

	return 0;
}