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

const int N = 2e5 + 500;
const int S = N * 40;

int s[S], ch[S][2], cnt;

void insert(int &x, int l, int r, int p) {
	if (!x) x = ++cnt;
	s[x]++;
	if (l == r) return;
	int m = l + r >> 1;
	if (p <= m) insert(ch[x][0], l, m, p);
	else insert(ch[x][1], m + 1, r, p);
}

void split(int t1, int &t2, int k) {
	if (!t1) return;
	t2 = ++cnt;
	int sl = s[ch[t1][0]];
	if (sl < k) split(ch[t1][1], ch[t2][1], k - sl);
	else swap(ch[t1][1], ch[t2][1]);
	if (sl > k) split(ch[t1][0], ch[t2][0], k);
	s[t2] = s[t1] - k; s[t1] = k;
}		
	
int merge(int t1, int t2) {
	if (!t1 || !t2) return t1 ^ t2;
	for (int i = 0; i < 2; ++i)
		ch[t1][i] = merge(ch[t1][i], ch[t2][i]);
	s[t1] += s[t2];
	return t1;
}
	
int kth(int x, int l, int r, int k) {
	if (l == r) return l;
	int m = l + r >> 1, ls = s[ch[x][0]];
	if (k <= ls) return kth(ch[x][0], l, m, k);
	return kth(ch[x][1], m + 1, r, k - ls);
}

int smaller(int x, int l, int r, int p) { // <=
	if (!x) return 0;
	if (l == r) return s[x];
	int m = l + r >> 1;
	if (p <= m) return smaller(ch[x][0], l, m, p);
	return s[ch[x][0]] + smaller(ch[x][1], m + 1, r, p);
}

int n, q, root[N], ans[N];

int main() {
	rep(i, 1, 100) root[i] = ++cnt;
	scanf ("%d", &n);
	rep(i, 1, n) {
		int a;
		scanf ("%d", &a);
		insert(root[a], 0, n, i);
	}
	scanf ("%d", &q);
	while (q--) {
		int l, r, x, y;
		scanf ("%d%d%d%d", &l, &r, &x, &y);
		int cnt0 = smaller(root[x], 0, n, l - 1), cnt1 = smaller(root[x], 0, n, r), r0, r1;
		split(root[x], r0, cnt0);
		split(r0, r1, cnt1 - cnt0);
		root[x] = merge(root[x], r1);
		root[y] = merge(root[y], r0);
	}
	rep(i, 1, 100) 
		rep(j, 1, smaller(root[i], 0, n, n))
			ans[kth(root[i], 0, n, j)] = i;
	rep(i, 1, n) printf ("%d ", ans[i]);	
	return 0;
}