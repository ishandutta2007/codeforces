#include<bits/stdc++.h>
using namespace std;
void solve(){
	int res = 0;
	for (int i = 0; i < 30; i++) {
		int b = (1 << i) - res;
		int a = b + (1 << (i + 1));
		cout << "? " << a << ' ' << b << '\n';
		cout.flush();
		int gcd;
		cin >> gcd;
		if (gcd == (1 << (i + 1))) res += 1 << i;
	}
	cout << "! " << res << '\n';
	cout.flush();
}
int main(){
	int T;
	cin >> T;
	while (T--) solve();
}