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

const int MaxN = 33;

LL n, L, c[MaxN], d[MaxN], s[MaxN];

int main() {
	int i, j; LL x = 0;
	cin >> n >> L;
	for(i = 1; i <= n; i++) cin >> c[i];
	for(i = n + 1; i <= 31; i++) c[i] = 1ll << 60;
	
	n = 31;
	for(i = 2; i <= n; i++) cmin(c[i], c[i - 1] + c[i - 1]);
	for(i = n - 1; i; i--) cmin(c[i], c[i + 1]); 
	for(i = 1; i < n; i++) {
		if(L >> (i - 1) & 1) {
			for(d[i] = c[i + 1], x = c[i], j = i - 1; j >= 0; j--) {
				cmin(d[i], d[j] + x);
				if(!j) break; if(L >> (j - 1) & 1) x += c[j];
			}
		}
		else d[i] = d[i - 1];
	}
	cout << d[n - 1];
	return 0;
}