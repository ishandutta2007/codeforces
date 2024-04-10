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

int n, MOD, a[N];
map <int, int> g, kek;

bool dasie(int x) {
	rep(i, 1, n) {
		if (a[i] > x) return false;
		x++;
	}
	return true;
}

int main() {
	scanf ("%d%d", &n, &MOD);
	int MAX = 0;
	rep(i, 1, n) {
		scanf ("%d", a + i);
		MAX = max(MAX, a[i]);
	}
	sort(a + 1, a + n + 1);
	int L = MAX - n + 1;
	int R = MAX + n;
	
	int bsl = L, bsr = R;
	while (bsl < bsr) {
		int m = (bsl + bsr) / 2;
		if (dasie(m))
			bsr = m;
		else
			bsl = m + 1;
	}
	L = bsl;
	
	int wsk = 0;
	rep(i, L, R) {
		while (wsk + 1 <= n && a[wsk + 1] <= i)
			wsk++;
		int v = i - wsk % MOD;
		int now = v;
		//cat(i);
		while (true) {
			if (g.count(now) || i - now + 1 > n) break;
			//cat(now);
			g[now] = 1;
			now -= MOD;
		}
	}
	vector <int> res;
	per(i, L, MAX) 
		if (!g.count(i)) res.pb(i);
	sort(all(res));
	printf ("%d\n", ss(res));
	for (auto it : res) printf ("%d ", it);
	
	
	return 0;
}