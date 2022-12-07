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

const int P = 1e9 + 7;

int K, p, q, f[2333][2333];

int exp(int a, int n) {
	int res = 1;
	for(; n; n >>= 1) {
		if(n & 1) {
			res = (LL) res * a % P;
		}
		a = (LL) a * a % P;
	}
	return res;
}

int main() {
	int i, j;
	cin >> K >> p >> q; 
	int ans = 0;
	for(i = 0; i < 2333; i++)
		f[K][i] = (K + i + (LL) p * exp(q, P - 2) % P) % P;
	int up = p + q; 
	p = (LL) p * exp(up, P - 2) % P;
	q = (LL) q * exp(up, P - 2) % P;
	for(i = K - 1; ~i; i--) {
		for(j = K - 1; ~j; j--) {
			f[i][j] = (LL) f[i + 1][j] * p % P;
			f[i][j] = (f[i][j] + (LL) q * (i + j >= K ? i + j : f[i][i + j]) % P) % P;	
		}
	}
	cout << f[1][0] << endl;
	return 0;
}