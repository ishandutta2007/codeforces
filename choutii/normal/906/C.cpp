#include <bits/stdc++.h>

#define fir first
#define sec second
#define MP make_pair
#define PB push_back

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

const int MaxN = 23, MaxU = (1 << 22);
int n, m, adj[MaxN], f[MaxU], p[MaxU], q[MaxU];
 
void print(int mask) {
	if(!mask) return;
	print(p[mask]);
	if(f[mask])
		printf("%d ", q[mask] + 1);
} 
int main() {
	int i, j, k;
	n = read(); m = read();
	for(i = 1; i <= m; i++) {
		int u = read() - 1, v = read() - 1;
		adj[u] |= (1 << v);
		adj[v] |= (1 << u);
	}
	for(i = 0; i < n; i++) adj[i] |= (1 << i);
	int up = (1 << n);
	for(i = 0; i < up; i++) {
		for(j = 0; j < n; j++)
			if((i >> j & 1) && (i & adj[j]) != i) 
				break;
		if(j < n) f[i] = 233;
	}	
	for(i = 1; i < up; i++)
		for(j = 0; j < n; j++)
			if(i >> j & 1)
				if(cmin(f[k = (i | adj[j])], f[i] + 1))
					 p[k] = i, q[k] = j;
	printf("%d\n", f[up - 1]);
	print(up - 1);
	return 0;
}