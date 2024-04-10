#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;		

const int N = 1e5 + 10;

int n, h, m, k;
int he, minuta[N];
vector <int> vals;

int pref(int x) {
	return (int) (upper_bound(all(vals), x) - vals.begin());
}

int main() {
	scanf ("%d%d%d%d", &n, &h, &m, &k);
	m /= 2;
	k--;
	if (!k) {
		printf ("0 0\n");
		return 0;
	}
	rep(i, 1, n) {
		scanf ("%d%d", &he, minuta + i);
		minuta[i] %= m;
		vals.pb(minuta[i]);
	}
	sort(all(vals));
	pair<int, int> mx = {1 << 30, 0};
	
	rep(i, 1, n) {
		int r = minuta[i];
		int l = (r - k + m) % m;
		int now = 0;
		if (l <= r) now = pref(r - 1) - pref(l - 1);
		else now = pref(r - 1) + pref(1 << 30) - pref(l - 1);
		mx = min(mx, {now, r});
	}
	
	printf ("%d %d\n", mx.fi, mx.se);
	
	rep(i, 1, n) {
		int r = mx.se;
		int l = (r - k + m) % m;
		if (l <= r) {
			if (l <= minuta[i] && minuta[i] < r)
				printf ("%d ", i);
		}
		else if (minuta[i] < r || l <= minuta[i])
			printf ("%d ", i);
	}
		
	return 0;
}