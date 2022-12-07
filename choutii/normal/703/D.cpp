#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 1000000;

int n, a[MaxN + 5], x[MaxN + 5], l[MaxN + 5], ans[MaxN + 5]; map<int, int> pre;

int bit[MaxN + 5]; vector <int> t[MaxN + 5];

void add(int p, int d) {
	for (; p <= n; p += p & -p)
		bit[p] ^= d;
}

int sum(int p) {
	int ans = 0;
	for (; p; p -= p & -p)
		ans ^= bit[p];
	return ans;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		x[i] = x[i - 1] ^ (a[i] = read());
	int q = read();
	for (int i = 1; i <= q; i++) {
		l[i] = read();
		t[read()].pb(i);
	}
	for (int i = 1; i <= n; i++) {
		add(i, a[i]);
		if(pre[a[i]]) add(pre[a[i]], a[i]);
		pre[a[i]] = i;
		for (auto j : t[i])
			ans[j] ^= sum(i) ^ sum(l[j] - 1) ^ x[i] ^ x[l[j] - 1];
	}
	
	for (int i = 1; i <= q; i++)
		printf("%d\n", ans[i]);
	return 0;
}