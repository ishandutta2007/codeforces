#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string S;
ll n, a, b, c;

ll calc(ll g, ll o, vector<ll> X, vector<ll> Y, ll z, ll w, bool f) {
	ll m = 0, s = 0;
	for (; ; f = !f) {
//		cout << g << " " << o << " " << X.size() << " " << Y.size() << " " << z << " " << w << endl;
		if (f) {
			if (o - g <= 0) break;
			o--; s += b;
			m = max(m, s);
		}
		else {
			if (o - g > 0) {
				if (!X.empty()) {
					X.back()--; s += a;
					m = max(m, s);

					if (X.back() == 0) {
						X.pop_back(); z++;
					}
				}
				else if (!Y.empty()) {
					Y.back()--; s += a;
					m = max(m, s);

					if (Y.back() == 0) {
						Y.pop_back(); w++;
					}
				}
				else if (z) {
					z--; s -= c; g--;
					m = max(m, s);
				}
				else if (w) {
					w--; s -= c;
					m = max(m, s);
				}
				else break;
			}
			else {
				if (!X.empty() || !Y.empty()) {
					m = max(m, s + a);
				}
				
				if (z) {
					z--; s -= c; g--;
					m = max(m, s);
				}
				else if (w) {
					w--; s -= c;
					m = max(m, s);
				}
				else break;
			}
		}
//		cout << s << endl;
	}
//	cout << m << endl;
	return m;
}

void tc() {
	vector<ll> X, Y;
	ll i, j;
	cin >> n >> a >> b >> c >> S;
	ll og = 0, oc = 0, z = 0, w = 0;
	for (i = j = 0; i < n; i = j) {
		for (; j < n && S[i] == S[j]; j++);
		if (S[i] == '1') {
			og++; oc += j - i;
		}
		else {
			if (i == 0 || j == n) {
				if (j - i == 1) w++;
				else Y.push_back(j - i - 1);
			}
			else {
				if (j - i == 1) z++;
				else X.push_back(j - i - 1);
			}
		}
	}
	sort(X.rbegin(), X.rend());
	sort(Y.rbegin(), Y.rend());
	cout << max(calc(og, oc, X, Y, z, w, 0), calc(og, oc, X, Y, z, w, 1)) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}