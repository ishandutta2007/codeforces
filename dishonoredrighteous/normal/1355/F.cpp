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

const int N = 2020;
const ll INF = (ll)1e18;
bool p[N];

ll query(ll x) {
	printf("? %lld\n", x);
	cerr << "? " << x << endl;
	fflush(stdout);
	scanf("%lld", &x);
	cerr << "gcd " << x << endl;
	return x;
}

void solve() {

	ll C = (ll)1e9 / 2 / 2;
	vector<ll> hv;
	vector<ll> cur;
	ll curProd = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		ll cc = C;
		for (int j = 0; j < 3; j++)
			cc /= i;
		if (cc == 0) break;
		if (INF / i < curProd) {
			ll g = query(curProd);
			while(!cur.empty()) {
				if (g % cur.back() == 0) {
					hv.push_back(cur.back());
					if ((int)hv.size() <= 2) C *= 2;
					C /= hv.back();
				}
				cur.pop_back();
			}
			curProd = 1;
		}
		cur.push_back((ll)i);
		curProd *= i;
	}
	if (!cur.empty()) {
		ll g = query(curProd);
		while(!cur.empty()) {
			if (g % cur.back() == 0) hv.push_back(cur.back());
			cur.pop_back();
		}
	}
	if ((int)hv.size() & 1) {
		for (int i = 2; i < N; i++) {
			if (!p[i]) continue;
			bool fnd = false;
			for (ll x : hv)
				fnd |= i == x;
			if (!fnd) {
				hv.push_back(i);
				break;
			}
		}
	}
	ll ans = 2;
	for (int i = 0; i < (int)hv.size(); i += 2) {
		ll p1 = hv[i], p2 = hv[i + 1];
		ll x1 = 1, x2 = 1;
		while(x1 * p1 <= (ll)1e9) x1 *= p1;
		while(x2 * p2 <= (ll)1e9) x2 *= p2;
		ll g = query(x1 * x2);
		int t1 = 1, t2 = 1;
		while(g % p1 == 0) {
			g /= p1;
			t1++;
		}
		while(g % p2 == 0) {
			g /= p2;
			t2++;
		}
		ans *= t1 * t2;
	}
	printf("! %lld\n", max(8LL, ans));
	cerr << "ans " << ans << endl;
	fflush(stdout);
}

int main()
{
	startTime = (double)clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 2; i < N; i++)
		p[i] = 1;
	for (int i = 2; i < N; i++) {
		if (!p[i]) continue;
		for (int j = 2 * i; j < N; j += i)
			p[j] = 0;
	}

	int t;
	scanf("%d", &t);
	cerr << "tests = " << t << endl;
	while(t--) solve();


	return 0;
}