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
 
const int N = 200005;
 
int T, k, n, a[N], b[N], s[N];
 
void tak() {
	printf ("yes\n");
}
 
map <int, int> m;

int psoms(int l, int r) {
	if (l > r) return -10;
	int s = 0;
	rep(i, l, r) {
		s += b[i];
		if (s > 0 && i != l) return 1;
		s = max(s, b[i]);
	}
	return -1;
}
 
void solve() {
	scanf ("%d%d", &n, &k);
	int cnt = 0;
	vector <int> ajc;
	rep(i, 1, n) {
		scanf ("%d", a+i);
		if (a[i] < k) b[i] = -1;
		if (a[i] > k) b[i] = +1;
		if (a[i] == k) b[i] = 0;
		if (b[i] == 0) {
			cnt++;
			ajc.pb(i);
		}
	}
	if (ss(ajc)) {
		if (psoms(1, ajc[0] - 1) > 0 || psoms(ajc.back() + 1, n) > 0) {
			tak(); return;
		}
		rep(i, 0, ss(ajc) - 2) {
			if (psoms(ajc[i] + 1, ajc[i + 1] - 1) > 0) {
				tak(); return;
			}
		}
	}
	
	rep(i, 2, n) {
		if (b[i] == 1 && b[i - 1] == 1 && cnt > 0) {
			tak();
			return ;
		}
	}
	rep(i, 3, n) {
		if (b[i] == 1 && b[i - 1] == -1 && b[i - 2] == 1 && cnt > 0) {
			tak();
			return;
		}
	}
	
	if (n == 1 && a[1] == k) {
		tak(); return;
	}
	rep(i, 2, n) {
		if (b[i] == 0 && b[i - 1] == 0) {
			tak(); return;
		}
		if (b[i] == 0 && b[i - 1] == 1) {
			tak(); return;
		}
	}
	rep(i, 1, n - 1) {
		if (b[i] == 0 && b[i + 1] == 1) {
			tak(); return;
		}
	}
	m.clear();
	int s = 0;
	rep(i, 1, n) {
		if (b[i] == 0 && m.find(s) != m.end()) {
			tak(); return;
		}
		m[s] = 12321;
		s += (b[i] != 0 ? b[i] : 1);
	}
	m.clear();
	s = 0;
	per(i, 1, n) {
		if (b[i] == 0 && m.find(s) != m.end()) {
			tak(); return;
		}
		m[s] = 12321;
		s += (b[i] != 0 ? b[i] : 1);
	}
		
	printf ("no\n");
}
 
int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
	return 0;
}