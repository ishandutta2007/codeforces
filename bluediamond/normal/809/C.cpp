#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 

bool home = true;
using namespace std;

typedef long long ll;
const ll M = (ll)1e9 + 7;
const ll BITS = 40;

ll rep(ll x) {
	x %= M;
	if (x < 0) x += M;
	return x;
}

vector<ll> place(ll num) {
	vector<ll> sol(BITS);
	for (int i = 0; i < BITS; i++) {
		sol[i] = !!(num & (1LL << i));
	}
	reverse(sol.begin(), sol.end());
	return sol;
}

void addup(ll& a, ll b) {
	a = rep(a + b);
}

ll cnt[BITS + 1][2][2][2];
ll sum[BITS + 1][2][2][2];

ll f(ll x, ll y, ll k) {
	if (x < 0 || y < 0) return 0;
	
	vector<ll> bx = place(x);
	vector<ll> by = place(y);
	vector<ll> bk = place(k);

	for (int i = 0; i <= BITS; i++) {
		for (int x = 0; x <= 1; x++) for (int y = 0; y <= 1; y++) for (int z = 0; z <= 1; z++) cnt[i][x][y][z] = sum[i][x][y][z] = 0;
	}
	
	cnt[0][1][1][1] = 1;
	sum[0][1][1][1] = 0;

	for (int i = 0; i < BITS; i++) {
		ll real_bit = (1LL << (BITS - 1 - i));
		ll hx = bx[i];
		ll hy = by[i];
		ll hk = bk[i];
		for (ll fx = 0; fx <= 1; fx++) {
			for (ll fy = 0; fy <= 1; fy++) {
				ll fxor = fx ^ fy;
				for (ll tagx = 0; tagx <= 1; tagx++) for (ll tagy = 0; tagy <= 1; tagy++) for (ll tagxor = 0; tagxor <= 1; tagxor++) {
					if (tagx && fx > hx) continue;
					if (tagy && fy > hy) continue;
					if (tagxor && fxor > hk) continue;
					addup(cnt[i + 1][tagx & (fx == hx)][tagy & (fy == hy)][tagxor & (fxor == hk)], cnt[i][tagx][tagy][tagxor]);
					addup(sum[i + 1][tagx & (fx == hx)][tagy & (fy == hy)][tagxor & (fxor == hk)], sum[i][tagx][tagy][tagxor]);
					addup(sum[i + 1][tagx & (fx == hx)][tagy & (fy == hy)][tagxor & (fxor == hk)], fxor * real_bit * cnt[i][tagx][tagy][tagxor]);
				}
			}
		}
	}
	ll sol = 0;
	for (ll tagx = 0; tagx <= 1; tagx++) for (ll tagy = 0; tagy <= 1; tagy++) for (ll tagz = 0; tagz <= 1; tagz++) {
		addup(sol, sum[BITS][tagx][tagy][tagz]);
		addup(sol, cnt[BITS][tagx][tagy][tagz]);
	}
	return sol;
}


signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}


	int tests;
	cin >> tests;
	while (tests--) {
		ll x1, y1, x2, y2, k;
		cin >> x1 >> y1 >> x2 >> y2 >> k;
		x1--;
		y1--;
		x2--;
		y2--;
		k--;


		ll sol = 0;

		sol = rep(f(x2, y2, k) - f(x1 - 1, y2, k) - f(x2, y1 - 1, k) + f(x1 - 1, y1 - 1, k));

		cout << sol << "\n";
	}

}