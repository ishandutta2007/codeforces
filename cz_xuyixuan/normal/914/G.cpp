#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MAXS = 2 << 17;
const int P = 1e9 + 7;
const int inv = 5e8 + 4;
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
int cnt[MAXS], bits[MAXS];
int resor[MAXS], resxor[MAXS], res[MAXS];
int f[MAXN][MAXS], seq[MAXS];
void FWTXOR(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++) {
		int tmp = a[i], tnp = a[j];
		a[i] = (tmp + tnp) % P;
		a[j] = (tmp - tnp + P) % P;
	}
}
void UFWTXOR(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++) {
		int tmp = a[i], tnp = a[j];
		a[i] = 1ll * (tmp + tnp) * inv % P;
		a[j] = 1ll * (tmp - tnp + P) * inv % P;
	}
}
void FWTOR(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[j] = (a[i] + a[j]) % P;
}
void UFWTOR(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[j] = (a[j] - a[i] + P) % P;
}
void FWTAND(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[i] = (a[i] + a[j]) % P;
}
void UFWTAND(int *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[i] = (a[i] - a[j] + P) % P;
}
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		cnt[x]++;
	}
	memcpy(resxor, cnt, sizeof(cnt));
	FWTXOR(resxor, MAXS);
	for (int s = 0; s < MAXS; s++)
		resxor[s] = 1ll * resxor[s] * resxor[s] % P;
	UFWTXOR(resxor, MAXS);
	for (int s = 0; s < MAXS; s++) {
		int tmp = s;
		while (tmp != 0) {
			if (tmp & 1) bits[s]++;
			tmp >>= 1;
		}
		f[bits[s]][s] = cnt[s];
	}
	for (int i = 0; i <= 17; i++)
		FWTOR(f[i], MAXS);
	for (int i = 0; i <= 17; i++) {
		static int tmp[MAXS];
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j <= i; j++)
		for (int s = 0; s < MAXS; s++)
			tmp[s] = (tmp[s] + 1ll * f[j][s] * f[i - j][s]) % P;
		UFWTOR(tmp, MAXS);
		for (int s = 0; s < MAXS; s++)
			if (bits[s] == i) resor[s] = tmp[s];
	}
	seq[1] = 1;
	for (int i = 2; i < MAXS; i++)
		seq[i] = (seq[i - 2] + seq[i - 1]) % P;
	for (int i = 0; i < MAXS; i++) {
		resxor[i] = 1ll * resxor[i] * seq[i] % P;
		resor[i] = 1ll * resor[i] * seq[i] % P;
		cnt[i] = 1ll * cnt[i] * seq[i] % P;
	}
	FWTAND(resxor, MAXS);
	FWTAND(resor, MAXS);
	FWTAND(cnt, MAXS);
	for (int s = 0; s < MAXS; s++)
		res[s] = 1ll * resxor[s] * resor[s] % P * cnt[s] % P;
	UFWTAND(res, MAXS);
	int ans = 0;
	for (int s = 0; s < MAXS; s++)
		if (bits[s] == 1) ans = (ans + res[s]) % P;
	writeln(ans);
	return 0;
}