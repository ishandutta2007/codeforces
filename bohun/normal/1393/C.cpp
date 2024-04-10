#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;	

const int N = 200100;

int n, cnt[N], c[N];
vector <pair<int, int>> add[N];
set <pair<int, int>> S;

bool ok(int d) {
	S.clear();
	rep(i, 1, n) S.insert({cnt[i], i}), add[i].clear(), c[i] = cnt[i];
	rep(i, 1, n) {
		for (auto it : add[i]) S.insert(it);
		if (S.empty()) return false;
		int x = (--S.end())->se;
		if (!c[x]) return false;
		auto it = *(--S.end());
		S.erase(it);
		c[x]--;
		add[i + d + 1].pb({c[x], x});
	}
	return true;
}

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) cnt[i] = 0;
	rep(i, 1, n) {
		int a;scanf("%d", &a);cnt[a]++;
	}
	int l = 0, r = n - 1;
	while (l < r) {
		int m = (l + r + 1) / 2;
		if (ok(m)) l = m;
		else r = m - 1;
	}
	printf ("%d\n", l);
}
	

int main() {	
	int T;
	scanf ("%d", &T);
	while (T--) solve();
	
	return 0;
}