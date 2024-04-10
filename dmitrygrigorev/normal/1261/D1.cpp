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

int pw(int x, int y){
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * pw(x, y-1)) % mod;
	int t = pw(x, y/2);
	return ((ll) t * t) % mod;
}

const int N = 200007;

int fact[N], rev[N];

int C(int n, int k){
	int A = fact[n], b = ((ll) rev[k] * rev[n-k]) % mod;
	return ((ll) A * b) % mod;
}

void calc(){
	fact[0] = 1;
	for (int i=1; i < N; ++i){
		fact[i] = ((ll) fact[i-1] * i) % mod;
	}
	for (int i=0;i<N;++i){
		rev[i] = pw(fact[i], mod-2);
	}
}

int main(){
#ifdef LOCAL
	freopen("L_input.txt", "r", stdin);
	//freopen("L_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	calc();

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i=0;i<n;++i) cin >> v[i];

	int p = 0;

	for (int i=0; i < n; ++i) {
		if (v[i] != v[(i+1)%n]) p++;
	}

	int ans = pw(k, n);

	for (int eq=0; 2*eq <= p; eq++){
		int var = ((ll) C(p, eq) * C(p-eq, eq)) % mod;
		var = ((ll) var * pw(k, n-p)) % mod;
		var = ((ll) var * pw(k-2, p-2*eq)) % mod;
		ans = (ans-var+mod)%mod;
	}

	ans = ((ll) ans * ((mod+1)/2)) % mod;
	cout << ans;



}