#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

vector<int> pref;
vector<int> kek;
vector<int> tet;

int pw(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * pw(x, y-1)) % mod;
	int q = pw(x, y/2);
	return ((ll) q * q) % mod;
}

int n;

int get_time(int l, int r) {
	l = n-1-l, r = n-1-r;
	swap(l, r);
	//cout << "========= " << l << " " << r << endl;
	int res = (kek[r+1] - kek[l] + mod) % mod;

	res = ((ll) res * pw(pref[l], mod-2)) % mod;
	//cout << "========= " << l << " " << r << " " << res << endl;
	return res;

}


int main(){
#ifdef LOCAL
	freopen("E_input.txt", "r", stdin);
	//freopen("E_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<int> checkpoints;

	int q;
	cin >> n >> q;

	vector<int> v(n);
	for (int i=0; i < n; ++i) cin >> v[i];

	reverse(v.begin(), v.end());

	checkpoints.insert(0);
	checkpoints.insert(n);
	pref.push_back(1);
	kek.push_back(0);

	for (int i=0; i < n; ++i) {
		int T = ((ll) v[i] * pw(100, mod-2)) % mod;
		pref.push_back(((ll) pref.back() * pw(T, mod-2)) % mod);

		kek.push_back((kek.back() + pref.back()) % mod);
	}

	//cout << tet[0] << " " << tet[1] << " " << tet[2] << endl;

	int ans = get_time(0, n-1);



	for (int i=0; i < q; ++i) {
		int x;
		cin >> x;
		x--;
		if (checkpoints.count(x)) {
			//cout << "===========\n";
			auto it = checkpoints.find(x);
			it--;
			int L = (*it);
			it++;
			it++;
			int R = (*it);
			ans = (ans - get_time(L, x-1) + mod) % mod;
			ans = (ans - get_time(x, R-1) + mod) % mod;
			ans = (ans + get_time(L, R-1)) % mod;
			checkpoints.erase(checkpoints.find(x));
		}
		else{
			checkpoints.insert(x);
			auto it = checkpoints.find(x);
			it--;
			int L = (*it);
			it++;
			it++;
			int R = (*it);
			ans = (ans + get_time(L, x-1)) % mod;
			ans = (ans + get_time(x, R-1)) % mod;
			ans = (ans - get_time(L, R-1) + mod) % mod;
			//checkpoints.erase(checkpoints.find(x));
		}
		cout << ans << "\n";
	}

	

}