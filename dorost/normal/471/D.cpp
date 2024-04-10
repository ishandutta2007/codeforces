/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, M = 587419138394947;
int a[N], b[N];

int32_t main() {
	srand(6985);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, w;
	cin >> n >> w;
	if (w == 1) {
		cout << n << '\n';
		return 0;
	}
	set <int> st;
	map <int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++) {
		a[i] = a[i] - a[i + 1];
		st.insert(a[i]);
	}
	for (int i = 0; i < w; i++)
		cin >> b[i];
	for (int i = 0; i < w - 1; i++) {
		b[i] = b[i] - b[i + 1];
		st.insert(b[i]);
	}
	int cnt = 0;
	for (auto x : st) {
		cnt += (rand() % 10) + 1;
		mp[x] = cnt;
	}
	n--;
	w--;
	for (int i = 0; i < w; i++) {
		b[i] = mp[b[i]];
	}
	for (int i = 0; i < n; i++) {
		a[i] = mp[a[i]];
	}
	int h = 1823;
	int ans = 0;
	for (int i = 0; i < w; i++) {
		ans *= h;
		ans += b[i];
		ans %= M;
	}
	if (w > n) {
		cout << 0;
		return 0;
	}
	int wh = 0;
	cnt = 0;
	for (int i = 0; i < w; i++) {
		wh *= h;
		wh += a[i];
		wh %= M;
	}
	if (wh == ans)
		cnt++;
	int x = 1;
	for (int i = 0; i < w - 1; i++) {
		x *= h;
		x %= M;
	}
	for (int i = w; i < n; i++) {
		wh -= x * a[i - w];
		wh %= M;
		wh += M;
		wh %= M;
		wh *= h;
		wh += a[i];
		wh %= M;
		if (wh == ans)
			cnt++;
	}
	cout << cnt;
}