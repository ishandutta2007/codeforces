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

int n, K, ans[MaxN];

void merge_sort(int l, int r, int x, int y) {
	if(K && l < r) {
		int mid = l + r + 1 >> 1;
		K -= 2;
		merge_sort(l, mid - 1, y - (mid - l - 1), y);
		merge_sort(mid, r, x, x + r - mid);
	}else
		for(int i = l; i <= r; i++)
			ans[i] = x + (i - l);
}

#define gg return puts("-1"), 0;
int main() {
	int i;
	cin >> n >> K;
	if(K > n * 2) gg;
	if(~K & 1) gg;
	--K; merge_sort(1, n, 1, n);
	for(i = 1; i <= n; i++) printf("%d ", ans[i]);  
	return 0;
}