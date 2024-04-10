#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXV = 1e7 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int tot, prime[MAXV], f[MAXV], miu[MAXV];
void sieve(int n) {
	miu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i, miu[i] = -1;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
			if (prime[j] == f[i]) miu[tmp] = 0;
			else miu[tmp] = -miu[i];
		}
	}
}
int func(int x) {
	int ans = 1;
	while (x != 1) {
		int tmp = f[x]; ans *= f[x];
		while (x % tmp == 0) x /= tmp;
	}
	return ans;
}
int n, k, a[MAXN], b[MAXN], home[MAXN], cnt[MAXV];
bool iskey[MAXN];
vector <int> d[MAXV];
void work(int x) {
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= x; i++)
		if (!iskey[i]) {
			for (auto x : d[a[i]])
				cnt[x]++;
		}
	for (int i = 1; i <= x; i++)
		if (!iskey[i]) {
			b[i] = 0;
			for (auto x : d[a[i]])
				b[i] += miu[x] * cnt[x];
		}
}
int main() {
	read(n), read(k), sieve(1e7);
	for (int i = 1; i <= n; i++) {
		read(a[i]), home[i] = i, a[i] = func(a[i]);
		d[a[i]].clear();
		for (int j = 1; j * j <= a[i]; j++)
			if (a[i] % j == 0) {
				cnt[j]++, d[a[i]].push_back(j);
				if (j * j != a[i]) cnt[a[i] / j]++, d[a[i]].push_back(a[i] / j);
			}
	}
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		for (auto x : d[a[i]])
			b[i] += miu[x] * cnt[x];
		if (b[i] >= 2) pos = i;
	}
	if (pos == 0) {
		set <int> s;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			b[i] = 0;
			for (auto x : d[a[i]])
				b[i] += miu[x] * cnt[x];
			if (b[i] == 0 && s.size() < k) {
				s.insert(i);
				for (auto x : d[a[i]])
					cnt[x]++;
			}
		}
		for (auto x : s)
			printf("%d ", x);
		return 0;
	}
	vector <int> key;
	key.push_back(pos), iskey[pos] = true;
	for (int i = 1; i <= n; i++)
		if (__gcd(a[i], a[pos]) == 1 && key.size() < 3) key.push_back(i), iskey[i] = true;
	work(n);
	int zeros = 0;
	for (int i = 1; i <= n; i++)
		if (!iskey[i] && b[i] == 0) zeros++;
	if (zeros >= k) {
		for (int i = 1; i <= n; i++)
			if (!iskey[i] && b[i] == 0 && k != 0) {
				printf("%d ", i);
				k--;
			}
	} else {
		int l = 0, r = n;
		while (l < r) {
			int mid = (l + r) / 2;
			int cnt = 3; work(mid);
			for (int i = 1; i <= mid; i++)
				if (!iskey[i] && b[i] != 0) cnt++;
			if (cnt >= k) r = mid;
			else l = mid + 1;
		}
		set <int> s; work(l);
		for (auto x : key)
			s.insert(x);
		for (int i = 1; i <= l; i++)
			if (!iskey[i] && b[i] != 0) s.insert(i);
		if (s.size() == k) {
			for (auto x : s)
				printf("%d ", x);
		} else {
			set <int> t; work(l - 1);
			for (auto x : key)
				t.insert(x);
			for (int i = 1; i <= l - 1; i++)
				if (!iskey[i] && b[i] != 0) t.insert(i);
			t.insert(l);
			bool flg = false;
			for (int i = 1; i <= l - 1 && (!flg || t.size() < k); i++)
				if (__gcd(a[l], a[i]) == 1) t.insert(i), flg = true;
			if (t.size() > k) t.erase(key.back());
			for (auto x : t)
				printf("%d ", x);
		}
	}
	return 0;
}