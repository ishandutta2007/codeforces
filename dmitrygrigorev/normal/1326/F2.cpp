#include <bits/stdc++.h>
#define ll long long
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

char matrix[18][18];
ll path_cnt[1<<18][18];
ll val[1<<18][19];

map<vector<int>, ll> mm;
int n;

void calc(vector<int> v) {
	ll res = 0;
	vector<int> t = {1, 1, 1};
	for (int i = 0; i < (1<<n); ++i) {
		int delta = n - __builtin_popcount(i);
		ll Q = 1;
		if (delta % 2) Q = -1;

		ll P = 1;
		for (int j = 0; j < v.size(); ++j) {
			P *= val[i][v[j]];
		}
		res += Q*P;

	}

	mm[v] = res;
}

void recursion(int n, int k, vector<int> v) {
	if (n > 0 && k==0) return;
	if (n == 0) {
		calc(v);
		return;
	}
	recursion(n, k-1, v);
	if (k > n) return;
	v.push_back(k);
	recursion(n-k, k, v);

}

ll touch[1<<18][19];

void precalc(int n) {
	for (int i = 0; i < n; ++i) {
		path_cnt[(1<<i)][i] = 1;
	}

	for (int mask = 1; mask < (1<<n); ++mask) {
		for (int last = 0; last < n; ++last) {
			if (!((1<<last)&mask)) continue;
			for (int nxt = 0; nxt < n; ++nxt) {
				if (matrix[last][nxt] == '0') continue;
				if ((1<<nxt) & mask) continue;
				path_cnt[mask ^ (1<<nxt)][nxt] += path_cnt[mask][last];
			}
		}
	}

	for (int i = 0; i < (1<<n); ++i) for (int j = 0; j < n; ++j) {
		val[i][__builtin_popcount(i)] += path_cnt[i][j];
	}

	for (int cnt = 0; cnt <= n; ++cnt) {
		for (int j = 0; j < (1<<n); ++j) for (int k = 0; k <= n; ++k) touch[j][k] = 0;
		for (int j = 0; j < (1<<n); ++j) touch[j][n] = val[j][cnt];
		for (int j = 0; j < (1<<n); ++j) for (int bit = n-1; bit >= 0; bit--) {
			touch[j][bit] = touch[j][bit+1];
			if ((j&(1<<bit))) touch[j][bit] += touch[j^(1<<bit)][bit+1];
		}
		//if (cnt == 1) cout << touch[1][n-1] << endl;
		for (int j = 0; j < (1<<n); ++j) {
			val[j][cnt] = touch[j][0];
		}
	}




}

ll g[1<<18][19][2];

main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> matrix[i][j];

	precalc(n);

	vector<int> st = {};
	recursion(n, n, st);

	vector<int> t = {1, 1, 1};
	n--;
	
	vector<int> res(1<<n);

	for (int i = 0; i < (1<<n); ++i) {
		vector<int> l;
		int now = 1;
		for (int j = 0; j < n; ++j) {
			if ((1<<j)&i) {
				now++;
			}
			else {
				l.push_back(now);
				now = 1;
			}
		}

		l.push_back(now);
		sort(l.begin(), l.end(), greater<int>());
		res[((1<<n)-1)^i] = mm[l];
	}

	for (int i = 0; i < (1<<n); ++i) {
		g[i][n][__builtin_popcount(i) % 2] = res[i];
	}

	for (int i = 0; i < (1<<n); ++i) {
		for (int e = 0; e < 2; ++e) {
			for (int bit = n-1; bit >= 0; bit--) {
				g[i][bit][e] = g[i][bit+1][e];
				if (i&(1<<bit)) g[i][bit][e] += g[i^(1<<bit)][bit+1][e];
			}
		}
	}

	for (int i = (1<<n)-1; i >= 0; i--) {
		long long kek = g[i][0][__builtin_popcount(i) % 2] - g[i][0][1-(__builtin_popcount(i) % 2)];
		if (kek < 0) for (int e = 0; e < 2; ++e) kek += (1LL<<62);
		cout << kek << " ";
	}





}