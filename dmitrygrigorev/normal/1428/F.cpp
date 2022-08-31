#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 1e6;
int start[N];
ll res[N];

main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < N; ++i) {
		start[i] = -1;
		res[i] = 0;
	}

	ll ans = 0;

	int n;
	string s;

	cin >> n >> s;

	int mx = 0;
	ll last = 0;

	for (int i = n-1; i >= 0; i--) {

		if (s[i] == '1') {

			last = 0;
			mx++;

			last += (ll) mx * (mx + 1) / 2;

			if (start[mx + 1] == -1) {
				int rem = n - i - mx;
				last += (ll) rem * mx;
			}

			else {
				int rem = n - i - mx - (n - start[mx + 1]);
				last += (ll) rem * mx + res[mx + 1];
			}
		}

		else {
			if (mx > 0) {
				for (int j = mx; j >= 1; j--) {
					int dist;
					if (start[j+1] != -1) dist = start[j + 1] - (i + j);
					else dist = n - (i + j);

					start[j] = i + j;
					res[j] = res[j + 1] + (ll) dist * j;
				}
			}
			mx = 0;
		}

		ans += last;
	}

	cout << ans;





}