#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Hasher{ 
	vector<int> a, h, rev;
	
    int p, mod;
    
    Hasher(const vector<int>& a, int p, int mod): a(a), p(p), mod(mod) {
        build();
    }

	int bp(int a, int k){
		if (k == 0) return 1;
		if (k % 2 == 1){
			return a * (ll)bp(a, k - 1) % mod;
		} else {
			int q = bp(a, k >> 1);
			return q * (ll)q % mod;
		}
	}

	void build(){
		rev.resize(a.size() + 1); h.resize(a.size() + 1);
		rev[0] = 1;
		h[0] = 0;
		int deg = 1;
		for (int i = 1; i <= a.size(); i++){
			h[i] = (h[i - 1] + a[i - 1] * (ll)deg) % mod;
			deg = deg * (ll)p % mod;
			rev[i] = bp(deg, mod - 2);
		}
	}

	int get(int l, int r){
		int ans = h[r + 1] - h[l];
		if (ans < 0) ans += mod;
		ans = ans * (ll)rev[l] % mod;
		return ans;
	}
}; 

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr;
	vector<string> kek;

	for (int i = 0; i < n; ++i) {
		string x;
		cin >> x;
		kek.push_back(x);
		for (int j = 0; j < x.size(); ++j) {
			arr.push_back(x[j] - 'a' + 1);
		}
		arr.push_back(27);
	}

	Hasher first(arr, 179, 1000000007), second(arr, 239,998244353);

	set<pair<int, int> > a;
	int tot = 0;
	for (int i = 0; i < n; ++i) {
		a.insert({first.get(tot, tot+kek[i].size() - 1), second.get(tot, tot+kek[i].size() - 1)});
		tot += kek[i].size() + 1;
	}

	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		vector<int> tarr;
		for (int j = 0; j < s.size(); ++j) tarr.push_back(s[j] - 'a' + 1);
		Hasher kek(tarr, 179, 1000000007), tet(tarr, 239,998244353);
		int A =kek.get(0, s.size()-1), B = tet.get(0, s.size()-1);

		bool ans = false;
		for (int j = 0; j < s.size(); ++j) {
			for (int e = 1; e < 4; ++e) {
				if (e == tarr[j]) continue;
				int delta = e - tarr[j];
				int C = A, D = B;
				int dc = kek.bp(kek.p, j);
				int dd = tet.bp(tet.p, j);

				for (int ss = 0; ss < abs(delta); ++ss) {
					if (delta < 0) {
						C = (C-dc + kek.mod) % kek.mod;
						D = (D-dd + tet.mod) % tet.mod;
					}
					else{
						C = (C+dc) % kek.mod;
						D = (D+dd) % tet.mod;
					}
				}

				//cout << C << " " << D << endl;

				if (a.count({C, D})) ans = true;
			}
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";

	}



}