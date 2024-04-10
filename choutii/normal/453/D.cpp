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

const int MaxN = 1 << 21;
int m; LL t, P, e0[MaxN], e1[MaxN], b[21];

inline LL mul(LL x,LL y){
    LL tmp=(x*y-(LL)((long double)x/P*y+1.0e-8)*P);
    return tmp<0?tmp+P:tmp;
}

LL exp(LL a, LL b) {
	LL res = 1; 
	for (; b; b >>= 1) {
		if(b & 1)
			res = mul(res, a);
		a = mul(a, a);
	}
	return res;
}

void dft(int n, LL *x) {
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j += (i << 1)) 
			for (int k = 0; k < i; k++) {
				LL u = x[j + k], v = x[j + k + i];
				x[j + k] = (u + v) % P;
				x[j + k + i] = (u - v) % P;
			}
	}
}

int main() {
	cin >> m >> t >> P; P <<= m;
	for (int i = 0; i < (1 << m); i++)
		e0[i] = (LL) read() % P;
	for (int i = 0; i <= m; i++)
		b[i] = (LL) read() % P;
	for (int i = 0; i < (1 << m); i++)
		e1[i] = b[__builtin_popcount(i)];
	dft(1 << m, e0); dft(1 << m, e1);
	for (int i = 0; i < (1 << m); i++)
		e0[i] = mul(e0[i], exp(e1[i], t));
	dft(1 << m, e0);
	for (int i = 0; i < (1 << m); i++) {
		e0[i] = (e0[i] + P) % P;
		printf("%lld\n", e0[i] >> m);
	}
	return 0;
}