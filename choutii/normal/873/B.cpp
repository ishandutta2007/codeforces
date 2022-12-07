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
int n; char s[MaxN];
int dt[MaxN << 1], *d = dt + MaxN;

int p0[MaxN], p1[MaxN];
int main() {
	int i;
	cin >> n; scanf("%s", s + 1);
	for(i = 1; i <= n; i++) {
		p0[i] = p0[i - 1] + (s[i] == '0');
		p1[i] = p1[i - 1] + (s[i] == '1');
	}
	
	memset(dt, -1, sizeof(dt));
	
	d[0] = 0;
	int ans = 0;
	for(i = 1; i <= n; i++) {
		int o = p1[i] - p0[i];
		if(d[o] != -1) cmax(ans, i - d[o]);
		if(d[p1[i] - p0[i]] == -1) d[p1[i] - p0[i]] = i;
	}
	
	cout << ans;
	return 0;
}