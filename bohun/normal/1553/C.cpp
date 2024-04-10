#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int res = 10;
		for (int w : {0, 1}) {
			int bil = 0;
			int cnt = 5;
			for (int i = 0; i < 10; i++) {
				if (s[i] == '?')
					bil += i % 2 == w % 2;
				if (s[i] == '1')
					bil += (i % 2 == w % 2 ? 1 : -1);
				if (i % 2 == !(w % 2))
					cnt--;
				if (bil > cnt)
					res = min(res, i + 1);
			}
		}
		cout << res << endl;
	}
	return 0;
}