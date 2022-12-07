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

LL n, K;
LL phi(LL n) {
	LL ans = n;
	for(LL i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			ans = ans / i * (i - 1);
			while(n % i == 0)
				n /= i;
		}
	}
	return n != 1 ? ans / n * (n - 1): ans;
}
int main() {
	cin >> n >> K;
	while(K > 0 && n != 1)
		n = phi(n), K -= 2;
	cout << n % (int) (1e9 + 7);
	return 0;
}