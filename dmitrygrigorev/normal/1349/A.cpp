#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 200007;
int m1[N];
int m2[N];
int have[N];

void deg(int &x, int y) {
	int cnt = 0;
	bool was = false;

	have[y]++;

	while (x%y == 0) {
		was = true;
		x /= y;
		cnt++;
	}

	if (cnt < m1[y]) {
		m2[y] = m1[y];
		m1[y] = cnt;
	}
	else m2[y] = min(m2[y], cnt);
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < N; ++i) {
		m1[i] = 1e9;
		m2[i] = 1e9;
	}

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;

		int T = x;
		for (int j = 2; j*j <= T; ++j) {
			deg(x, j);
		}

		if (x != 1) deg(x, x);
	}

	ll res = 1;

	//cout << have[5] << endl;

	for (int i = 0; i < N; ++i) {
		if (have[i] <= n-2) continue;
		//cout << i << " " << have[i] << endl;
		if (have[i] == n-1) {
			for (int j = 0; j < m1[i]; ++j) res *= i;
		}
		else for (int j = 0; j < m2[i]; ++j) res *= i;
	}

	cout << res;

}