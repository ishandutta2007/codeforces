#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector <int> sieve(int n) {
	vector <int> lp(n+1);
	iota(lp.begin(), lp.end(), 0);
	for(int i = 2; i <= n; i++) {
		if(lp[i] == i) {
			for(int j = i * i; j <= n; j += i) {
				if(lp[j] == j) lp[j] = i;
			}
		}
	}
	return lp;
}

void solve() {
	vector <int> lp = sieve(1E7 + 60);
	int n, m;
	cin >> n >> m;
	vector <int> a(n), b(m);
	forn(i, 0, n) cin >> a[i];
	forn(i, 0, m) cin >> b[i];
	map <int, vector<int>> num;
	map <int, vector<int>> den;
	map <int, int> num_occ;
	map <int, int> den_occ;
	forn(i, 0, n) {
		int temp = a[i];
		while(temp > 1) {
			num[lp[temp]].push_back(i);
			num_occ[lp[temp]]++;
			temp /= lp[temp];
		}
	}
	forn(i, 0, m) {
		int temp = b[i];
		while(temp > 1) {
			den[lp[temp]].push_back(i);
			den_occ[lp[temp]]++;
			temp /= lp[temp];
		}
	}
	map<int, int> occ;
	for(auto i : num_occ) occ[i.first] = i.second;
	for(auto i : occ) occ[i.first] = min(occ[i.first], den_occ[i.first]);
	for(auto i : occ) {
		int cnt = 0;
		for(auto j : num[i.first]) {
			if(cnt >= i.second) break;
			a[j] /= i.first;
			cnt++;
		}
		cnt = 0;
		for(auto j : den[i.first]) {
			if(cnt >= i.second) break;
			b[j] /= i.first;
			cnt++;
		}
	}
	cout << n << " " << m << endl;
	forn(i, 0, n) cout << a[i] << " "; cout << endl;
	forn(i, 0, m) cout << b[i] << " "; cout << endl;
}

int32_t main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int T = 1;
	// cin >> T;
	for(int I = 1; I <= T; I++) {
		// cout << "Case #" << I << ": ";
		solve(); 
	}

	return 0;
}