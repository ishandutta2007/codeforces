#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout << setprecision(14) << fixed;
	
	int A, B;
	cin >> A >> B;
	if(A < B) {
		cout << -1 << '\n';
		return 0;
	}
	int r(ld(A) / ld(B));
	if(r & 1) ++r;
	ld ans = ld(A + B) / ld(r);
	cout << ans << '\n';
}