#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

double startTime;
double getCurrentTime() {
	return ((double)clock() - startTime) / CLOCKS_PER_SEC;
}

const ll INF = (ll)2e18 + 77;
const int N = 100100;
int n;
ll h[N];
ll pref[N];
ll A, R, M;
ll ans = INF;

ll solve(ll H) {
	int pos = lower_bound(h, h + n, H) - h;
	ll res = 0;
	ll k1 = H * pos - pref[pos];
	ll k2 = pref[n] - pref[pos] - H * (n - pos);
	res = min(k1, k2);
	k1 -= res;
	k2 -= res;
	res *= M;
	res += k1 * A;
	res += k2 * R;
	return res;
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld%lld%lld", &n, &A, &R, &M);
	M = min(M, A + R);
	for (int i = 0; i < n; i++)
		scanf("%lld", &h[i]);
	sort(h, h + n);
	for (int i = 0; i < n; i++)
		pref[i + 1] = pref[i] + h[i];

	ans = min(ans, solve(pref[n] / n));
	ans = min(ans, solve(pref[n] / n + 1));
	for (int i = 0; i < n; i++)
		ans = min(ans, solve(h[i]));
	printf("%lld\n", ans);

	return 0;
}