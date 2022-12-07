#include <bits/stdc++.h>

#define L first.first
#define R first.second
#define X second

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 101234;
int n, m, seed, vmax, a[MaxN];
int rnd() {
	int ret = seed; seed = (seed * 7ll + 13) % (int) (1e9 + 7);
	return ret;
}

typedef pair<pair<int, int>, LL> PiiL;
set<PiiL> s;

#define make_tuple(x, y, z) make_pair(make_pair(x, y), z)

void append(int x, int y, LL z) {
	s.insert(make_tuple(x, y, z));
}

void cut(int x) {
	set <PiiL> :: iterator it = prev(s.upper_bound(make_tuple(x, n + 3, -1))); 
	if(it -> L == x) return; 
	PiiL It = *it; s.erase(it); 
	append(It.L, x, It.X);
	append(x, It.R, It.X);
}

vector<PiiL> buf;
void extract(int l, int r) {
	cut(l); cut(r); buf.clear();
	for(auto it = s.lower_bound(make_tuple(l, -1, -1)); it != s.end() && it -> R <= r; it++)
		buf.push_back(*it);
}

void add(int x) {
	for(auto it : buf) 
		s.erase(it), 
		append(it.L, it.R, it.X + x);
}

void cover(int l, int r, int x) {
	for(auto it : buf) s.erase(it);
	append(l, r + 1, x);	
}

LL kth(int K) {
	sort(buf.begin(), buf.end(), [&] (PiiL a, PiiL b) {return a.X < b.X;});
	for(auto it : buf) 
		if(K < it.R - it.L) 
			return it.X; 
		else
			K -= it.R - it.L;
}

int exp(LL a, int n, int P) {
	int res = 1;
	for(a %= P; n; n >>= 1) {
		if(n & 1)
			res = (LL) res * a % P;
		a = (LL) a * a % P;
	}
	return res;
}
int query(int x, int y) {
	int ans = 0;
	for(auto it : buf) 
		(ans += (LL) exp(it.X, x, y) * (it.R - it.L) % y) %= y;
	return (ans % y + y) % y;
}

int main() {
	int i;
	n = read(); m = read(); seed = read(); vmax = read();
	for(i = 1; i <= n; i++) append(i, i + 1, rnd() % vmax + 1);
	for(i = 1; i <= m; i++) {
		int op, l, r, x, y;
		op = rnd() % 4 + 1; l = rnd() % n + 1; r = rnd() % n + 1; if(l > r) swap(l, r);
		if(op == 3) 
			x = rnd() % (r - l + 1) + 1;
		else
			x = rnd() % vmax + 1;
		if(op == 4) y = rnd() % vmax + 1;
		extract(l, r + 1);
		if(op == 1) add(x);
		if(op == 2) cover(l, r, x);
		if(op == 3) printf("%lld\n", kth(x - 1));
		if(op == 4) printf("%d\n", query(x, y));
	}
	return 0;
}