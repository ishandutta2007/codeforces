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

const int MaxN = 2333; 
int n, a[MaxN];
int main() {
	int i, j, k;
	n = read();
	int chk = 0;
	for(i = 1; i <= n; i++)
		if((a[i] = read()) == 1) 
			chk++;
	if(chk) return printf("%d\n", n - chk), 0;
	chk = 1e6;
	for(i = 1; i <= n; i++)
		for(j = i, k = a[i]; j <= n; j++) 
			if((k = __gcd(k, a[j])) == 1)
				cmin(chk, n - 1 + j - i);
	return printf("%d\n", chk >= 1e6 ? -1 : chk), 0;
}