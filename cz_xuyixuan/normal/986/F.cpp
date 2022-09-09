#include<bits/stdc++.h>
using namespace std;
const int MAXQ = 55;
const int MAXLOG = 64;
const int MAXN = 100005;
const int MAXP = 2e6 + 5;
const int MAXV = 3.2e7 + 5;
const long long INF = 4e18;
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
int q; long long memk[MAXQ];
int tot, prime[MAXP], f[MAXV];
int cnt[MAXQ]; long long p[MAXQ][MAXLOG];
long long dist[MAXQ][MAXN];
struct info {long long dist; int home; };
bool operator < (info a, info b) {
	return a.dist > b.dist;
}
void exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return;
	}
	long long q = a / b, r = a % b;
	exgcd(b, r, y, x);
	y -= q * x;
}
int main() {
	for (int i = 2; i < MAXV; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp >= MAXV) break;
			f[tmp] = prime[j];
		}
	}
	int T; read(T);
	while (T--) {
		long long n, k;
		read(n), read(k);
		int pos = 0;
		for (int i = 1; i <= q; i++)
			if (memk[i] == k) pos = i;
		if (pos == 0) {
			pos = ++q;
			memk[q] = k;
			long long tmp = k;
			for (int i = 1; 1ll * prime[i] * prime[i] <= tmp; i++)
				if (tmp % prime[i] == 0) {
					p[pos][++cnt[pos]] = prime[i];
					while (tmp % prime[i] == 0) tmp /= prime[i];
				}
			if (tmp != 1) p[pos][++cnt[pos]] = tmp;
			if (cnt[pos] >= 3) {
				for (int i = 0; i < p[pos][1]; i++)
					dist[pos][i] = INF;
				static priority_queue <info> Heap;
				dist[pos][0] = 0; Heap.push((info) {0, 0});
				static bool vis[MAXN];
				memset(vis, false, sizeof(vis));
				while (!Heap.empty()) {
					while (!Heap.empty() && vis[Heap.top().home]) Heap.pop();
					if (Heap.empty()) break;
					info tmp = Heap.top(); Heap.pop();
					for (int i = 2; i <= cnt[pos]; i++) {
						int dest = (tmp.home + p[pos][i]) % p[pos][1];
						if (dist[pos][dest] > tmp.dist + p[pos][i]) {
							dist[pos][dest] = tmp.dist + p[pos][i];
							Heap.push((info) {dist[pos][dest], dest});
						}
					}
				}
			}
		}
		bool flg = false;
		for (int i = 1; i <= cnt[pos]; i++)
			if (n % p[pos][i] == 0) {
				printf("YES\n");
				flg = true;
				break;
			}
		if (flg) continue;
		if (cnt[pos] <= 1) {
			printf("NO\n");
			continue;
		}
		if (cnt[pos] == 2) {
			long long x = 0, y = 0;
			exgcd(p[pos][1], p[pos][2], x, y);
			y = (y % p[pos][1] + p[pos][1]) % p[pos][1];
			long long tmp = y * (n % p[pos][1]) % p[pos][1] * p[pos][2];
			if (tmp <= n) printf("YES\n");
			else printf("NO\n");
			continue;
		}
		int tmp = n % p[pos][1];
		if (dist[pos][tmp] <= n) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}