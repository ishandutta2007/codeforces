#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 301234;
const int MaxL = 20;
int n, q, a[MaxN], b[MaxN];
int cnt[MaxN * MaxL], rev[MaxL];

void append(int x) {
	b[x] = 1; int p = 1;
	for(int i = MaxL - 1; ~i; i--) 
		cnt[p = (p << 1 | (x >> i & 1))]++;
}
void query() {
	int p = 1, ans = 0;
	for(int i = MaxL - 1; ~i; i--) {
		if(cnt[p << 1 | rev[i]] == (1 << i))
			p = p << 1 | (rev[i] ^ 1), ans |= (1 << i);
		else 
			p = p << 1 | rev[i];
	}	
	printf("%d\n", ans);
}
int main() {
	int i;
	n = inp(); q = inp();
	for(i = 1; i <= n; i++) {
		a[i] = inp(); 
		if(b[a[i]]) continue;
		append(a[i]); 
	}
	
	while(q--) {
		int x = inp();
		for(i = 0; i < MaxL; i++) rev[i] ^= (x >> i & 1);
		query();
	}	
	return 0;
}