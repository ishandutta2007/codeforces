#include <bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;
typedef unsigned long long u64;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

int n, a[233], f[233][233][2];

int main() {
	int i, j;
	cin >> n;
	for(i = 1; i <= n; i++) cin >> a[i];
	for(i = 1; i <= n; i++) f[i][i][1] = (a[i] & 1);
	
	for(int L = 2; L <= n; L++) {
		for(int l = 1; l <= n; l++) {
			int r = l + L - 1;
			if((a[l] & 1) && (a[r] & 1)) {
				f[l][r][1] = (r - l + 1) & 1;
				for(i = l; i <= r; i++) {
					f[l][r][1] |= (f[l][i][0] && f[i + 1][r][1]); 
					f[l][r][1] |= (f[l][i][1] && f[i + 1][r][0]);
					f[l][r][0] |= (f[l][i][0] && f[i + 1][r][0]);
					f[l][r][0] |= (f[l][i][1] && f[i + 1][r][1]); 
				}
			}
		}
	}
	if(f[1][n][1]) puts("Yes");
	else puts("No");
	return 0;
}