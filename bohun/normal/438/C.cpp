#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
 
 
using namespace std;	
const int nax = 202;
const int mod = 1e9 + 7;

int n;

struct punkt {
	int x, y;
	punkt () {}
	punkt (int x, int y): x(x), y(y) {}
};

ll wek(punkt a, punkt b) {
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

ll ska(punkt a, punkt b) {
	return 1LL * a.x * b.x + 1LL * a.y * b.y;
}

int sign(ll x) {
	if(x > 0)
		return 1;
	if(x < 0)
		return -1;
	return 0;
}

punkt sub(punkt a, punkt b) {
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

punkt t[nax];	

bool online(punkt p, punkt k, punkt a) {
	if(wek(sub(k, p), sub(a, p)) != 0)
		return 0;
	if(ska(sub(p, a), sub(k, a)) < 0)
		return 1;
	return 0;
}

int side(punkt p, punkt k, punkt a) {
	ll q = wek(sub(k, p), sub(a, p));
	return sign(q);
}

bool intersection(punkt a, punkt b, punkt c, punkt d) { 
	int q = side(a, b, c) * side(a, b, d);
	int qq = side(c, d, a) * side(c, d, b);
	return q < 0 && qq < 0;
}

ll pole() {
	ll res = 0;
	FOR(i, 1, n)
		res += wek(t[i], t[i + 1]);
	return res;
}

ld pi = acos(-1);

bool between(punkt a, punkt b, punkt c) {
	ld ka = atan2(a.y, a.x);
	ld kb = atan2(b.y, b.x);
	ld kc = atan2(c.y, c.x);
	while(kb < ka)
		kb += 2 * pi;
	while(kc < ka)
		kc += 2 * pi;
	return kc < kb;
}
	
int good[nax][nax];
int dp[nax][nax], byl[nax][nax];

int makedp(int l, int r) {
	if(l + 2 >= r)
		return good[l][r];
	if(byl[l][r])
		return dp[l][r];
	int ans = 0;
	FOR(i, l + 1, r - 1) 
		if(good[l][i] && good[i][r]) {
			ans = (ans + 1LL * makedp(l, i) * makedp(i, r)) % mod;
		}
	byl[l][r] = 1;
	return dp[l][r] = ans;
}

int main() {	
	scanf("%d", &n);
	FOR(i, 1, n) 
		scanf("%d%d", &t[i].x, &t[i].y);
	t[n + 1] = t[1];
	int z = sign(pole());
	if(z < 0) {
		reverse(t + 1, t + n + 1);
		t[n + 1] = t[1];
	}
	t[0] = t[n];
	FOR(i, 1, n) {
		good[i][i + 1] = 1;
		FOR(j, i + 2, n) {
			if(between(sub(t[j + 1], t[j]), sub(t[j - 1], t[j]), sub(t[i], t[j])))
				good[i][j] = 1;
			FOR(k, 1, n) {
				if(k != i && k != j && online(t[i], t[j], t[k]))
					good[i][j] = 0;
				if(intersection(t[i], t[j], t[k], t[k + 1]))
					good[i][j] = 0;
			}
		}
	}
	good[1][n] = 1;
	printf("%d\n", makedp(1, n));
	
	return 0;
}