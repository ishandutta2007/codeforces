#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
namespace rmq {
	const int MAXN = 3e5 + 5;
	const int MAXLOG = 19;
	int Max[MAXN][MAXLOG], Min[MAXN][MAXLOG], Log[MAXN];
	int queryMax(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return max(Max[l][tmp], Max[r - (1 << tmp) + 1][tmp]);
	}
	int queryMin(int l, int r) {
		int len = r - l + 1, tmp = Log[len];
		return min(Min[l][tmp], Min[r - (1 << tmp) + 1][tmp]);
	}
	void init(int *a, int n) {
		for (int i = 1; i <= n; i++) {
			Min[i][0] = a[i];
			Max[i][0] = a[i];
			Log[i] = Log[i - 1];
			if ((1 << (Log[i] + 1)) <= i) Log[i]++;
		}
		for (int t = 1; t < MAXLOG; t++)
		for (int i = 1, j = (1 << (t - 1)) + 1; j <= n; i++, j++) {
			Max[i][t] = max(Max[i][t - 1], Max[j][t - 1]);
			Min[i][t] = min(Min[i][t - 1], Min[j][t - 1]);
		}
	}
}
int n, a[MAXN], cnt[MAXN * 2]; ll ans;
void solve(int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	solve(l, mid);
	solve(mid + 1, r);
	// Both l
	for (int i = mid, Min = a[i], Max = a[i], pos = mid; i >= l; i--) {
		chkmin(Min, a[i]), chkmax(Max, a[i]);
		while (pos + 1 <= r && a[pos + 1] > Min && a[pos + 1] < Max) pos++;
		int j = i + Max - Min; ans += j > mid && j <= pos && rmq :: queryMin(i, j) == Min && rmq :: queryMax(i, j) == Max;
	}
	// Both r
	for (int i = mid + 1, Min = a[i], Max = a[i], pos = mid + 1; i <= r; i++) {
		chkmin(Min, a[i]), chkmax(Max, a[i]);
		while (pos - 1 >= l && a[pos - 1] > Min && a[pos - 1] < Max) pos--;
		int j = i - Max + Min; ans += j <= mid && j >= pos && rmq :: queryMin(j, i) == Min && rmq :: queryMax(j, i) == Max;
	}
	// l Max, r Min
	int pa = mid, pb = mid + 1;
	for (int i = mid, Min = a[i], Max = a[i]; i >= l; i--) {
		chkmin(Min, a[i]), chkmax(Max, a[i]);
		while (pa + 1 <= r && a[pa + 1] < Max) {pa++; cnt[pa + rmq :: queryMin(mid + 1, pa)]++; }
		while (pb <= r && rmq :: queryMin(i, pb) == Min) {cnt[pb + rmq :: queryMin(mid + 1, pb)]--; pb++;}
		if (pb <= pa) ans += cnt[Max + i];
	}
	if (pb <= pa) {
		for (int i = pb; i <= pa; i++)
			cnt[i + rmq :: queryMin(mid + 1, i)]--;
	} else {
		for (int i = pa + 1; i <= pb - 1; i++)
			cnt[i + rmq :: queryMin(mid + 1, i)]++;
	}
	// l Min, r Max
	pa = mid, pb = mid + 1;
	for (int i = mid, Min = a[i], Max = a[i]; i >= l; i--) {
		chkmin(Min, a[i]), chkmax(Max, a[i]);
		while (pa + 1 <= r && a[pa + 1] > Min) {pa++; cnt[n + pa - rmq :: queryMax(mid + 1, pa)]++; }
		while (pb <= r && rmq :: queryMax(i, pb) == Max) {cnt[n + pb - rmq :: queryMax(mid + 1, pb)]--; pb++;}
		if (pb <= pa) ans += cnt[n + i - Min];
	}
	if (pb <= pa) {
		for (int i = pb; i <= pa; i++)
			cnt[n + i - rmq :: queryMax(mid + 1, i)]--;
	} else {
		for (int i = pa + 1; i <= pb - 1; i++)
			cnt[n + i - rmq :: queryMax(mid + 1, i)]++;
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		int x, y; read(x), read(y);
		a[x] = y;
	}
	rmq :: init(a, n);
	ans = n, solve(1, n);
	cout << ans << endl;
	return 0;
}