#include <bits/stdc++.h>

using namespace std;

int n, k;

string s, t;

int main() {
	scanf("%d %d", &n, &k);
	cin >> s >> t;
	long long ans = 0, cur = 1;
	for (int i = 0; i < n; i++) {
		if (cur == 1) {
			if (s[i] == t[i]) {
			} else {
				cur = 2;
			}
		} else {
			cur = min(10000000000, (cur - 2) * 2 + 2);
			if (s[i] == 'a') {
				cur ++;
			}
			if (t[i] == 'b') {
				cur ++;
			}
		}
		ans += min(1LL * k, cur);
	}	
	cout << ans << endl;
}