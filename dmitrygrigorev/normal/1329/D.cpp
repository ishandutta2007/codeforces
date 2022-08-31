#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> //  . 
#include <ext/pb_ds/tree_policy.hpp> //   tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> rmq;

void change(int i, int l, int r, int index, int val) {
	if (r-l == 1) {
		rmq[i] += val;
		return;
	}
	int mid = (l+r)/2;
	if (index < mid) change(2*i+1, l, mid, index, val);
	else change(2*i+2, mid, r, index, val);
	rmq[i] = rmq[2*i+1] + rmq[2*i+2];
}

int get(int i, int l, int r, int l1, int r1) {
	if (l1 >= r1) return 0;
	if (l == l1 && r==r1) return rmq[i];
	int mid = (l+r)/2;
	return get(2*i+1, l, mid, l1, min(r1, mid)) + get(2*i+2, mid, r, max(l1, mid), r1);
} 

vector<pair<int, int> > ans;
int n;

void my_erase(int l, int r, set<int> &kek) {

	int minimum = 1e9, maximum = -1e9;

	int T = 0;

	//cout << l << " " << r << endl;

	while (true) {
		auto it = kek.upper_bound(l-1);
		if (it == kek.end()) break;
		auto x = (*it);
		//cout << l << " " << r << " " << x << endl;
		if (x > r) break;
		kek.erase(it);
		int cnt = get(0, 0, n, 0, x);
		minimum = min(minimum, cnt + (T));
		maximum = max(maximum, cnt + (T++));
		change(0, 0, n, x, -1);
		l = x+1;
	}
	//cout << endl;
	ans.push_back({minimum, maximum});
}

void solve() {

	ans.clear();

	string s;
	cin >> s;

	n = s.size();

	vector<int> cnt(26, 0);
	for (int i = 0; i + 1 < s.size(); ++i) {
		if (s[i] == s[i+1]) {
			cnt[s[i] - 'a']++; 
		}
	}

	int sum = 0;
	for (int i = 0; i < 26; ++i) sum += cnt[i];

	int mx = -1, var = -1;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > mx) {
			mx = cnt[i];
			var = i;
		}
	}

	set<int> kek;

	rmq.assign(4*n, 0);

	for (int i = 0; i < n; ++i) {
		kek.insert(i);
		change(0, 0, n, i, 1);
	}

	vector<vector<int> > wait(26);

	int tsum = sum;

	for (int i = 0; i < n; ++i) {
		if (s[i] != s[i+1]) continue;
		int index = -1, who = -1;


		for (int j = 0; j < 26; ++j) {
			if (j == s[i] - 'a') continue;
			if (!wait[j].size()) continue;
			if (2*mx <= sum+1) {
				cnt[j]--, cnt[s[i]-'a']--;
				tsum -= 2;

				int Q = 0;
				for (int e = 0; e < 26; ++e) Q = max(Q, cnt[e]);
				if (Q * 2 <= tsum+1) {
					if (wait[j].back() > index) {
						index = wait[j].back();
						who = j;
					}
				}

				cnt[j]++, cnt[s[i]-'a']++;
				tsum += 2;
			}

			else {
				if (j != var && s[i] - 'a'!= var) continue;
				if (wait[j].back() > index) {
					index = wait[j].back();
					who = j;
				}
			}

		}
		if (who == -1) wait[s[i] - 'a'].push_back(i);
		else {
			tsum -= 2;
			cnt[s[i]-'a']--;
			cnt[who]--;

			my_erase(wait[who].back() + 1, i, kek);
			wait[who].pop_back();
		}
	}

	for (int i = 0; i < 26; ++i) for (int j = 0; j < wait[i].size(); ++j) {
		my_erase(wait[i][j], wait[i][j], kek);
	}

	int A = get(0, 0, n, 0, n);
	ans.push_back({0, A-1});

	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i].first+1 << " " << ans[i].second+1 << "\n"; 
	}




}

main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}