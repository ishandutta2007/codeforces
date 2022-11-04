#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define rep(i, a) for (int i = 0; i < (a); ++i)
#define repi(i, a) for (int i = 1; i <= (a); ++i)
typedef long long ll;
const int Inf = 0x3f3f3f3f;

int a, b;

void solve() {
	scanf("%d%d", &a, &b);
	if (a < b) swap(a, b);
	set<int> vas;
	int sm = a + b;
	int ras = (sm + 1) / 2, rbs = sm / 2;
	for (int i = a - ras; i <= rbs; ++i) vas.insert(a - ras + 2 * (i - a + ras));
	ras = sm / 2, rbs = (sm + 1) / 2;
	for (int i = a - ras; i <= rbs; ++i) vas.insert(a - ras + 2 * (i - a + ras));
	printf("%d\n", SZ(vas));
	for (int i : vas) printf("%d ", i);
	puts("");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) solve();
	return 0;
}