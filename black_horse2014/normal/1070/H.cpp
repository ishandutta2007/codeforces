#include <bits/stdc++.h>
using namespace std;

const int P1 = 1e9 + 7;
const int P2 = 1e9 + 9;

int main() {
	ios::sync_with_stdio(0);
	int n; cin >> n;
	map<pair<int, int>, int> H;
	map<pair<int, int>, string> T;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		set<pair<int, int> > S;
		for (int j = 0; j < s.length(); j++) {
			int cur1 = 0, cur2 = 0;
			for (int k = j; k < s.length(); k++) {
				cur1 = (cur1 * 337LL + s[k]) % P1;
				cur2 = (cur2 * 337LL + s[k]) % P2;
				auto t = make_pair(cur1, cur2);
				if (S.count(t)) continue;
				S.insert(t);
				T[t] = s;
				H[t]++;
			}
		}
	}
	int q; cin >> q;
	while (q--) {
		string s; cin >> s;
		int cur1 = 0, cur2 = 0;
		for (int j = 0; j < s.length(); j++) cur1 = (cur1 * 337LL + s[j]) % P1, cur2 = (cur2 * 337LL + s[j]) % P2;
		auto t = make_pair(cur1, cur2);
		if (H.count(t)) {
			cout << H[t] << ' ' << T[t] << endl;
		} else {
			cout << "0 -" << endl;
		}
	}
	return 0;
}