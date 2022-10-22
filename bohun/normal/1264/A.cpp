#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

const int mod = 1e9 + 7;
const int nax = 1e6 + 111;


int pt(int a, int b) {int c = 1; while(b) {if(b & 1) c = 1ll * c * a % mod; a = 1ll * a * a % mod; b /= 2;} return c;}

int fac[nax];
int rev[nax];

void elo() {
	fac[0] = rev[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
}

int T;
int n;
int a[nax];

multiset <int> secik;

int main() {
	elo();
	scanf("%d", &T);
	while(T--) {
		secik.clear();
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		int pr = n / 2;
		while(pr > 0 && a[pr] == a[n / 2 + 1])
			pr--;

		int best = 0;
		int A = 0;
		int B = 0;
		int C = 0;
		for(int i = 1; i < pr; ++i)
			if(a[i] != a[i + 1])
				secik.insert(i);
		for(int i = 1; i < pr; ++i) {
			if(a[i] == a[i + 1])
				continue;
			auto it = secik.lower_bound(2 * i + 1);
			if(it == secik.end() || *it == pr - 1 || pr - *it <= i)
				continue;
			A = i;
			B = *it - i;
			C = pr - *it;
		}

		printf("%d %d %d\n", A, B, C);
	}




	return 0;
}