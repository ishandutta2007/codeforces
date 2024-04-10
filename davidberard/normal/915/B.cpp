#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int N, pos, l, r;

	cin >> N >> pos >> l >> r;
	int total = 0;

	if(abs(pos-l) < abs(pos-r)) {
		if(l != 1) {
			total += abs(pos-l) + 1;
			pos = l;
		}
		if(r != N) {
			total += abs(r-pos) + 1;
		}
	} else {
		if(r != N) {
			total += abs(pos-r) + 1;
			pos = r;
		}
		if(l != 1) {
			total += abs(l-pos) + 1;
		}
	}
	cout << total << endl;
	
	
	return 0;
}