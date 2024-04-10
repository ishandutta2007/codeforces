#include <bits/stdc++.h>

#define fir first
#define sec second
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

const int MaxN = 51234, MaxK = 11;
int n, K;

struct info {
	int siz, l[MaxK], r[MaxK];
	bool operator < (const info & b) const {
		for(int i = 1; i <= K; i++)
			if(r[i] >= b.l[i]) return 0;
		return 1;
	} 
	void merge(const info & b) {
		siz += b.siz;
		for(int i = 1; i <= K; i++)
			cmin(l[i], b.l[i]), cmax(r[i], b.r[i]);
	}
};

set <info> s;
int main() {
	int i, j;
	n = read(); K = read();
	for(int i = 1; i <= n; i++) {
		info t; t.siz = 1;
		for(j = 1; j <= K; j++)
			t.l[j] = t.r[j] = read();
		auto x = s.lower_bound(t);
		auto y = s.upper_bound(t);
		while(x != y) {
			t.merge(*x);
			s.erase(x++);
		}
		s.insert(x, t);
		printf("%d\n", s.rbegin() -> siz);
	}
	return 0;
}