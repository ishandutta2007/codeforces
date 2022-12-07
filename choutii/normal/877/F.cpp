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

const int MaxN = 201234;
int n, m, K, a[MaxN];
LL s[MaxN], t[MaxN]; map<LL, int> mp;

int g[MaxN], Lg[MaxN], Rg[MaxN];

struct query{
	int l, r, i;
}q[MaxN]; LL ans[MaxN], cnt[MaxN];

const int B = 300;
bool cmp(query x, query y) {
	return x.l / B == y.l / B ? (((x.l / B) & 1) == ((y.l / B) & 1) ? x.r < y.r : x.r < y.r) : x.l / B < y.l / B; 
}

int main() {
	int i;
	n = read(); K = read();
	for(i = 1; i <= n; i++) a[i] = read();
	for(i = 1; i <= n; i++) {
		int x = read();
		a[i] = a[i] == 1 ? x : -x;
	} 
	t[0] = s[0] = 0;
	for(i = 1; i <= n; i++) t[i] = s[i] = s[i - 1] + a[i];
	
	sort(t, t + n + 1);
	for(i = 0; i <= n; i++) mp[t[i]] = i + 1;
	
	for(i = 0; i <= n; i++) {
		Rg[i] = mp[s[i] + K];
		g[i] = mp[s[i]];
		Lg[i] = mp[s[i] - K];
	}

	m = read();
	for(i = 1; i <= m; i++) q[i].l = read(), q[i].r = read(), q[i].i = i;
	
	sort(q + 1, q + m + 1, cmp);
	
	int L = q[1].l - 1, R = q[1].r; LL res = 0;
	
	for(i = L; i <= R; i++) {
		res += cnt[Lg[i]], cnt[g[i]]++;
	}
	
	ans[q[1].i] = res;
	
	for(i = 2; i <= m; i++) {
		int l = q[i].l - 1, r = q[i].r;
		while(R < r) 
			res += cnt[Lg[++R]], cnt[g[R]]++;
		while(R > r) 
			cnt[g[R]]--, res -= cnt[Lg[R--]];
		while(L > l) 
			res += cnt[Rg[--L]], cnt[g[L]]++;
		while(L < l) 
			cnt[g[L]]--, res -= cnt[Rg[L++]];
		ans[q[i].i] = res;
	} 
	
	for(i = 1; i <= m; i++) printf("%lld\n", ans[i]);
	return 0;
}