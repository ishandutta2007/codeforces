#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int arr[1<<25];
int pref[(1<<25) + 7];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	ll ans = 0;

	for (int i = 0; i < 25; ++i) {
		int K = (1<<(i+1));
		for (int j = 0; j < n; ++j) {
			arr[v[j] % K]++;
		}
		pref[0] = 0;
		for (int j = 0; j < (1<<(i+1)); ++j) {
			pref[j+1] = pref[j] + arr[j];
		}

		ll Z = 0;

		for (int j = 0; j < (1<<(i+1)); ++j) {
			int zero = (1<<i) - j - 1;
			if (zero >= 0) {
				int tam = pref[zero+1];
				Z += (ll) tam * arr[j];
			}

			int bzero = ((1<<(i+1)) - 1) ^ j;
			int L = bzero+1, R = bzero+(1<<i);

			R = min(R, ((1<<(i+1)) - 1));
			if (L <= R) {
				int tam = pref[R+1] - pref[L];
				Z += (ll) tam * arr[j];
			}

		}

		for (int j = 0; j < (1<<(i+1)); ++j) {
			int T = j+j;
			if (!(T & (1<<i))) {
				ll Q = arr[j];
				Z -= Q;
			}
		}

		Z = ((ll) n * (n-1)) - Z;
		Z /= 2;
		
		if (Z%2 != 0) ans += (1<<i);

		for (int j = 0; j < n; ++j) {
			arr[v[j] % K]--;
		}
	}

	cout << ans;

}