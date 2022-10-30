#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int d = 0;
	for(char c : s)
		d += c-'a'+1;
	if(s.size()%2 != 0) {
		d -= 2*(min(s[0], s.back())-'a'+1);
	}
	if(d > 0) cout << "Alice " << d << '\n';
	else cout << "Bob " << -d << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}