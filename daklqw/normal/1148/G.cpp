#include <bits/stdc++.h>

const int MAXN = 200010;
const int MAXS = 10000000;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int pri[MAXS / 10], npri[MAXS + 1], dvi[MAXS + 1], mu[MAXS + 1], tot;
void sieve() {
	mu[1] = 1;
	for (int i = 2; i <= MAXS; ++i) {
		if (!npri[i]) mu[dvi[pri[++tot] = i] = i] = -1;
		for (int j = 1, t; j <= tot && (t = i * pri[j]) <= MAXS; ++j) {
			npri[t] = true;
			dvi[t] = pri[j];
			if (i % pri[j] == 0) {
				mu[t] = 0;
				break;
			}
			mu[t] = -mu[i];
		}
	}
}
int A[MAXN];
int arr[MAXS];
typedef std::vector<int> VI;
VI fac[MAXN];
void add(int x, int v) {
	for (auto t : fac[x]) arr[t] += v;
}
int get(int x) {
	int res = 0;
	for (auto t : fac[x]) res += arr[t] * mu[t];
	return res;
}
int getf(VI & li, int mid) {
	for (int i = 0; i < mid; ++i) add(li[i], 1);
	int res = mid;
	for (int i = 0; i < mid; ++i) res -= !get(li[i]);
	for (int i = 0; i < mid; ++i) add(li[i], -1);
	return res;
}
VI solve(VI & li, int K) {
	const int n = li.size();
	VI ansl;
	if (n - getf(li, n) >= K + 3) {
		for (int i = 0; i < n; ++i) add(li[i], 1);
		for (int i = 0, tc = K + 3; i < n && tc; ++i) if (!get(li[i]))
			ansl.push_back(li[i]), --tc;
		for (int i = 0; i < n; ++i) add(li[i], -1);
	} else {
		int l = 1, r = n, ans = 0;
		while (l <= r) {
			int mid = l + r >> 1;
			if (getf(li, mid) >= K) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		std::set<int> S;
		int rest = ans, dx = getf(li, ans) - getf(li, ans - 1);
		for (int i = 0; i < ans; ++i) add(li[i], 1);
		for (int i = 0; i < ans; ++i) if (!get(li[i]))
			S.insert(li[i]), --rest;
		for (int i = 0; i + 1 < ans && rest > K && dx > 1; ++i)
			if (!S.count(li[i]) && get(li[i]) == 1)
				if (gcd(A[li[ans - 1]], A[li[i]]) == 1)
					S.insert(li[i]), --dx, --rest;
		for (int i = 0; i < ans; ++i) if (!S.count(li[i]))
			ansl.push_back(li[i]);
		for (int i = 0; i < ans; ++i) add(li[i], -1);
	}
	return ansl;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	sieve();
	int n, K; std::cin >> n >> K;
	std::set<int> S;
	for (int i = 1, t; i <= n; ++i) {
		std::cin >> t; A[i] = 1;
		while (t != 1) S.insert(dvi[t]), t /= dvi[t];
		const int U = 1 << S.size();
		for (auto t : S) A[i] *= t;
		for (int j = 0; j != U; ++j) {
			int now = 1, k = 0;
			for (auto t : S) if (j >> k++ & 1) now *= t;
			fac[i].push_back(now);
		}
		S.clear();
	}
	for (int i = 1; i <= n; ++i) add(i, 1);
	int rt = -1, dx = -1, dy = -1;
	for (int i = 1; i <= n; ++i) if (get(i) >= 2) {
		rt = i;
		for (int j = 1; j <= n; ++j)
			if (j != i && gcd(A[j], A[i]) == 1) {
				if (dx == -1) dx = j;
				else { dy = j; break; }
			}
		break;
	}
	for (int i = 1; i <= n; ++i) add(i, -1);
	VI ansl;
	if (rt == -1) {
		for (int i = 1, tc = K; i <= n && tc; ++i)
			if (get(i) == 0)
				ansl.push_back(i), add(i, 1), --tc;
	} else {
		VI li;
		for (int i = 1; i <= n; ++i)
			if (i != rt && i != dx && i != dy)
				li.push_back(i);
		ansl = solve(li, K - 3);
		if (ansl.size() < K) {
			ansl.push_back(rt);
			ansl.push_back(dx);
			if (ansl.size() < K)
				ansl.push_back(dy);
		}
	}
	assert(ansl.size() == K);
	for (auto t : ansl) std::cout << t << ' ', add(t, 1);
	std::cout << '\n';
	bool fa = true, fb = true;
	for (auto t : ansl) {
		int x = get(t);
		fa &= x > 0, fb &= x == 0;
	}
	std::cerr << "DD " << fa << ' ' << fb << std::endl;
	assert(fa || fb);
	return 0;
}