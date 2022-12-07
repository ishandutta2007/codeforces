#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234, B = 5000, MaxM = 101234;
int n, q, a[MaxN], bel[MaxN], le[MaxN], ri[MaxN];

deque<int> val[MaxN / B + 5]; int hav[MaxN / B + 5][MaxM];

void shift(int l, int r) {
	int a = l / B, b = r / B; l %= B; r %= B;
	int t = val[b][r];
	val[a].insert(val[a].begin() + l, t); ++hav[a][t];
	if(a == b) ++r;
	val[b].erase(val[b].begin() + r); --hav[b][t];
	for (int i = a; i < b; i++) {
		int t = val[i].back();
		--hav[i][t]; ++hav[i + 1][t]; 
		val[i + 1].push_front(t);
		val[i].pop_back();
	}
}

int sum(int r, int x) {
	int p = r / B, ans = 0; r %= B;
	for (int i = 0; i <= r; i++)
		ans += (val[p][i] == x);
	return ans;
}

int query(int l, int r, int x) {
	int a = l / B, b = r / B, ans = 0;
	for (int i = a; i < b; i++)
		ans += hav[i][x];
	ans += sum(r, x);
	if(l % B)
		ans -= sum(l - 1, x);
	return ans;
}

int main() {
	n = read();
	for (int i = 0; i < n; i++) {
		a[i] = read();
		val[i / B].push_back(a[i]);
		hav[i / B][a[i]]++;
	}
	
	q = read(); int last = 0;
	while(q--) {
		int op = read(), l = read(), r = read();
		l = (l + last - 1) % n;
		r = (r + last - 1) % n;
		if(l > r) swap(l, r);
		if(op == 1) 
			shift(l, r); 
		else {
			int k = (read() + last - 1) % n + 1;
			printf("%d\n", last = query(l, r, k)); 
		}
	}
	return 0;
}