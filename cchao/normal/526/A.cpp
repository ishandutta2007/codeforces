#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)

int main() {
	int l; cin >> l;
	string s; cin >> s;
	rep(i, l) {
		if(s[i] == '.') continue;
		for(int j = 1; j <= l; ++j) {
			bool ans = true;
			for(int k = 1; k <= 4; ++k) {
				if(i + k * j >= l || s[i + k * j] == '.') {
					ans = false;
					break;
				}
			}
			if(ans) {
				puts("yes");
				return 0;
			}
		}
	}
	puts("no");
	return 0;
}