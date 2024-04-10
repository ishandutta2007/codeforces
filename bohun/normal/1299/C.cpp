#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define LL long long
#define LD long double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 1e6 + 11;

int n;
int a[nax];

vector <pair<LD, int>> v;

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", a + i);
	}
	v.pb({1e18, 0});
	for (int i = n; 1 <= i; --i) {
		LD y = a[i];
		while (ss(v) >= 2) {
			int dl = v.back().se;
			LD diff = v[ss(v) - 2].fi - v.back().fi;
			LD x = (LD) dl * diff;
			if (diff < 1e17 && x + v[ss(v) - 2].fi <= y) {
				int dl = v.back().se;
				v.pop_back();
				v.back().se += dl;
				y -= x;
			}
			else {
				if (y <= v.back().fi) break;
				pair <LD, int> w = v.back();
				w.fi = (y + (LD) w.fi * w.se) / (w.se + 1);
				v.back() = w;
				y = (LD) v.back().fi;
				break;
			}
		}
		v.pb({y, 1});
	}
	reverse(v.begin(), v.end());
	for (auto it : v) {
		if (it.fi == 1e18) break;
		int x = it.se;
		while (x--) {
			printf ("%.10Lf\n", it.fi);
		}
	}



	return 0;
}