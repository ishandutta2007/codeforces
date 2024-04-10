#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}
const int C = 1e6;
bool v[C+1] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		v[a] = true;
	}

	int ans = 0;
	for(int i = C; i >= 1; --i) {
		if(v[i]) continue;
		int g = 0;
		for(int j = i+i; j <= C; j += i) {
			if(v[j]) {
				g = gcd(g, j);
				if(g == i) {
					v[i] = true;
					++ans;
					break;
				}
			}
		}
	}
	cout << ans << '\n';
}