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

const int MaxN = 101234;
int n, m, K, a[MaxN], b[MaxN];

int main() {
	int i;
	cin >> n >> K >> m;
	for(i = 1; i <= n; i++) {
		a[i] = read();
		b[a[i] % m]++;
	}
	
	int ans = 0, j;
	for(i = 0; i < m; i++) {
		if(b[i] >= K) {
			ans = 1; j = i; 
			break;
		}
	}
	if(ans) {
		puts("Yes");
		for(i = 1; i <= n; i++) {
			if(a[i] % m == j) {
				printf("%d ", a[i]);
				if(!--K) break;
			}
		}
	} else puts("No");
	return 0;
}