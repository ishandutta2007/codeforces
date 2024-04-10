#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a) for (int i = 0; i < (a); ++i)
#define cont(i, a) for (int i = 1; i <= (a); ++i)
#define circ(i, a, b) for (int i = (a); i <= (b); ++i)
#define range(i, a, b, c) for (int i = (a); (c) > 0 ? i <= (b) : i >= (b); i += (c))
#define parse(it, x) for (auto &it : (x))
#define pub push_back
#define pob pop_back
#define emb emplace_back
#define mak make_pair
#define mkt make_tuple
typedef long long ll;
typedef long double lf;
const int Inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

int n;
ll a[100005], b[100005];
int id[100005];

int main() {
	scanf("%d", &n);
	cont(i, n) scanf("%lld%lld", a + i, b + i), id[i] = i;
	sort(id + 1, id + n + 1, [&] (int x, int y) { return b[x] > b[y]; });
	ll sm = accumulate(a + 1, a + n + 1, 0ll), res = sm * 2;
	cont(I, n) {
		int i = id[I];
		ll sel = max(0ll, min(sm - b[i], a[i]));
		res -= sel; sm -= sel;
	}
	printf("%lld\n", res);
	return 0;
}