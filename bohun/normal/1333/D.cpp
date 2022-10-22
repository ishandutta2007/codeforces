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

const int N = 3005 * 3005;

int n, k;
char s[N];
vector <int> v[3000009];
int t[N];
vector <int> se, se2;
vector <vector <int>> ans;

int main() {
	scanf ("%d%d", &n, &k);
	scanf ("%s", s + 1);
	rep(i, 1, n) {
		t[i] = (s[i] == 'R' ? 1 : 0);
	}
	rep(i, 1, n - 1) {
		if (t[i] == 1 && t[i + 1] == 0) se.pb(i);
	}
	int f = 0;
	ll sum = 0;
	while (ss(se)) {
		f++;
		for (auto it : se) {
			v[f].pb(it);
			sum++;
			t[it] = 0;
			t[it + 1] = 1;
		}
		se2.clear();
		for (auto it : se) {
			if (it - 1 >= 1 && t[it - 1] == 1 && t[it] == 0) se2.pb(it - 1);
			if (it + 1 < n && t[it + 1] == 1 && t[it + 2] == 0) se2.pb(it + 1);
		}
		sort(all(se2));
		se2.erase(unique(all(se2)), se2.end());
		se = se2;
	}
	if (!(f <= k && k <= sum)) return printf ("-1\n"), 0;
	int q = f;
	for (int i = 1; i <= f; ++i) {
		while (ss(v[i]) > 1 && q != k) {
			q++;
			int ele = v[i].back();
			ans.pb({ele});
			v[i].pop_back();
		}
		ans.pb(v[i]);
	}
	for (auto it : ans) {
		printf ("%d ", ss(it));
		for (auto i : it) printf ("%d ", i);
		printf ("\n");
	}
	
	
    return 0;
}