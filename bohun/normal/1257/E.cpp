#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
 
using namespace std;

const int nax = 2e5 + 111;
const int pod = (1 << 18);

int k1, k2, k3;
int a[nax], b;

int t[2 * pod];
int lazy[2 * pod];

void push(int u) {
	lazy[2 * u] += lazy[u];
	lazy[2 * u + 1] += lazy[u];
	t[2 * u] += lazy[u];
	t[2 * u + 1] += lazy[u];
	lazy[u] = 0;
}

void add(int x, int y, int c, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		lazy[u] += c;
		t[u] += c;
		return;
	}
	int m = (l + r) / 2;
	push(u);
	if(x <= m)
		add(x, y, c, 2 * u, l, m);
	if(m < y)
		add(x, y, c, 2 * u + 1, m + 1, r);
	t[u] = max(t[2 * u], t[2 * u + 1]);
}
 
int main() {	
	scanf("%d %d %d", &k1, &k2, &k3);
	FOR(i, k1) {
		scanf("%d", &b);
		a[b] = 0;
	}
	FOR(i, k2) {
		scanf("%d", &b);
		a[b] = 1;
	}
	FOR(i, k3) {
		scanf("%d", &b);
		a[b] = 2;
	}
	int n = k1 + k2 + k3;
	for(int i = 1; i <= n; ++i) {
		if(a[i] == 1)
			add(i + 1, n + 1, 1);
		if(a[i] == 2)
			add(1, i, 1);
	}
	int best = t[1];
	int ile = 0;
	for(int i = 1; i <= n; ++i) {
		ile += a[i] == 0;
		if(a[i] == 1) {
			add(i + 1, n + 1, -1);
		}
		if(a[i] == 2) {
			add(1, i, -1);
		}
		best = max(best, ile + t[1]);
	}
	printf("%d\n", n - best);
	
	
	
	
	
	return 0;
}