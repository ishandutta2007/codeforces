#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

const int O = 200001;
int N, M;
int a[200005], b[200005];

struct Fenwick {
	int dt[400005];
	void inline init() { memset(dt, 0, sizeof(dt)); }
	void inline add(int a, int x) {
		while (a < 400005) dt[a] += x, a += a & -a;
	}
	int inline sum(int a) {
		int res = 0;
		while (a) res += dt[a], a -= a & -a;
		return res;
	}
} bit;

ll solve(int m) {
	repi(i, N) b[i] = (a[i] < m ? -1 : 1) + b[i - 1];
	bit.init();
	bit.add(O, 1);
	ll ans = 0;
	repi(i, N) {
		ans += bit.sum(b[i] + O - 1);
		bit.add(b[i] + O, 1);
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	repi(i, N) scanf("%d", a + i);
	printf("%lld\n", solve(M) - solve(M + 1));
	return 0;
}