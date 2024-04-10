#include <bits/stdc++.h>

#define fi first
#define se second
#define MP make_pair
#define PB push_back

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

const int MaxN = 101234;

char s[MaxN]; int n;
bitset<MaxN> f[26], o;

int main() {
	scanf("%s", s); n = strlen(s);
	for (int i = 0; i < n; i++) f[s[i] - 'a'].set(i), o.set(i);
	for (int q = read(); q--; ) {
		int op = read(), x = read();
		if(op == 1) {
			char c[5]; scanf("%s", c);
			for (int i = 0; i < 26; i++)
				f[i][x - 1] = 0;
			f[*c - 'a'].set(x - 1); 
		}else {
			char c[MaxN]; int r;
			scanf("%d%s", &r, c); int l = strlen(c);
			bitset<MaxN> bs = (o >> (n - r + x + l - 2)) << (x - 1);
			for (int i = 0; i < l; bs <<= 1,  i++) bs &= f[c[i] - 'a'];
			printf("%d\n", bs.count()); 
		}
	}
	return 0;
}