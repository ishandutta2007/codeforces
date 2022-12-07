#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 201234, P = 1e9 + 7;

int n, K, ans, fac[MaxN], rfac[MaxN];

int exp(int a, int n) {
	int res = 1;
	for (; n; n >>= 1) {
		if(n & 1)
			res = (LL) res * a % P;
		a = (LL) a * a % P;
	}
	return res;
}

int s(int n, int m) {
	int ans = 0, s = 1;
	for (int k = 0; k <= m; k++) {
		ans = (ans + (LL) s * exp(m - k, n) % P * rfac[k] % P * rfac[m - k]) % P;
		s = (P - s) % P; 
	}
	return ans;
}

int main() {
	n = read(); K = read(); 
	for (int i = 1; i <= n; i++)
		(ans += read()) %= P;
		
	int j = 1;
	for (int i = 2; i <= K; i++) j = (LL) j * i % P;
	rfac[K] = exp(j, P - 2);
	for (int i = K; i; i--) rfac[i - 1] = (LL) rfac[i] * i % P;
	
	ans = (LL) ans * (s(n, K) + (LL) (n - 1) * s(n - 1, K) % P) % P;
	cout << ans << endl;
	return 0;
}