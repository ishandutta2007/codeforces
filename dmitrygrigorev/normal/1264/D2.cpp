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
 
const int N = 1000007;
int fact[N], rev[N];
int pwt[N];

int pw(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * pw(x, y-1)) % mod;
	int T = pw(x, y/2);
	return ((ll) T * T) % mod;
}

int C(int n, int k) {
	if (k<0 || k > n) return 0;
	int A = fact[n], B = ((ll) rev[k] * rev[n-k]) % mod;
	return ((ll) A * B) % mod;
}

map<pair<int, int>, int> mm;

int pref(int n, int k) {
	if (k < 0) return 0;
	if (mm.count({n, k})) return mm[{n, k}];
	int T = (pref(n, k-1) + C(n, k)) % mod;
	mm[{n, k}] = T;
	return T;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
 	fact[0] = 1;
	for (int i=1; i < N; ++i){
		fact[i] = ((ll) i * fact[i-1]) % mod;
	}

	for (int i = 0; i < N; ++i) {
		rev[i] = pw(fact[i], mod-2);
	}
 
	string s;
	cin >> s;
 
	int ans = 0;
 
	int n = s.size();

	int cnt = 0, spec = 0, kek = 0, tet = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') kek++;
		if (s[i] == ')') tet++;
	}
 
	for (int i=0; i < n; ++i) {
		if (s[i] == '?') spec++;
		if (s[i] == '(') cnt++;

		if (s[i] == '?') kek--;
		if (s[i] == ')') tet--;

		if (s[i] == ')') continue;
		if (s[i] == '?'){
			cnt++;
			spec--;
		}
 
		//cnt + take1 <= tet + take2

		int x = pref(kek + spec, tet + kek - cnt);

		//cout << kek+spec << " " << tet+kek-cnt << endl;

		if (s[i] == '?'){
			cnt--;
			spec++;
		}
		ans = (ans + x) % mod;
	}
 
	reverse(s.begin(), s.end());

	for (int i=0;i<n;++i){
		if (s[i] == '(') s[i] = ')';
		else if (s[i] == ')') s[i] = '(';
	}
 
	cnt = 0, spec = 0, kek = 0, tet = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') kek++;
		if (s[i] == ')') tet++;
	}
 
	for (int i=0; i < n; ++i) {
		if (s[i] == '?') spec++;
		if (s[i] == '(') cnt++;

		if (s[i] == '?') kek--;
		if (s[i] == ')') tet--;

		if (s[i] == ')') continue;
		if (s[i] == '?'){
			cnt++;
			spec--;
		}
 
		//cnt + take1 <= tet + take2

		int x = pref(kek + spec, tet + kek - cnt);

		//cout << kek+spec << " " << tet+kek-cnt << " " << x << endl;

		if (s[i] == '?'){
			cnt--;
			spec++;
		}
		ans = (ans + x) % mod;
	}
 
	ans = ((ll) ans * ((mod+1)/2)) % mod;
 
	cout << ans;
 
}