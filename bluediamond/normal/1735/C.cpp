#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t[26], s[26];

void clr() {
	for (int i = 0; i < 26; i++) {
		t[i] = i;
		s[i] = 1;
	}
}

int root(int a) {
	if (t[a] == a) {
		return a;
	}
	return t[a] = root(t[a]);
}

void join(int i, int j) {
	i = root(i);
	j = root(j);
	if (i == j) {
		return;
	}
	t[i] = j;
	s[j] += s[i];
}

signed main() {
#ifndef ONPC
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif

	
	

	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; tc++) {
		int n;
		string str;
		cin >> n >> str;
		assert((int) str.size() == n);
		vector<int> who(26, -1);
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			char ch = str[i];
			assert('a' <= ch && ch <= 'z');
			a[i] = ch - 'a';
			assert(0 <= a[i] && a[i] < 26);
		}
		for (int i = 0; i < n; i++) {
			if (who[a[i]] != -1) {
				continue;
			}
			set<int> av;
			for (int x = 0; x < 26; x++) {
				av.insert(x);
			}
			for (int x = 0; x < 26; x++) {
				if (who[x] != -1) {
					av.erase(who[x]);
				}
			}
			clr();
			for (auto &val : av) {
				who[a[i]] = val;
				clr();
				for (int x = 0; x < 26; x++) {
					if (who[x] != -1) {
						s[x]--;
					}
				}
				int cnt = 0;
				for (int x = 0; x < 26; x++) {
					if (who[x] != -1) {
						join(x, who[x]);
						cnt++;
					}
						
				}
				bool ok = 1;
				
				if (cnt == 26) {
					int cnt_pap = 0;
					for (int x = 0; x < 26; x++) {
						cnt_pap += (t[x] == x);
					}
					ok &= (cnt_pap == 1);
				} else {
					for (int x = 0; x < 26; x++) {
						if (t[x] == x)
						//cout << "x = " << x << " and s[x] = " << s[x] << "\n";
						if (t[x] == x && s[x] == 0) {
							ok = 0;
						}
					}
				}
				
				if (ok) {
					break;
				}
				
				who[a[i]] = 0;
			}
			assert(who[a[i]] != -1);
		}
		for (int i = 0; i < n; i++) {
			int x = who[a[i]];
			cout << (char) ('a' + x);
		}
		cout << "\n";
	}
		
	return 0;
}