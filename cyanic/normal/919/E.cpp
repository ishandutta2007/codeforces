#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL maxn = 1000009;
LL pos[maxn], now = 1, ans, loop;
LL a, b, p, limit, x, y, gcd, t, mn;

LL exgcd(LL a, LL b, LL &x, LL &y) {
	if (!b) { x = 1; y = 0; return a; }
	LL g = exgcd(b, a%b, y, x); y-=a/b*x; return g;
}

int main() {
	scanf("%I64d%I64d%I64d%I64d", &a, &b, &p, &limit);
	memset(pos, -1, sizeof pos);
	pos[now] = 0;
	for (LL i=1; i<=p-1; i++) {
		now = now * a % p;
		if (pos[now] != -1) {
			loop = i; break;
		}
		pos[now] = i;
	}
	//printf("%I64d\n", loop);
	for (LL n=1; n<=p-1; n++) {
		gcd = exgcd(n, p, x, y);
		x = (x * b % p + p) % p;	//a^t == x
		//printf("%I64d %I64d\n", n, x);
		t = pos[x];					//mn == t (mod p-1)
		if (t == -1) continue;
		gcd = exgcd(p, loop, x, y);
		y = (y * (n - t + p) % p + p) % p;
		mn = y * loop + t;
		mn %= p * loop;
		//printf("%I64d    %I64d\n", t, mn);
		if (!mn) mn = p * loop;
		ans += limit / (p * loop);
		ans += (mn <= limit % (p * loop));
	}
	printf("%I64d\n", ans);
	return 0;
}