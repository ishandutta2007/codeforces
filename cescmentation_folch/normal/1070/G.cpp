#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

bool comp(pi a, pi b) {
	return a.first > b.first;
}


int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vvpi V(n);
	int mii = n;
	int maa = -1;
	for (int i = 0; i < m; ++i) {
		int s,h;
		cin >> s >> h;
		--s;
		mii = min(mii, s);
		maa = max(maa, s);
		V[s].push_back(pi(h,i));
	}
	for (int i = 0; i < n; ++i) 
		sort(V[i].begin(), V[i].end(), comp);
	VI S(n);
	for (int i = 0; i < n; ++i) cin >> S[i];	
	vpi D1(n);
	for (int i = 0; i < n; ++i) {
		D1[i] = pi(-1,-1);
		if (V[i].size()) D1[i] = max(pi(V[i][0].first + S[i], V[i][0].second),D1[i]);	
		if (i) D1[i] = max(pi(D1[i-1].first + S[i], D1[i-1].second), D1[i]);
	}
	vpi D2(n);
	for (int i = n-1; i >= 0; --i) {
		D2[i] = pi(-1,-1);
		if (V[i].size()) D2[i] = max(pi(V[i][0].first + S[i], V[i][0].second),D2[i]);	
		if (i < n-1) D2[i] = max(pi(D2[i+1].first + S[i], D2[i+1].second), D2[i]);
	}
	vpi res(m,pi(-1,-1));
	int cont = 0;
	bool espot = false;
	for (int i = 0; i <= n; ++i) {
		int i1 = i-1;
		espot = true;
		for (int j = i; j < n; ++j) {
			if (D2[j].first < 0 and j <= maa) espot = false;
		}
		for (int j = i1; j >= 0; --j){
			if (D1[j].first < 0 and j >= mii) espot = false;
		}
		if (!espot) continue;
		int cent = i;
		if (i == n) {
			cent = i1;
			for (int j = i1; j >= 0; --j) {
				int k = D1[j].second;
				if (k == -1) continue;
				if (res[k].first == -1) res[k].first = cont++;
			}
			for (int j = i; j < n; ++j) {
				int k = D2[j].second;
				if (k == -1) continue;
				if (res[k].first == -1) res[k].first = cont++;
			}
		} else {
			for (int j = i; j < n; ++j) {
				int k = D2[j].second;
				if (k == -1) continue;
				if (res[k].first == -1) res[k].first = cont++;
			}
			for (int j = i1; j >= 0; --j) {
				int k = D1[j].second;
				if (k == -1) continue;
				if (res[k].first == -1) res[k].first = cont++;
			}
		}
		for (int j = 0; j < m; ++j) {
			res[j].second = j+1;
			if (res[j].first == -1) res[j].first = cont++;
		}
		sort(res.begin(), res.end());
		cout << cent+ 1 << '\n';
		for (int j = 0; j <m; ++j) {
			if (j) cout << ' ';
			cout << res[j].second;
		}
		cout << '\n';
		break;
	}
	if (!espot) cout << -1 << '\n';
}