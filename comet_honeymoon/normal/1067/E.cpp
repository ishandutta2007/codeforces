#include<bits/stdc++.h>
using namespace std;

const int p = 998244353, inv2 = (p + 1) / 2;
struct Z {int x; Z(int x0 = 0) : x(x0) {}};
int inline check(int x) { return x >= p ? x - p : x; }
Z operator +(const Z a, const Z b) { return check(a.x + b.x); }
Z operator -(const Z a, const Z b) { return check(a.x - b.x + p); }
Z operator -(const Z a) {return check(p - a.x);}
Z operator *(const Z a, const Z b) { return 1LL * a.x * b.x % p; }
Z& operator +=(Z &a, const Z b) { return a = a + b; }
Z& operator -=(Z &a, const Z b) { return a = a - b; }
Z& operator *=(Z &a, const Z b) { return a = a * b; }
Z qpow(Z a, int k) {
	Z ans = 1;
	for (; k; a *= a, k >>= 1) if(k & 1) ans *= a;
	return ans;
}

int n;
Z f[500005];
vector<int> G[500005];
Z ans;
void solve(int x, int fa) {
	f[x] = 1;
	for (int y : G[x]) if (y != fa)
		solve(y, x), f[x] *= (1 + f[y]) * inv2;
	f[x] = 1 - f[x];
	ans += f[x];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v), G[v].push_back(u);
	}
	solve(1, 0);
	printf("%d\n", ans * qpow(2, n));
}