#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define __builtin_popcount __builtin_popcountll

using namespace std;

const int mod = 998244353;

void print(vector<ll> &ans) {
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	exit(0);
}


void solve_naive(vector<ll> &gauss, int m, int add) {
	vector<ll> ans(m+1, 0);

	int n = gauss.size();
	for (int i = 0; i < (1<<n); ++i) {

		ll x = 0;
		for (int j = 0; j < n; ++j) {
			if ((1<<j)&i) x ^= gauss[j];
		}
		int T = __builtin_popcount(x);

		ans[T] += add;
		ans[T] %= mod;

	}

	print(ans);

}

// u can set modular arithmetic here
void hadamard(vector<int>& v){
	int K = v.size();
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                int F = v[start+w] + v[start+step/2+w];
                int S = v[start+w] - v[start+step/2+w];
                v[start + w] = F%mod;
                v[start+step/2+w] = (S+mod)%mod;
            }
        }
    }
}

int bp(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * bp(x, y-1)) % mod;
	int t = bp(x, y/2);
	return ((ll) t*t) % mod;
}

void dvd(int &a, int b) { ///////// a/b - write own code depending of if you need using modulo
	a = ((ll) a * bp(b, mod-2)) % mod;
}

vector<int> mult(vector<int> a, vector<int> b) {

	int deg = 1;
	while (deg < a.size() || deg < b.size()) deg *= 2;
	while (a.size() < deg) a.push_back(0);
	while (b.size() < deg) b.push_back(0);

	hadamard(a);
    hadamard(b);
    for (int i=0; i < a.size(); i++) {
    	ll T = (ll) a[i] * b[i];
    	a[i] = T%mod;
    }
    hadamard(a);

    for (int i=0; i < a.size(); i++) dvd(a[i], a.size());
    return a;

}

const int T = 16;

const int N = (1<<T);

void solve_mitm(vector<ll> &gauss, int m, int add) {

	int a = 0;
	int b = gauss.size();
	while (a < gauss.size() && gauss[a] >= (ll) N) {
		a++;
		b--;
	}
	vector<ll> ans(m+1, 0);

	for (int cnt = 0; cnt <= max(0, m-T); ++cnt) {

		vector<int> e(N, 0);
		vector<int> f(N, 0);

		for (int mask = 0; mask < (1<<a); ++mask) {

			ll x = 0;
			for (int i = 0; i < a; ++i) {
				if ((1LL<<i)&mask) x ^= gauss[i];
			}
			ll A = x&(N-1);
			ll B = x^A;

			if (__builtin_popcount(B) != cnt) continue;
			e[A]++;
		}


		for (int mask = 0; mask < (1<<b); ++mask) {

			ll x = 0;
			for (int i = 0; i < b; ++i) {
				if ((1LL<<i)&mask) x ^= gauss[i+a];
			}
			
			f[x]++;
		}


		vector<int> c = mult(e, f);
		for (int i = 0; i < N; ++i) {
			if (c[i] == 0) continue;
			int cur = cnt+__builtin_popcount(i);
			int Q = ((ll) add * c[i]) % mod;
			ans[cur] += Q;
			ans[cur] %= mod;
		}

	}

	print(ans);

}

void solve_dp(vector<ll> &gauss, int m, int add) {

	vector<pair<int, int> > arr;


}

int main(){
#ifdef LOCAL
	freopen("N_input.txt", "r", stdin);
	//freopen("N_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<ll> gauss(m, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = m-1; j >= 0; j--) {
			if (!(v[i] & (1LL<<j))) continue;
			if (gauss[j] == 0) {
				gauss[j] = v[i];
				break;
			}
			v[i] ^= gauss[j];
		}
	}

	int res = 1;

	int cnt = 0;
	for (int i = 0; i < m; ++i) if (gauss[i]) cnt++;
	for (int i = 0; i < n - cnt; ++i) {
		res *= 2;
		res %= mod;
	}

	vector<ll> ng;
	for (int i = 0; i < gauss.size(); ++i) if (gauss[gauss.size() - i - 1]) ng.push_back(gauss[gauss.size() - i - 1]);
	gauss = ng;

	if (cnt <= 1) {
		solve_naive(gauss, m, res);
	}
	else if (cnt <= 36) solve_mitm(gauss, m, res);
	else solve_dp(gauss, m, res);

}