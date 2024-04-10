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

const int MaxN = 48, MaxM = 1 << (MaxN / 2);

int n, m, F[MaxN];
int find(int x) {
	return F[x] == x ? x : F[x] = find(F[x]);
}

char c[MaxN][MaxN]; int sz[MaxN], b[MaxM], h[MaxM], g[MaxM], f[MaxM];

int main() {
	int i, j, k;
	n = read();
	for(i = 0; i < n; i++) F[i] = i;
	for(i = 0; i < n; i++) {
		scanf("%s", c[i]);
		for(j = 0; j < i; j++)
			if(c[i][j] == 'A') 	
				F[find(i)] = find(j);
 	}
 	for(i = 0; i < n; i++) sz[find(i)]++;
 	for(i = 0; i < n; i++)
 		if(find(i) == i && sz[i] > 1) 	
 			h[i] = 1 << m, m++;
 	for(i = 0; i < n; i++)
 		for(j = 0; j < i; j++) if(c[i][j] == 'X'){
 			int x = find(i), y = find(j);
			if(x == y) return puts("-1"), 0;
			if(h[x] && h[y])
				f[h[x] | h[y]] = 1;
		}
 	if(!m) return printf("%d\n", n - 1), 0;
	for(i = 0; i < (1 << m); i++) 
		for(j = 0; j < m; j++)
			if(i >> j & 1)
				f[i] |= f[i ^ (1 << j)];
	for(i = 0; i < (1 << m); i++) {
		b[i] = b[i >> 1] + (i & 1);
		f[i] = !f[i]; g[i] = 1;
	}			
	for(j = 0; j < m; j++)
		for(i = 0; i < (1 << m); i++) 
			if(i >> j & 1)
				f[i] += f[i ^ (1 << j)];
	for(i = 1; i <= m; i++) {
		int t = 0;
		for(j = 0; j < (1 << m); j++) {
			g[j] = g[j] * f[j];
			(m - b[j] & 1) ? t -= g[j] : t += g[j];
		}
		if(t) return printf("%d\n", n + i - 1), 0;
	}
	return 0;
}