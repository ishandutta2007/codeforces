#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> vert(n+1);
	for(int i = 1; i <= n;++i) {
		cin >> vert[i];
	}

	vector<int> st_ends;
	for(int i = 0; i < m; ++i) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		if(x1 == 1) {
			st_ends.push_back(x2);
		}
	}

	sort(st_ends.rbegin(), st_ends.rend());
	sort(vert.begin(), vert.end());
	vert.push_back(1e9);

	int best = 1e9;
	for(int i = 1; i < (int)vert.size(); ++i){
		while (st_ends.size() and st_ends.back() < vert[i])
			st_ends.pop_back();
		//cout << "-- at " << vert[i] << " -- " << endl;
		//for(int x : st_ends) cout << x << " "; cout << endl;
		best = min(best, i-1 + (int)st_ends.size());
	}
	cout << best << "\n";
}