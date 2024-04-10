#include <bits/stdc++.h>

using namespace std;

#define var_dump(x) cerr<<#x": "<<x<<"\n"
#define arr_dump(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define ok_dump cerr<<"OK!\n"

#define int long long

int32_t main() {
	#ifndef ONLINE_JUDGE
	freopen("input", "r", stdin);
	#endif

	srand(time(0));

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> m >> n;

	vector<int> Hash(n + 1, 0);

	for(int i = 0; i < m; ++i) {
		int k, rnd = 0;
		for(int _ = 0; _ < 4; ++_)
		    rnd = rnd * RAND_MAX + rand();
		    
		cin >> k;
		while(k--) {
			int x;
			cin >> x;
			Hash[x] += rnd;
		}
	}

	map<int, int> Cnt;
	for(int i = 1; i <= n; ++i)
		Cnt[Hash[i]] += 1;

	const int kMod = 1e9 + 7;

	vector<int> Fact(n + 1);
	Fact[0] = 1;
	for(int i = 1; i <= n; ++i) {
		Fact[i] = Fact[i - 1] * i % kMod;
	}

	int ans = 1;
	for(auto p : Cnt) {
		ans = ans * Fact[p.second] % kMod;
	}
	cout << ans << endl;

	return 0;
}