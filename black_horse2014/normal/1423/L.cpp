#include <bits/stdc++.h>
using namespace std;

#define MX 1050
typedef unsigned long long ull;
ull hs[MX], hL[1 << 15], bs[50];

int main() {
//	freopen("1.in", "r", stdin);
//	freopen("1.out", "w", stdout);
	mt19937_64 rnd(time(0));
	srand(time(0));
	int n, s, d; scanf("%d%d%d", &n, &s, &d);
	for (int i = 0; i < MX; i++) hs[i] = rnd();
	random_shuffle(hs, hs + MX);
	for (int i = 0; i < s; i++) {
		int c; scanf("%d", &c);
		while (c--) {
			int k; scanf("%d", &k);
			bs[i] ^= hs[k];
		}
	}
	int mid = min(10, s / 2);
	for (int bits = 0; bits < (1 << mid); bits++) {
		for (int i = 0; i < mid; i++) {
			if (bits >> i & 1) {
				hL[bits] ^= bs[i];
			}
		}
	}
	unordered_map<ull, int> mp;
	mp[0] = 0;
	for (int bits = 0; bits < (1 << (s - mid)); bits++) {
		ull val = 0;
		for (int i = 0; i < s - mid; i++) {
			if (bits >> i & 1) {
				val ^= bs[i + mid];
			}
		}
		int cnt = __builtin_popcount(bits);
		if (!mp.count(val) || mp[val] > cnt) {
			mp[val] = cnt;
		}
	}
	while (d--) {
		int c; scanf("%d", &c);
		ull v = 0;
		while (c--) {
			int k; scanf("%d", &k);
			v ^= hs[k];
		}
		int res = INT_MAX;
		for (int bits = 0; bits < (1 << mid); bits++) {
			ull val = hL[bits] ^ v;
			if (mp.count(val)) res = min(res, mp[val] + __builtin_popcount(bits));
		}
		if (res == INT_MAX) puts("-1");
		else printf("%d\n", res);
	}
	return 0;
}