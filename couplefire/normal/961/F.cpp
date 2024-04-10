#include <bits/stdc++.h>

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)

#define all(a) (a).begin(), (a).end()
#define sz(a) int(a.size())
#define mp make_pair

#define x first
#define y second

using namespace std;

typedef long long li;

const li MOD = li(1e18) + 3;
const li BASE = 1009;

inline li norm(li a) {
	while(a >= MOD)
		a -= MOD;
	while(a < 0)
		a += MOD;
	return a;
}

inline li mul(li a, li b) {
	li m = ((long double)(a) * b) / MOD;
	return norm(a * b - m * MOD);
}

const int N = 1000 * 1000 + 555;

int n;
string s;

inline bool read() {
	if(!(cin >> n))
		return false;
	
	char buf[N];
	assert(scanf("%s", buf) == 1);
	s = buf;
	return true;
}

li h[N], pw[N];

inline void precalc() {
	h[0] = 0;
	fore(i, 0, n)
		h[i + 1] = norm(mul(h[i], BASE) + s[i] - 'a' + 1);
		
	pw[0] = 1;
	fore(i, 1, N)
		pw[i] = mul(pw[i - 1], BASE);
}

inline li getHash(int l, int r) {
	return norm(h[r] - mul(h[l], pw[r - l]));
}

inline bool eq(int i1, int i2, int l) {
	if(i1 == i2) return true;
	return getHash(i1, i1 + l) == getHash(i2, i2 + l);
}

int l[N], mx[N];

inline void solve() {
	precalc();
	
	fore(i, 0, n / 2) {
		int c1 = i, c2 = n - 1 - i;
		if(s[c1] != s[c2]) {
			l[i] = -1;
			continue;
		}
		int lf = 0, rg = min(c1, n - 1 - c2) + 1;
		while(rg - lf > 1) {
			int mid = (lf + rg) >> 1;
			
			if(eq(c1 - mid, c2 - mid, 2 * mid + 1))
				lf = mid;
			else
				rg = mid;
		}
		l[i] = lf;
	}
	
	fore(i, 0, n / 2) {
		if(l[i] < 0)
			continue;
		mx[i - l[i]] = max(mx[i - l[i]], 2 * l[i] + 1);
	}
	fore(i, 1, n / 2)
		mx[i] = max(mx[i], mx[i - 1] - 2);

	fore(i, 0, (n + 1) / 2) {
		if(i) printf(" ");
		if(mx[i] == 0) mx[i] = -1;
		printf("%d", mx[i]);
	}
	puts("");
}

int main(){
	if(read()) {
		solve();
	}
	return 0;
}