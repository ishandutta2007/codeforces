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

const int nax = 2e5 + 100;

int n, k;
int a[nax];
int b[nax];
int c[nax];	 

vector <int> v[nax];
vector <int> qw;

bool ok(int cnt) {
	rep(i, 1, cnt) v[i].clear();
	qw.clear();
	per(i, 1, k) {
		int x = c[i] - c[i + 1];
		if (x > 0) {
			rep(j, 1, cnt) {
				rep(g, 1, x) {
					qw.pb(j);
					if (ss(qw) > n) break;
				}
				if (ss(qw) > n) break;
			}
		}
		rep(j, 1, b[i]) {
			if (ss(qw) == 0) return false;
			int x = qw.back();
			qw.pop_back();
			v[x].pb(i);
		}
	}
	return true;
}						
	

int main() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) {
		scanf ("%d", a+i);
		b[a[i]]++;
	}
	rep(i, 1, k) scanf ("%d", c+i);
	c[k + 1] = 0;
	
	int l = 1, r = n;
	while (l < r) {
		int m = (l + r) / 2;
		if (ok(m)) r = m;
		else l = m + 1;
	}
	ok(l);
	printf ("%d\n", l);
	rep(i, 1, l) {
		printf ("%d ", ss(v[i]));
		for (auto it : v[i])
			printf ("%d ", it);
		printf ("\n");
	}
	
	return 0;
}