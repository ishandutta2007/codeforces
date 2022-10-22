#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

const int N = 1e5 + 100;

int n, m, a, b;
int e[N], f[N], in[N];

vector <int> v[N];
queue <int> q;

bool ok(int x) {
	while (ss(q)) q.pop();
	rep(i, 1, n) {
		in[i] = 0;
		v[i].clear();
	}
	rep(i, 1, x) {
		v[e[i]].pb(f[i]);
		in[f[i]]++;
	}
	rep(i, 1, n) if (!in[i]) q.push(i);
	int qw = 0;
	
	while (true) {
		if (ss(q) > 1) return false;
		if (ss(q) == 0) return qw == n;
		int r = q.front();
		q.pop();
		qw++;
		for (auto it : v[r]) {
			in[it]--;
			if (!in[it]) q.push(it);
		}
	}
}
	

int main() {
	scanf ("%d%d", &n, &m);
	rep(i, 1, m) {
		scanf ("%d%d", e + i, f + i);
	}
	int l = 1;
	int r = m + 1;
	while (l < r) {
		int m = (l + r) / 2;
		if (ok(m)) r = m;
		else l = m + 1;
	}
	if (l == m + 1) printf ("-1\n");
	else printf ("%d\n", l);
	
	
	
	return 0;
}