#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

int n, k;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> k))
		return false;
	a.resize(n);
	fore(i, 0, n)
		cin >> a[i];
	return true;
}

inline void solve() {
	pair<int, int> ans = {int(1e9) + 7, -1};
	fore(i, 0, n - k) {
		int dist = a[i + k] - a[i];
		ans = min(ans, make_pair(dist, a[i] + dist / 2));
	}
	
	cout << ans.second << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int tc; cin >> tc;
	
	while(tc--) {
	    read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}