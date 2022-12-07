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

int n, a[MaxN], b[MaxN], c[MaxN];
vector<int> ans[MaxN];

int main() {
	int i;
	n = read();
	for(i = 1; i <= n; i++) a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	for(i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	int _ans = 0, j;
	for(i = 1; i <= n; i++) {
		if(c[i]) continue;
		for(++_ans, j = i; !c[j]; c[j] = 1, ans[_ans].emplace_back(j), j = a[j]);
	}
	printf("%d\n", _ans);
	for(i = 1; i <= _ans; i++) {
		printf("%d ", ans[i].size());
		for(auto x : ans[i]) 
			printf("%d ", x); puts("");
	}
	return 0;
}