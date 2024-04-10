#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, q, a[300000], b[300000], p[300000];
vector<pair<int, int>>vec; bool used[300000];
bool hito[300000];
vector<int>sr[300000];
int main() {
	cin >> n; for (int i = 0; i < n; i++) { cin >> a[i] >> b[i]; sr[a[i]].push_back(i); }
	for (int i = n - 1; i >= 0; i--) {
		if (used[a[i]] == false) { vec.push_back(make_pair(a[i], i)); used[a[i]] = true; }
	}
	for (int i = 0; i < 300000; i++) { p[i] = -1; }
	for (int i = 0; i < vec.size(); i++) { p[vec[i].first] = vec[i].second; }
	cin >> q;
	for (int i = 0; i < q; i++) {
		int sc; cin >> sc; vector<int>H;
		for (int j = 0; j < sc; j++) { int g; cin >> g; if (p[g] != -1)H.push_back(g); }
		for (int j = 0; j < H.size(); j++) { hito[H[j]] = true; }
		int cnt1 = -1, cnt2 = -1;
		for (int j = 0; j < vec.size(); j++) {
			if (cnt2 >= 1)break;
			if (hito[vec[j].first] == false) {
				if (cnt1 == -1)cnt1 = vec[j].first;
				else if (cnt2 == -1)cnt2 = vec[j].first;
			}
		}
		if (cnt1 == -1)cout << "0 0" << endl;
		else {
			if (cnt2 == -1)cout << cnt1 << ' ' << b[sr[cnt1][0]] << endl;
			else {
				int pos1 = lower_bound(sr[cnt1].begin(), sr[cnt1].end(), p[cnt2] + 1) - sr[cnt1].begin();
				cout << cnt1 << ' ' << b[sr[cnt1][pos1]] << endl;
			}
		}
		for (int j = 0; j < H.size(); j++) { hito[H[j]] = false; }
	}
	return 0;
}