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
#include <numeric> 

bool home = 1;
using namespace std;
#define int long long]

typedef long long ll;

ll d, val1, val2;

pair<ll, ll> gcd(ll a, ll b) {
	if (b == 0) {
		d = a;
		return { 1, 0 };
	}
	ll c = a / b;
	pair<ll, ll> it = gcd(b, a - b * c);

	return { it.second, it.first - it.second * c };
}

vector<pair<ll, ll>> solve(ll a, ll b, ll c) {
	auto it = gcd(a, b);
	assert(a * it.first + b * it.second == d);
	if (c % d) return {};
	c = c / d;
	val1 = b / d;
	val2 = a / d;
	it.first *= c;
	it.second *= c;
	return { it };
}

const ll INF = (ll)2e9 + 7;

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

	ll a1, b1, a2, b2, l, r, x, y;
	cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
	{
		auto sol = solve(a1, -a2, b2 - b1);
		if (sol.empty()) {
			cout << "0\n";
			return 0;
		}
		assert(sol.size() == 1);
		x = sol[0].first, y = sol[0].second;
	}
	b1 += INF;
	b2 += INF;
	l += INF;
	r += INF;

	if (val1 < 0) {
		val1 *= -1, val2 *= -1;
	}

	if (x >= 0) {
		ll t = x / val1;
		x -= t * val1;
		y += t * val2;
	}
	else {
		ll t = (-1 - x) / val1 + 1;
		x += t * val1;
		y -= t * val2;
	}


	ll L = l, R = r;


	l -= b1, r -= b1;
	l = max(0LL, l);
	if (r < 0) { cout << "0\n"; return 0; }
	l = (l + a1 - 1) / a1, r = r / a1;
	l -= x, r -= x;
	l = max(0LL, l);
	if (r < 0) { cout << "0\n"; return 0; }
	l = (l + val1 - 1) / val1, r /= val1;
	l = max(0LL, l);
	ll sol = 0;
	assert(val2 <= 0);

	val2 *= -1;
	y *= -1;

	l = max(l, (y + val2 - 1) / val2);


	if (l <= r) {
		sol += r - l + 1;
	}



	cout << sol << "\n";
}