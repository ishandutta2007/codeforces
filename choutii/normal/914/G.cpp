#include <bits/stdc++.h>

#define fi first
#define se second
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 1 << 17, MaxM = 1001234, P = 1e9 + 7;

int n, u, a[MaxN], b[MaxN], c[MaxN], d[MaxN], fib[MaxN];
 

void xor_conv(int x[], int z[]) {
	for (int i = 0; i < u; i++) z[i] = x[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < u; j++) 
			if(j >> i & 1){
				int l = z[j ^ (1 << i)], r = z[j];
				z[j] = (l - r + P) % P;
				z[j ^ (1 << i)] = (l + r) % P;
			}
	for (int i = 0; i < u; i++) z[i] = (LL) z[i] * z[i] % P;
	int inv = P + 1 >> 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < u; j++) 
			if(j >> i & 1){
				int l = z[j ^ (1 << i)], r = z[j];
				z[j] = (LL) (l - r + P) * inv % P;
				z[j ^ (1 << i)] = (LL) (l + r) * inv % P;
			} 
}

int t[MaxN];
void fmt(int x[]) {
	for (int i = 0; i < u; i++) 
		t[i] = x[u - 1 ^ i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < u; j++)
			if(j >> i & 1) t[j] = (t[j] + t[j ^ (1 << i)]) % P;
	for (int i = 0; i < u; i++) x[i] = t[i];
}

void ifmt(int x[]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < u; j++)
			if(j >> i & 1) x[j] = (x[j] - x[j ^ (1 << i)] + P) % P;
}

void and_conv(int x[], int y[], int z[], int w[]) {
	fmt(x); fmt(y); fmt(z);
	for (int i = 0; i < u; i++) 
		w[i] = (LL) x[i] * y[i] % P * z[i] % P;
	ifmt(w);	
}

int main() {
	n = read();
	fib[0] = 0; fib[1] = 1;
	for (int i = 2; i < MaxN; i++) 
		fib[i] = (fib[i - 1] + fib[i - 2]) % P;
	for (int i = 1; i <= n; i++) 
		a[read()]++;
		
	n = 17; u = 1 << n;
	for (int i = 0; i < u; i++) {
		b[i] = (b[i] + (LL) a[0] * a[i]) % P;
		for (int j = i; j; j = j - 1 & i)
			b[i] = (b[i] + (LL) a[j] * a[i - j]) % P;
	} // b[i] = count(sa | sb = i) sa & sb = 0
	
	xor_conv(a, c); // c[i] = count(sa ^ sb = i)
	// a[] = itself
	
	for (int i = 0; i < u; i++) a[i] = (LL) a[i] * fib[i] % P, b[i] = (LL) b[i] * fib[i] % P, c[i] = (LL) c[i] * fib[i] % P;
	and_conv(a, b, c, d);
	int ans = 0; 
	for (int i = 1; i < u; i <<= 1) ans = (ans + d[i ^ u - 1]) % P;
	cout << ans << endl;
	return 0;
}