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

const int N = 201;

int T, n, m, x;
int l[N], r[N];
bool gg[N];

bool inter(int a, int b, int c, int d) {
	return min(b, d) >= max(a, c);
}

map <int, int> mapa;

int main() {
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d%d", &n, &x, &m);
		
		l[0] = x;
		r[0] = x;
		gg[0] = 1;
		
		rep(i, 1, m) {
			gg[i] = 0;
			scanf ("%d%d", l + i, r + i);
			rep(j, 0, i - 1)
				if (gg[j] && inter(l[i], r[i], l[j], r[j]))
					gg[i] = 1;
		}
		
		mapa.clear();
		rep(i, 0, m)
			if (gg[i]) {
				mapa[l[i]]++;
				mapa[r[i] + 1]--;
			}
		
		int cnt = 0, last = 0, ans = 0;
		for (auto it : mapa) {
			if (cnt > 0)
				ans += it.fi - last;
			cnt += it.se;
			last = it.fi;
		}
		
		printf ("%d\n", ans);		
	}
			
	
	return 0;
}