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

int N;
ll C;
ll a[1000005];
bool ful[1000005];
ll xf[1000005], mn[1000005];

int main() {
	scanf("%d%lld", &N, &C);
	cont(i, N - 2) scanf("%lld", a + i);
	ll sig = 1, del = 0;
	deque<pair<ll, ll> > q;
	#define D(x) (sig * (x) + del)
	#define E(x) (((x) - del) * sig)
	#define MXL (!~sig ? q.front().second : q.back().first)
	#define MXR (!~sig ? q.front().first : q.back().second)
	#define MNR (~sig ? q.front().first : q.back().second)
	q.emb(0, C);
	cont(i, N - 2) {
		while (SZ(q) && D(MXR) > a[i]) {
			if (D(MXL) <= a[i]) MXR = E(a[i]);
			else !~sig ? q.pop_front() : q.pob();
		}
		if (SZ(q) && D(MXR) == a[i]) {
			q.clear();
			sig = 1; del = 0;
			q.emb(0, a[i]);
			ful[i] = 1;
			continue;
		}
		sig *= -1; del = a[i] - del;
		if (SZ(q) && D(MXR) != a[i]) !~sig ? q.emplace_front(E(a[i]), E(a[i])) : q.emb(E(a[i]), E(a[i]));
		if (!SZ(q)) return puts("NO"), 0;
		mn[i] = D(MNR);
		assert(mn[i] >= 0);
	}
	puts("YES");
	ll val = D(MNR); sig = 1;
	range(i, N - 2, 1, -1) {
		xf[i] = sig * val;
		if (ful[i]) val = a[i], sig *= -1;
		else if (val == a[i]) val = mn[i - 1], sig *= -1;
		else val = a[i] - val;
		assert(val >= 0);
	}
	xf[0] = sig * val;
	ll mnv = 0; val = 0;
	loop(i, N - 1) {
		val += xf[i];
		mnv = min(mnv, val);
	}
	val = -mnv; printf("%lld", val);
	loop(i, N - 1) {
		val += xf[i];
		printf(" %lld", val);
	}
	puts("");
	return 0;
}