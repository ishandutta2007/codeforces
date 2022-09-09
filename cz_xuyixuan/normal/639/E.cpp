#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double eps = 1e-10;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
double sumt, pre[MAXN]; int Min[MAXN], Max[MAXN];
int n, a[MAXN], b[MAXN], p[MAXN], t[MAXN];
bool cmp(int x, int y) {
	return p[x] < p[y];
}
bool cnp(int x, int y) {
	return 1ll * t[x] * p[y] < 1ll * t[y] * p[x];
}
bool check(double c) {
	double last;
	for (int i = 1, nxt; i <= n; i = nxt + 1) {
		nxt = i; while (nxt + 1 <= n && p[b[i]] == p[b[nxt + 1]]) nxt++;
		if (i != 1) {
			for (int j = i; j <= nxt; j++) {
				double cur = p[b[j]] * (1 - c * pre[Max[b[j]]] / sumt);
				if (cur < last) return false;
			}
		}
		last = 0;
		for (int j = i; j <= nxt; j++)
			chkmax(last, p[b[j]] * (1 - c * (pre[Min[b[j]] - 1] + t[b[j]]) / sumt));
	}
	return true;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		a[i] = b[i] = i;
	for (int i = 1; i <= n; i++)
		read(p[i]);
	for (int i = 1; i <= n; i++)
		read(t[i]), sumt += t[i];
	sort(a + 1, a + n + 1, cnp);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + t[a[i]];
	for (int i = 1, nxt; i <= n; i = nxt + 1) {
		nxt = i; while (nxt + 1 <= n && 1ll * p[a[i]] * t[a[nxt + 1]] == 1ll * t[a[i]] * p[a[nxt + 1]]) nxt++;
		for (int j = i; j <= nxt; j++) {
			Min[a[j]] = i;
			Max[a[j]] = nxt;
		}
	}
	double l = 0, r = 1;
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	printf("%.10lf\n", (l + r) / 2);
	return 0;
}