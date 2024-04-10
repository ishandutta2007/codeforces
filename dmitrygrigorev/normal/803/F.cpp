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

const int N = 200007;
int g[N];
int cnt[N];

int arr[N];

int bp(int x, int y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	if (y%2) return ((ll) x * bp(x, y-1)) % mod;

	int t = bp(x, y/2);
	return ((ll) t * t) % mod;

}

int main(){
#ifdef LOCAL
	freopen("I_input.txt", "r", stdin);
	//freopen("I_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		arr[x]++;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			cnt[i] += arr[j];
		}
	}

	for (int i = N-1; i > 0; i--) {
		g[i] = (bp(2, cnt[i]) - 1 + mod)%mod;
		for (int j = i+i; j < N; j += i) {
			g[i] -= g[j];
			if (g[i] < 0) g[i] += mod;
		}
	}

	cout << g[1];

	

}