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

const int N = 3e5 + 4;
const int T = 1 << 19;

int g[T + T];

void init() {
	rep(i, 1, T + T - 1) g[i] = -1e9;
}

void Set(int x, int y) {
	x += T;
	g[x] = y;
	for (x /= 2; x; x /= 2)
		g[x] = max(g[2 * x], g[2 * x + 1]);
}

int qw(int l, int r) {
	int res = -1e9;
	for (l += T, r += T + 1; l < r; l /= 2, r /= 2) {
		if (l & 1) res = max(res, g[l++]);
		if (r & 1) res = max(res, g[--r]);
	}
	return res;
}

int u[T + T];

void init2() {
	rep(i, 1, T + T - 1)
		u[i] = 1e9;
}

void zmin(int l, int r, int x) {
	for (l += T, r += T + 1; l < r; l /= 2, r /= 2) {
		if (l & 1) {
			u[l] = min(u[l], x);
			l++;
		}
		if (r & 1) {
			r--;
			u[r] = min(u[r], x);
		}
	}
}

int bound(int x) {
	int res = 1e9;
	for (x += T; x; x /= 2)
		res = min(res, u[x]);
	return res;
}

int n, m, z[N], out[N];

struct gao {
	int l, r, x;
};
vector <gao> f;
set <int> S;

void nope() {
	printf ("NO\n");
	exit(0);
}

vector <int> bits[30];
map <int, vector <int>> M;

void add(int x, int id) {
	rep(i, 0, 29)
		if ((x >> i) & 1)
			bits[i].pb(id);
}

int main() {	
	scanf ("%d%d", &n, &m);
	
	init(); init2();
	
	rep(i, 1, m) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c);
		if (a == 1) {
			int d;
			scanf ("%d", &d);
			int e = qw(b, c);
			if (e > d) nope();
			if (e < d) f.pb({b, c, d});
			zmin(b, c, d);
		}
		else {
			if (qw(b, b) == -1e9) {
				z[b] = bound(b);
				f.pb({-1, -1, b});
			}
			Set(b, c);
		}
	}
	rep(i, 1, n)
		if (qw(i, i) == -1e9)
			z[i] = bound(i);
			
	rep(i, 1, n)
		M[z[i]].pb(i);
	
	int OR = 0;
	rep(i, 1, n) S.insert(i);
	for (auto a : f) {
		if (a.l == -1) {
			if (S.count(a.x)) {
				add(z[a.x], a.x);
				S.erase(a.x);
			}
			continue;
		}
		
		bool flag = false;
		for (auto b : M[a.x]) {
			if (a.l <= b && b <= a.r && S.count(b)) {
				flag = true;
				out[b] = a.x;
				OR |= out[b];
				S.erase(b);
				break;
			}
		}
		
		if (!flag) nope();
		
	}
	
	for (auto it : S) 
		add(z[it], it);
	
	per(i, 0, 29) {
		if (bits[i].empty()) continue;
		if ((OR >> i) & 1) {
			int a = bits[i][0];
			out[a] |= (1 << i) - 1;
			break;
		}
		if (ss(bits[i]) >= 2) {
			int a = bits[i][0], b = bits[i][1];
			out[a] |= (1 << i);
			out[b] |= (1 << i) - 1;
			break;
		}
		int a = bits[i][0];
		out[a] |= (1 << i);
	}
	printf ("YES\n");
	rep(i, 1, n)
		printf ("%d ", out[i]);
	
	return 0;
}