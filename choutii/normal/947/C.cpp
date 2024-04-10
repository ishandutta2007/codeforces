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

const int MaxN = 301234, Logn = 30;

int n, x[MaxN], p[MaxN];

int ch[MaxN * Logn][2], cnt[MaxN * Logn], segn = 1, rt = 1;

void add(int &p, int x, int d) {
	if(!p) p = ++segn;
	++cnt[p]; if(!d) return;
	add(ch[p][x >> d - 1 & 1], x, d - 1);
}

int query(int &p, int x, int d) {
	--cnt[p]; if(!d) return 0;
	if(cnt[ch[p][x >> d - 1 & 1]])
		return query(ch[p][x >> d - 1 & 1], x, d - 1);
	else
		return query(ch[p][(x >> d - 1 & 1) ^ 1], x, d - 1) ^ (1 << d - 1);
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++) 
		x[i] = read();
	for (int i = 1; i <= n; i++)
		add(rt, p[i] = read(), 30);
	for (int i = 1; i <= n; i++) {
		int ans = query(rt, x[i], 30);
		printf("%d\n", ans);
	}
	
	return 0;
}