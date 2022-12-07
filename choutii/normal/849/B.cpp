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

const int MaxN = 1234;
int n, y[MaxN], d[MaxN];

int main() {
	int i, j, k;
	cin >> n;
	for(i = 1; i <= n; i++) cin >> y[i];
	int ans = 0;
	for(i = 2; i <= n; i++) {
		for(j = 1;j <= n; j++)
			if((LL) (i - 1) * (y[j] - y[1]) == (LL) (j - 1) * (y[i] - y[1]))
				d[j] = 1;
			else 
				d[j] = 0;
		k = 0; bool ok = 1;
		for(j = 1; j <= n; j++) {
			if(d[j]) continue;
			if(!k) k = j;
			else if((LL) (i - 1) * (y[j] - y[k]) != (LL) (j - k) * (y[i] - y[1]))
				ok = 0;
		}
		if(ok && k) ans = 1;
	}
	
	reverse(y + 1, y + n + 1);
	for(i = 2; i <= n; i++) {
		memset(d, 0, sizeof(d));
		for(j = 1;j <= n; j++)
			if((LL) (i - 1) * (y[j] - y[1]) == (LL) (j - 1) * (y[i] - y[1]))
				d[j] = 1;
			else d[j] = 0;
		int k = 0; bool ok = 1;
		for(j = 1; j <= n; j++) {
			if(d[j]) continue;
			if(!k) k = j;
			else 
				if((LL) (i - 1) * (y[j] - y[k]) != (LL) (j - k) * (y[i] - y[1]))
					ok = 0;
		}
		if(ok && k) ans = 1;
	}
	
	if(ans) puts("Yes"); else puts("No");
	return 0;
}