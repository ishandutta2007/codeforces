#include<bits/stdc++.h>
using namespace std;
const int MAXN = 524288;
const int MAXC = 256;
const double eps = 1e-3;
const double pi = acos(-1);
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
struct point {double x, y; };
point operator + (point a, point b) {return (point) {a.x + b.x, a.y + b.y}; }
point operator - (point a, point b) {return (point) {a.x - b.x, a.y - b.y}; }
point operator * (point a, point b) {return (point) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x}; }
point operator / (point a, double x) {return (point) {a.x / x, a.y / x}; }
int sa[MAXN], sc[MAXN], sg[MAXN], st[MAXN];
int ta[MAXN], tc[MAXN], tg[MAXN], tt[MAXN];
point res[MAXN]; char s[MAXN], t[MAXN];
int n, m, k, N, Log, cnt[MAXC], home[MAXN];
bool ans[MAXN];
void FFTinit() {
	for (int i = 0; i < N; i++) {
		int tmp = i, ans = 0;
		for (int j = 1; j <= Log; j++) {
			ans <<= 1;
			ans += tmp & 1;
			tmp >>= 1;
		}
		home[i] = ans;
	}
}
void FFT(point *a, int mode) {
	for (int i = 0; i < N; i++)
		if (home[i] < i) swap(a[i], a[home[i]]);
	for (int len = 2; len <= N; len <<= 1) {
		point delta = (point) {cos(2 * pi / len * mode), sin(2 * pi / len * mode)};
		for (int i = 0; i < N; i += len) {
			point now = (point) {1, 0};
			for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
				point tmp = a[j];
				point tnp = a[k] * now;
				a[j] = tmp + tnp;
				a[k] = tmp - tnp;
				now = now * delta;
			}
		}
	}
	if (mode == -1) {
		for (int i = 0; i < N; i++)
			a[i] = a[i] / (4 * N);
	}
}
int main() {
	read(n), read(m), read(k);
	scanf("\n%s\n%s", s, t);
	N = 1, Log = 0;
	while (N <= n) {
		N <<= 1;
		Log++;
	}
	reverse(t, t + m);
	for (int i = 0; i < m; i++) {
		if (t[i] == 'A') ta[i] = 1;
		if (t[i] == 'C') tc[i] = 1;
		if (t[i] == 'G') tg[i] = 1;
		if (t[i] == 'T') tt[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
		if (cnt['A']) sa[i] = 1;
		if (cnt['C']) sc[i] = 1;
		if (cnt['G']) sg[i] = 1;
		if (cnt['T']) st[i] = 1;
		if (i >= k) cnt[s[i - k]]--;
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = n - 1; i >= 0; i--) {
		cnt[s[i]]++;
		if (cnt['A']) sa[i] = 1;
		if (cnt['C']) sc[i] = 1;
		if (cnt['G']) sg[i] = 1;
		if (cnt['T']) st[i] = 1;
		if (i + k <= n - 1) cnt[s[i + k]]--;
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < m; i++)
		cnt[t[i]]++;
	FFTinit(); memset(ans, true, sizeof(ans));
	for (int i = 0; i < N; i++)
		res[i] = (point) {sa[i] + ta[i], sa[i] - ta[i]};
	FFT(res, 1);
	for (int i = 0; i < N; i++)
		res[i] = res[i] * res[i];
	FFT(res, -1);
	for (int i = m - 1; i < n; i++)
		if (fabs(res[i].x - cnt['A']) > eps) ans[i] = false;
	for (int i = 0; i < N; i++)
		res[i] = (point) {sc[i] + tc[i], sc[i] - tc[i]};
	FFT(res, 1);
	for (int i = 0; i < N; i++)
		res[i] = res[i] * res[i];
	FFT(res, -1);
	for (int i = m - 1; i < n; i++)
		if (fabs(res[i].x - cnt['C']) > eps) ans[i] = false;
	for (int i = 0; i < N; i++)
		res[i] = (point) {sg[i] + tg[i], sg[i] - tg[i]};
	FFT(res, 1);
	for (int i = 0; i < N; i++)
		res[i] = res[i] * res[i];
	FFT(res, -1);
	for (int i = m - 1; i < n; i++)
		if (fabs(res[i].x - cnt['G']) > eps) ans[i] = false;
	for (int i = 0; i < N; i++)
		res[i] = (point) {st[i] + tt[i], st[i] - tt[i]};
	FFT(res, 1);
	for (int i = 0; i < N; i++)
		res[i] = res[i] * res[i];
	FFT(res, -1);
	for (int i = m - 1; i < n; i++)
		if (fabs(res[i].x - cnt['T']) > eps) ans[i] = false;
	int sum = 0;
	for (int i = m - 1; i < n; i++)
		sum += ans[i];
	writeln(sum);
	return 0;
}