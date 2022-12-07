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

const int MaxK = 13, MaxN = 101234;
int n, q, K, a[MaxK][MaxN]; bitset<1 << 12> h[MaxN];
int main() {
	int i, j;
	n = read(); K = read(); q = read();
	for(i = 0; i < K; i++) {
		for(j = 0; j < n; j++) 
			a[i][j] = read(); 
		for(j = 0; j < (1 << 12); j++) h[i][j] = j >> i & 1;
	}
	int c = K;
	while(q--) {
		int op = read(), x = read() - 1 , y = read() - 1;
		if(op == 1)	h[c++] = h[x] | h[y];
		if(op == 2)  h[c++] = h[x] & h[y];
		if(op == 3) {
			vector<pair<int, int> > v;
			for(i = 0; i < K; i++)
				v.push_back(make_pair(a[i][y], i));
			sort(v.begin(), v.end());
			int mask = 0;
			for(i = K - 1; ~i; i--) {
				mask |= (1 << v[i].sec);
				if(h[x][mask]) {
					printf("%d\n", v[i].fir);
					break;
				}
			}
		} 
	}
	return 0;
}