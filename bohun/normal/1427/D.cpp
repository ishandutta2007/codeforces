#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

int n;
vector <pair<int, int>> a;
set <int> S;

vector <pair<int, int>> f(vector <pair<int, int>> x) {
	vector <pair<int, int>> q;
	for (auto [a, cnt] : x) {
		if (!q.empty() && a == q.back().fi + q.back().se) {
			q.back().se += cnt;
		}
		else q.pb({a, cnt});
	}
	S.clear();
	for (auto [a, cnt] : q)
		S.insert(a);
	return q;
}

vector <vector <int>> ans;

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		int x;
		scanf ("%d", &x);
		a.pb({x, 1});
	}
	a = f(a);
	while (sz(a) > 1) {
		int siz = sz(a);
		bool done = false;
		rep(i, 0, siz - 1) {
			if (done) break;
			auto it = S.lower_bound(a[i].fi);
			it++;
			if (it == S.end()) continue;
			rep(j, 0, i - 1) {
				if (*it == a[j].fi) {
					done = true;
					int s0 = 0, s1 = 0, s2 = 0, s3 = 0;
					
					rep(k, 0, j - 1)
						s0 += a[k].se;
					
					s1 = a[j].se;
					
					rep(k, j + 1, i)
						s2 += a[k].se;
					
					rep(k, i + 1, siz - 1)
						s3 += a[k].se;
					
					vector <int> now;
					if (s0) now.pb(s0);
					if (s1) now.pb(s1);
					if (s2) now.pb(s2);
					if (s3) now.pb(s3);
					ans.pb(now);
					
					vector <pair<int, int>> b;
					
					rep(k, i + 1, siz - 1)
						b.pb(a[k]);
					
					rep(k, j + 1, i)
						b.pb(a[k]);
					
					b.pb(a[j]);
					
					rep(k, 0, j - 1)
						b.pb(a[k]);
						
					a = b;
					
					break;
				}
			}
		}
		a = f(a);
	}
				
	printf ("%d\n", sz(ans));
	for (auto x : ans) {
		printf ("%d ", sz(x));
		for (auto y : x)
			printf ("%d ", y);
		puts ("");
	}
	
	return 0;
}