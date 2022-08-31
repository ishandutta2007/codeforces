#include<bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int> > > data;
vector<bool> used;
void solve(){
	int n, m;
	cin >> n >> m;
	data.assign(3*n, {});
	used.assign(3*n, false);
	vector<int> matching;
	for (int i=0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v) swap(u, v);
		data[v].push_back({u, i});
	}
	for (int i=0; i < 3*n; i++){
		for (int j=0; j < data[i].size(); j++){
			int to = data[i][j].first;
			if (used[to]) continue;
			used[i] = true, used[to] = true;
			matching.push_back(data[i][j].second);
			break;
		}
	}
	if (matching.size() >= n){
		cout << "Matching\n";
		for (int i=0; i < n; i++) cout << matching[i]+1 << " ";
		cout << "\n";
	}
	else{
		int cur = n;
		cout << "IndSet\n";
		for (int i=0;i<3*n;i++){
			if (used[i]) continue;
			cur--;
			cout << i+1 << " ";
			if (cur==0) break;
		}
		cout << "\n";
	}
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for (int i=0; i < t; i++) solve();
}