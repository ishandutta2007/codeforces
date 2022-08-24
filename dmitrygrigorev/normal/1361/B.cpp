#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1000000007;

const int N = 1000007;
int v[N];
int val[N];
int used[6*N];

int pw(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * pw(x, y-1)) % mod;

	int t = pw(x, y/2);
	return ((ll) t*t) % mod;

}

void solve() {
	int n, p;
	cin >> n >> p;

	for (int i = 0; i < n; ++i) cin >> v[i];


	if (p == 1) {
		if (n%2 == 0) {
			cout << "0\n";
			return;
		}
		else {
			cout << "1\n";
			return;
		}
	}

	sort(v, v+n, greater<int>());

	int cur = 0;
	while (cur < n) {

		int finish = cur+1;
		int now = 0;

		while (finish < n) {

			val[v[finish]]++;
			int t = v[finish];
			used[now++] = v[finish];

			finish++;

			while (val[t] == p) {
				val[t] = 0;
				used[now++] = t;
				val[++t]++;
				used[now++] = t;
			}

			if (t == v[cur]) {
				break;
			}
			
		}

		if (finish != n) {
			for (int i = 0; i < now; ++i) {
				val[used[i]] = 0;
			}
			cur = finish;
		}

		else {
			int ans = pw(p, v[cur]);
			for (int i = 0; i < now; ++i) {
				int Q = pw(p, used[i]);
				Q = ((ll) Q * val[used[i]]) % mod;

				ans = (ans-Q+mod) % mod;
				val[used[i]] = 0;

			}

			cout << ans << "\n";
			return;

		}

	}

	cout << "0\n";
	return;
	

}

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}