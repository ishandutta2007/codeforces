#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<int>> divis;
vector<vector<int>> location;
vector<int> seen;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	{
		const int limit = (int) 1e6 + 7;
		divis.resize(limit);
		for (int i = 1; i < limit; i++) {
			for (int j = 2 * i; j < limit; j += i) {
				divis[j].push_back(i);
			}
		}
		seen.resize((int) divis.size());
		location.resize((int) divis.size());
	}
	
	int tests;
	cin >> tests;
	
	vector<int> stk, a, l, r, L, R, lsm, nsm;
	
	for (int tc = 1; tc <= tests; tc++) {
		int n;
		cin >> n;
		a.resize(n);
		l.resize(n);
		r.resize(n);
		L.resize(n);
		R.resize(n);
		lsm.resize(n);
		nsm.resize(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		{
			stk.clear();
			for (int i = 0; i < n; i++) {
				while (!stk.empty() && a[stk.back()] >= a[i]) {
					stk.pop_back();
				}
				lsm[i] = stk.empty() ? -1 : stk.back();
				stk.push_back(i);
			}
		}
		{
			stk.clear();
			for (int i = n - 1; i >= 0; i--) {
				while (!stk.empty() && a[stk.back()] >= a[i]) {
					stk.pop_back();
				}
				nsm[i] = stk.empty() ? n : stk.back();
				stk.push_back(i);
			}
		}
		{
			stk.clear();
			for (int i = 0; i < n; i++) {
				while (!stk.empty() && a[stk.back()] <= a[i]) {
					stk.pop_back();
				}
				L[i] = stk.empty() ? 0 : (stk.back() + 1);
				stk.push_back(i);
			}
		}
		{
			stk.clear();
			for (int i = 0; i < n; i++) {
				while (!stk.empty() && a[stk.back()] >= a[i]) {
					stk.pop_back();
				}
				l[i] = stk.empty() ? 0 : (stk.back() + 1);
				stk.push_back(i);
			}
		}
		{
			stk.clear();
			for (int i = n - 1; i >= 0; i--) {
				while (!stk.empty() && a[stk.back()] < a[i]) {
					stk.pop_back();
				}
				R[i] = stk.empty() ? (n - 1) : (stk.back() - 1);
				stk.push_back(i);
			}
		}
		{
			stk.clear();
			for (int i = n - 1; i >= 0; i--) {
				while (!stk.empty() && a[stk.back()] > a[i]) {
					stk.pop_back();
				}
				r[i] = stk.empty() ? (n - 1) : (stk.back() - 1);
				stk.push_back(i);
			}
		}
		for (int i = 0; i < n; i++) {
			location[a[i]].push_back(i);
		}
		ll sol = 0;
		for (int id_mx = 0; id_mx < n; id_mx++) {
			int id_mn = id_mx;
			int ways_l = max(0, min(id_mx, id_mn) - max(L[id_mx], l[id_mn]) + 1);
			int ways_r = max(0, min(R[id_mx], r[id_mn]) - max(id_mx, id_mn) + 1);	
			sol += ways_l * (ll) ways_r;
		}
		for (int id_mx = 0; id_mx < n; id_mx++) {
			seen[a[id_mx]]++;
			for (auto &d : divis[a[id_mx]]) {
				int ant = seen[d] - 1, nxt = seen[d];
				if (!(0 <= ant && ant < (int) location[d].size())) ant = -1; else ant = location[d][ant];
				if (!(0 <= nxt && nxt < (int) location[d].size())) nxt = -1; else nxt = location[d][nxt];
				if (nxt == -1 && ant == -1) {
					continue;
				}
				
				if (ant == -1) {
					if (lsm[nxt] > id_mx) {
						continue;
					}
					int ways_l = max(0, id_mx - max(lsm[nxt] + 1, L[id_mx]) + 1);
					int ways_r = max(0, min(nsm[nxt] - 1, R[id_mx]) - nxt + 1);
					sol += ways_l * (ll) ways_r;
					continue;
				}
				if (nxt == -1) {
					if (nsm[ant] < id_mx) {
						continue;
					}
					int ways_l = max(0, ant - max(lsm[ant] + 1, L[id_mx]) + 1);
					int ways_r = max(0, min(nsm[ant] - 1, R[id_mx]) - id_mx + 1);
					sol += ways_l * (ll) ways_r;
					continue;
				}
				
				if (lsm[nxt] > id_mx && nsm[ant] < id_mx) {
					continue;
				}
				
				if (lsm[nxt] > id_mx) {
					int ways_l = max(0, ant - max(lsm[ant] + 1, L[id_mx]) + 1);
					int ways_r = max(0, min(nsm[ant] - 1, R[id_mx]) - id_mx + 1);
					
					sol += ways_l * (ll) ways_r;
					
					continue;
				}
				
				if (nsm[ant] < id_mx) {
					int ways_l = max(0, id_mx - max(L[id_mx], lsm[nxt] + 1) + 1);
					int ways_r = max(0, min(nsm[nxt] - 1, R[id_mx]) - nxt + 1);
					sol += ways_l * (ll) ways_r;
					continue;
				}
				int start = max(L[id_mx], lsm[ant] + 1);
				int stop = min(R[id_mx], nsm[ant] - 1);
				sol += max(0, id_mx - start + 1) * (ll) max(0, stop - id_mx + 1);
				sol -= max(0, id_mx - max(ant + 1, start) + 1) * (ll) max(0, min(nxt - 1, stop) - id_mx + 1);	
			}
		}
		for (int i = 0; i < n; i++) {
			location[a[i]].clear();
			seen[a[i]] = 0;
		}
		cout << sol << "\n";
	}
}