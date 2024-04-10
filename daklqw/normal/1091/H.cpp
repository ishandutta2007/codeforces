#include <bits/stdc++.h>

const int MAXN = 200010;
const int MAXS = 200000;
int pri[MAXN], frac[MAXN], tot, npri[MAXN];
int sg[MAXN], F;
typedef std::bitset<MAXN> B;
B hav[110], can;
void sieve() {
	for (int i = 2; i <= MAXS; ++i) {
		if (!npri[i]) frac[pri[++tot] = i] = 1;
		for (int j = 1, t; j <= tot && (t = i * pri[j]) <= MAXS; ++j) {
			npri[t] = true;
			frac[t] = frac[i] + 1;
			if (i % pri[j] == 0) break;
		}
	}
	frac[1] = frac[F] = 3;
	for (int i = 1; i <= MAXS; ++i)
		if (frac[i] <= 2) can.set(i);
	int ma = 0;
	for (int i = 1; i <= MAXS; ++i) {
		for (int j = 0; j <= ma + 1; ++j)
			if (!hav[j].test(i)) {
				ma = std::max(ma, sg[i] = j);
				break;
			}
		hav[sg[i]] |= can << i;
	}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n >> F;
	sieve();
	int gm = 0;
	for (int i = 1; i <= n; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		gm ^= sg[b - a];
		gm ^= sg[c - b];
	}
	if (gm) std::cout << "Alice\nBob\n";
	else std::cout << "Bob\nAlice\n";
	return 0;
}