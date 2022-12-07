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

const int MaxN = 2333, MaxM = 501234;

bitset<MaxN> g[MaxN], f[MaxN];

int n, m, a[MaxM], b[MaxM];
int main() {
	int i, j;
	n = read(); m = read();
	for(i = 1; i <= m; i++) a[i] = read(), b[i] = read(), f[a[i]].set(b[i]);
	for(i = 1; i <= n; i++) g[i].set(i);
	for(i = 1; i <= n; i++) {
		for(j = i; j <= n; j++)
			if(f[j][i]) break;
		swap(f[i], f[j]); swap(g[i], g[j]);
		for(j = 1; j <= n; j++) {
			if(f[j][i] && i != j) {
				f[j] ^= f[i], g[j] ^= g[i];
			}
		}
	}
	for(i = 1; i <= m; i++)
		if(!g[b[i]][a[i]]) 
			puts("YES");
		else 
			puts("NO");
	return 0;
}