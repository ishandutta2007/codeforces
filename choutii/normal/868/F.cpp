
 #include <cstdio>
#include <cstring>
#include <iostream>

typedef long long LL;
using namespace std;

template <typename T> inline T cmax(T & a, const T & b) {return a < b ? a = b, 1 : 0; }
template <typename T> inline T cmin(T & a, const T & b) {return b < a ? a = b, 1 : 0; }

const int MaxN = 101234;
const LL inf = (1ll << 60);

int n, K, a[MaxN], L, R; LL w, f[MaxN], g[MaxN], cnt[MaxN];

void solve(int l, int r, int qL, int qR) {
	if(qL > qR) return;
	int o = qL + qR >> 1, mid; LL t = inf;
	for(int i = l + 1; i <= min(o, r + 1); i++) {
		while(L > i)   w += cnt[a[--L]], cnt[a[L]]++;
		while(L < i)   cnt[a[L]]--, w -= cnt[a[L++]];
		while(R < o) w += cnt[a[++R]], cnt[a[R]]++;
		while(R > o) cnt[a[R]]--, w -= cnt[a[R--]];
		if(cmin(t, f[i - 1] + w)) mid = i - 1;
	}
	
	g[o] = t; 
	solve(l, mid, qL, o - 1);
	solve(mid, r, o + 1, qR);
}
int main() {
	int i;
	scanf("%d%d", &n, &K);
	for(i = 1; i <= n; i++) scanf("%d", a + i);
	for(i = 1; i <= n; i++) f[i] = inf;
	//for(i = 1; i <= K; i++) { <-- sb
	for(; K--; ){
		L = 1, R = w = 0;
		solve(0, n - 1, 1, n);
		for(i = 0; i <= n; i++) f[i] = g[i], g[i] = cnt[i] = 0;
	}
	printf("%I64d", f[n]);
	return 0;
}