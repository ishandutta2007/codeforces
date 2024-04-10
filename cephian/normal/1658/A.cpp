#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int num = 0;
	for(int i = 1; i < n; ++i) {
		if(s[i] == '0' && s[i-1] == '0')
			num += 2;
		if(i < n-1 && s[i] == '1' && s[i-1] == '0' && s[i+1] == '0')
			++num;
	}
	cout << num << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}