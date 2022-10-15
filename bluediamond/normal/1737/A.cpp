#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int f[26];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, l;
		string s;
		cin >> n >> l >> s;
		f[0] = f[1] = f[2] = f[3] = f[4] = f[5] = f[6] = f[7] = f[8] = f[9] = f[10] = f[11] = f[12] = f[13] = f[14] = f[15] = f[16] = f[17] = f[18] = f[19] = f[20] = f[21] = f[22] = f[23] = f[24] = f[25] = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] - 'a' < n / l) {
				f[s[i] - 'a']++;
			}
		}
		for (int s = 0; s < l; s++) {
			int cur = 0;
			while (f[cur]) {
				f[cur++]--;
			}
			cout << (char) ('a' + cur);
		}
		cout << "\n";
	}
  return 0;
}