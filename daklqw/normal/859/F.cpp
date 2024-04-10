#include <bits/stdc++.h>

const int MAXN = 200010;
typedef long long LL;
int n, A[MAXN], B[MAXN], tar[MAXN];
LL C, up[MAXN];
LL preA[MAXN], preB[MAXN];
LL ans[MAXN];
LL kk[MAXN], kl[MAXN];
LL qv[MAXN * 5]; int qr[MAXN * 5];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> C;
	for (int i = 1; i <= n * 2 - 1; ++i)
		if (i & 1) std::cin >> A[i + 1 >> 1];
		else std::cin >> B[(i >> 1) + 1];
	for (int i = 1; i <= n; ++i) preA[i] = preA[i - 1] + A[i];
	for (int i = 2; i <= n; ++i) preB[i] = preB[i - 1] + B[i];
	for (int i = 1; i <= n; ++i) {
		if (C >= A[i]) {
			int l = i, r = n, ans = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (preB[mid] - preB[i] + preA[mid] - preA[i - 1] <= C)
					ans = mid, l = mid + 1;
				else r = mid - 1;
			}
			if (ans > i) tar[i] = ans;
			LL tc = C - (preB[ans] - preB[i] + preA[ans] - preA[i - 1]);
			if (ans < n && tc >= A[ans + 1])
				kk[i] = ans + 1, kl[i] = -B[i] - B[ans + 1] + tc - A[ans + 1];
		}
	}
	int head = 1, tail = 0;
	for (int i = 0; i <= n; ++i) {
		ans[i] = -preB[i];
		if (i) ans[i] = std::max(ans[i], ans[i - 1] - B[i]);
		while (head <= tail && qr[head] < i) ++head;
		if (head <= tail)
			ans[i] = std::max(ans[i], qv[head]);
		if (tar[i]) {
			LL tv = ans[i - 1] - B[i];
			while (head <= tail && qv[tail] < tv) --tail;
			++tail, qv[tail] = tv, qr[tail] = tar[i];
		}
		if (kk[i]) {
			LL tv = ans[i - 1] + kl[i];
			while (head <= tail && qv[tail] < tv) --tail;
			++tail, qv[tail] = tv, qr[tail] = kk[i];
		}
	}
	for (int i = 1; i <= n; ++i) ans[i] += preB[i];
	LL Ans = 0;
	for (int i = n; i; --i) Ans += (ans[i] -= ans[i - 1]) + std::min((LL) A[i], C);
	std::cout << Ans << std::endl;
	return 0;
}