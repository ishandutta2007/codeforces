#include <bits/stdc++.h>
using namespace std;

int n;
	vector<string> all, cand;
int vis[220];

void tick(string s, int tt) {
	for (int i = 0; i < all.size(); i++) {
		if (vis[i]) continue;
		if (all[i] == s) {
			vis[i] = tt;
			break;
		}
	}
}
bool check(string s1, string s2) {
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n - 1; i++) {
		tick(s1, 1);
		s1.pop_back();
	}
	for (int i = 1; i <= n - 1; i++) {
		tick(s2, 2);
		reverse(s2.begin(), s2.end());
		s2.pop_back();
		reverse(s2.begin(), s2.end());
	}
	for (int i = 0; i < 2 * (n - 1); i++) if (!vis[i]) return 0;
	for (int i = 0; i < 2 * (n - 1); i++) cout <<"PS"[vis[i] - 1];
	cout << endl;
	return true;
}
int main() {
// 	freopen("in.txt", "r", stdin);	
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= 2 * n - 2; i++) {
		string s; cin >> s;
		if (s.length() == n - 1) cand.push_back(s);
		all.push_back(s);
	}
	if (check(cand[0], cand[1])) return 0;
	check(cand[1], cand[0]);
	return 0;
}