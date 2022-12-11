#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

vpi D1[1000010];
vpi D2[1000010];
ll R1[1000010];
ll R2[1000010];

int main() {
	int n,m,k;
	cin >> n>> m >>k;
	for (int i = 0; i < m; ++i) {
		int d,f,t,c;
		cin >> d >> f >> t >> c;
		if (f == 0) {
			D2[d].push_back(pi(c, t));
		}
		else {
			D1[d].push_back(pi(c, f));
		}
	}
	vi V(n + 1, -1);
	int q = n;
	ll val = 0;
	for (int i = 0; i < 1000010; ++i) {
		for (int j = 0; j < D1[i].size(); ++j) {
			ll c = D1[i][j].first;
			int k = D1[i][j].second;
			if (V[k] == -1) {
				V[k] = c;
				--q;
				val += c;
			}
			else if(V[k] > c) {
				val += c - V[k];
				V[k] = c;
			}
		}
		if (q == 0) R1[i] = val;
		else R1[i] = -1;
	}
	
	V = vi(n + 1, -1);
	q = n;
	val = 0;
	for (int i = 1000009; i >= 0; --i) {
		for (int j = 0; j < D2[i].size(); ++j) {
			ll c = D2[i][j].first;
			int k = D2[i][j].second;
			if (V[k] == -1) {
				V[k] = c;
				--q;
				val += c;
			}
			else if(V[k] > c) {
				val += c - V[k];
				V[k] = c;
			}
		}
		if (q == 0) R2[i] = val;
		else R2[i] = -1;
	}
	
	ll res = -1;
	for (int i = 0; i + k + 1 < 1000010; ++i) {
		int j = i + k + 1;
		if (R1[i] != -1 and R2[j] != -1) {
			ll tt = R1[i] + R2[j];
			if (res == -1 or tt < res) res = tt;
		}
	}
	cout << res << endl;
}