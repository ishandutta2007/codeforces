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

int n;

ll ask(int t, int a, int b, int c) {
	printf ("%d %d %d %d\n", t, a, b, c);
	fflush(stdout);
	ll x;
	scanf ("%lld", &x);
	return x;
}

vector <int> v[2], f[4];
ll pole[1100];

int main() {
	scanf ("%d", &n);
	rep(i, 3, n) {
		int id = ask(2, 1, 2, i);
		id = (id == 1 ? 0 : 1);
		pole[i] = ask(1, 1, 2, i);
		v[id].pb(i);
	}
	rep(i, 0, 1) {
		if (v[i].empty()) continue;
		pair<ll, int> c = {-1, 0};
		for (auto it : v[i])
			c = max(c, {pole[it], it});
		pole[c.se]++;
		f[2 * i].pb(c.se);
		for (auto it : v[i]) {
			if (it == c.se) continue;
			if (ask(2, 1, c.se, it) == 1)
				f[2 * i].pb(it);
			else
				f[2 * i + 1].pb(it);
		}
	}
	rep(i, 0, 1) {
		sort(all(f[2 * i]), [](int a, int b) {
			return pole[a] < pole[b];
		});
		sort(all(f[2 * i + 1]), [](int a, int b) {
			return pole[a] > pole[b];
		});
		reverse(all(f[2 * i]));
		reverse(all(f[2 * i + 1]));
	}
	vector <int> ans;
	ans.pb(1);
	for (auto i : {3, 2})
		for (auto j : f[i])
			ans.pb(j);
	ans.pb(2);
	for (auto i : {1, 0})
		for (auto j : f[i])
			ans.pb(j);
	printf ("0");
	for (auto it : ans) printf (" %d", it);
	printf ("\n");
	fflush(stdout); 
			
		
	
	return 0;
}