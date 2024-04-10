#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

int n, k;
string s;

void win(int b) {
	if(b == 0) cout << "tokitsukaze\n";
	else if(b == 1) cout << "quailty\n";
	else cout << "once again\n";
	exit(0);
}

int get_idx(vector<int>& v, int a, bool before) {
	int lo = -1, hi = v.size();
	while(hi - lo > 1) {
		int md = (lo+hi)/2;
		if(v[md] <= a)
			lo = md;
		else hi = md;
	}
	if(before) {
		if(lo >= 0 && v[lo] == a)
			return lo-1;
		return lo;
	} else {
		return hi;
	}
}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> s;
	vector<int> l[2];
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0')
			l[0].push_back(i);
		else
			l[1].push_back(i);
	}
	// first player wins
	for(int s = 0; s < 2; ++s) {
		if(l[s].empty() || l[s].back() - l[s][0] < k)
			win(0);
	}
	// search for draw
	for(int i = 0; i+k <= n; ++i) {
		for(int s = 0; s < 2; ++s) {
			int fm = min(l[s][0], i);
			int lm = max(l[s].back(), i+k-1);

			int a = get_idx(l[!s], i, true);
			int b = get_idx(l[!s], i+k-1, false);
			int fd = -1, ld = -1;
			if(a >= 0 || b < (int)l[!s].size()) {
				fd = (a < 0) ? l[!s][b] : l[!s][0];
				ld = (b >= (int)l[!s].size()) ? l[!s][a] : l[!s].back();
				if(ld - fd >= k && lm - fm >= k)
					win(2);
			}
		}
	}
	win(1);
}