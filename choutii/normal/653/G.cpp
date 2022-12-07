#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

const int MaxN = 301234, Logn = 20, P = 1e9 + 7;

int n, a[MaxN], c[MaxN][Logn], cs[MaxN], fac[MaxN], rfac[MaxN];

int exp(int a, int n) {
	int res = 1;
	for (; n; n >>= 1) {
		if(n & 1)
			res = (LL) res * a % P;
		a = (LL) a * a % P;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1, t; t = a[i], i <= n; i++) {
		for (int d = 2; d * d <= a[i]; d++) {
			int p = 0; while(!(t % d)) t /= d, ++p; c[d][p]++;
		}
		if(t > 1) c[t][1]++;
	}
	
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = (LL) fac[i - 1] * i % P;
	rfac[n] = exp(fac[n], P - 2);
	for (int i = n; i; i--)
		rfac[i - 1] = (LL) rfac[i] * i % P;
	for (int i = 0; i <= n; i++) {
		cs[i] = (LL) fac[n] * rfac[i] % P * rfac[n - i] % P;
	}
	for (int i = 1; i <= n; i++) (cs[i] += cs[i - 1]) %= P;
	for (int i = 1; i <= n; i++) (cs[i] += cs[i - 1]) %= P;

	int ans = 0; 
	for (int i = 1; i < MaxN; i++) {
		int ok = 0;
		for (int k = 1; k < Logn; k++)
			ok |= c[i][k];
		if(!ok) continue;
		int m = n;
		for (int k = 1; k < Logn; k++)
			m -= c[i][k];
		for (int k = 1; k < Logn; k++) {
			if(!c[i][k]) continue;
			int l = m; m += c[i][k]; 
			int r = m - 1; 
			int x = (cs[r] - (l ? cs[l - 1] : 0) + P) % P;
			x = (x - (LL) c[i][k] * exp(2, n - 1) % P + P) % P; 
			ans = (ans + (LL)k * x) % P;
		}
	}
	cout << ans << endl;
	return 0;
}