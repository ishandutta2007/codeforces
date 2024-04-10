#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9;

int get(int i, set<int> &x){
	auto it = x.upper_bound(i);
	if (it != x.end()) return (*it);
	it = x.begin();
	return (*it);
}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];
	set<int> used;
	set<int> bad;
	for (int i=0; i < n; ++i) bad.insert(i);
	vector<pair<int, int> > sorted;
	for (int i=0; i < n; ++i) sorted.push_back({v[i], i});
	sort(sorted.begin(), sorted.end(), greater<pair<int, int> > ());
	vector<int> ans(n);

	int start = 0;
	int u = 0;
	while (start < n){
		int finish = start;
		while (finish < n && sorted[start].first == sorted[finish].first) finish++;
		while (u < n && sorted[u].first * 2 >= sorted[start].first){
			bad.erase(bad.find(sorted[u].second));
			u++;
		}
		for (int i=start; i < finish;++i){
			int index = sorted[i].second;
			int res = INF;
			if (used.size()){
				int closest = get(index, used);
				if (ans[closest] != -1) res = min(res, ans[closest] + (closest-index+n)%n);
			}
			if (bad.size()){
				int closest = get(index, bad);
				res = min(res, (closest-index+n)%n);
			}
			if (res == INF) ans[index] = -1;
			else ans[index] = res;
		}
		for (int i=start; i < finish; ++i){
			used.insert(sorted[i].second);
		}
		start = finish;
	}
	for (int i=0;i<n;++i) cout << ans[i] << " ";



}