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
	
const int T = 1 << 20;	
	
int cnt[T + T];

void add(int x, int c) {
	x += T;
	while (x) {
		cnt[x] += c;
		x /= 2;
	}
}	

int query(int k, int v = 1, int l = 0, int r = T - 1) {
	if (l == r) return l;
	int m = (l + r) / 2;
	if (cnt[2 * v] >= k) return query(k, 2 * v, l, m);
	else return query(k - cnt[2 * v], 2 * v + 1, m + 1, r);
}
	
int n, q;
int a;

int main() {
	scanf ("%d%d", &n, &q);
	rep(i, 1, n) {
		scanf ("%d", &a);
		cnt[a + T]++;
	}
	per(i, 1, T - 1)
		cnt[i] = cnt[2 * i] + cnt[2 * i + 1];
	while (q--) {
		scanf ("%d", &a);
		if (a > 0) add(a, 1);
		else add(query(-a), -1);
	}
	if (cnt[1] == 0) printf ("0\n");
	else printf ("%d\n", query(1));
	
	return 0;
}