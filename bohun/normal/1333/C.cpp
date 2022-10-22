#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define sz(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;

const int nax = 2e5 + 100;

int n;
int a[nax];
ll b[nax];

map <ll, int> m;

void solve() {
	m.clear();
	scanf ("%d", &n);
	m[0] = 0;
	int last = -1;
	ll res = 0;
	rep(i, 1, n) {
		scanf ("%d", a + i);
		b[i] = b[i - 1] + a[i];
		if (m.find(b[i]) != m.end()) last = max(last, m[b[i]]);
		res += i - last - 1;
		m[b[i]] = i;
	}
	printf ("%lld\n", res);
}

int main() {
	int T = 1;
	while (T--) solve();
		
	
    return 0;
}