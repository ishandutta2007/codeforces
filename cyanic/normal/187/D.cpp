#include<bits/stdc++.h>
#define mp make_pair
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
#define per(i,a,b) for (int i=(a); i>=int(b); i--)
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

const int maxn = 200005;
int q[maxn], Next[maxn], n, Q, G, R, m, l, r;
LL f[maxn], s[maxn], sum, tmp; set<pii> S;

void solve(int l, int r, int x) {
	set<pii>::iterator it = S.lower_bound(mp(l, 0));
	while (it != S.end() && it->first <= r)
		Next[it->second] = x, S.erase(it++);
}

int main() {
	scanf("%d%d%d", &n, &G, &R); m = G + R; n++;
	rep (i, 1, n) scanf("%lld", &s[i]), s[i] = sum = s[i-1] + s[i];
	scanf("%d", &Q);
	rep (i, 1, Q) scanf("%d", &q[i]), S.insert(mp((m - q[i]%m) % m, n + i));
	rep (i, 1, n + Q) Next[i] = n;
	rep (i, 1, n - 1) {
		l = (s[i] + 1) % m; r = (s[i] + R) % m;
		if (l <= r) solve(l, r, i);
		else solve(0, r, i), solve(l, m - 1, i);
		S.insert(mp(s[i] % m, i));
	}
	f[n] = 0; 
	per (i, n - 1, 1) 
		if (Next[i] == n) f[i] = s[n] - s[i];
		else {
			tmp = s[Next[i]] - s[i];
			f[i] = f[Next[i]] + tmp + m - tmp % m;
		} 
	rep (i, 1, Q) {
		tmp = s[Next[i+n]] + q[i];
		printf("%I64d\n", f[Next[i+n]] + tmp + (Next[i+n] == n ? 0 : m - tmp % m));
	}
	return 0;
}