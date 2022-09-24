#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:512000000")
#include<utility>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<functional>
#include<random>
#include<climits>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<cassert>
#include<ccomplex>
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define forn(i, n, m) for (ll i = (n); i<=(m); i++)
#define all(x) x.begin(), x.end()
#define mp make_pair
#define X first
#define Y second
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 gen(time(NULL));
ll const mod = 1e9 + 7;
namespace {
	ll mul(ll a, ll b) {
		ll val = a * b - (ll)((ld)a * b / mod) * mod;
		if (val < 0) val += mod;
		if (val >= mod) val -= mod;
		return val;
	}
	ll poww(ll a, ll b) {
		ll val = 1;
		a %= mod;
		while (b > 0) {
			if (b % 2) val = mul(a, val);
			a = mul(a, a);
			b >>= 1;
		}
		return val % mod;
	}
	ll inv(ll a) {
		return poww(a, mod - 2);
	}
}
ll const maxn = 2e5 + 5;
set<ll>g[maxn];
set<ll>gg[maxn];
bool used[maxn];
signed main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	vector<ll>a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	set<ll> nice;
	for (ll bit = 0; bit < 64; bit++) {
		vector<ll>idx;
		for (ll i = 0; i < n; i++) {
			if ((1LL << bit) & a[i]) {
				idx.push_back(i);
			}
		}
		if (idx.size() >= 3) {
			cout << 3 << endl;
			return 0;
		}
		else {
			if (idx.size() == 2) {
				g[idx[0]].insert(idx[1]);
				g[idx[1]].insert(idx[0]);
				gg[idx[0]].insert(idx[1]);
				gg[idx[1]].insert(idx[0]);
				nice.insert(idx[0]);
				nice.insert(idx[1]);
			}
		}
	}
	ll ans = maxn;
	for (ll i : nice) {
		for (ll j : gg[i]) {
			for (auto k : nice) {
				used[k] = 0;
			}
			g[i].erase(j);
			g[j].erase(i);
			map<ll, ll>d;
			d[i] = 0;
			queue<ll>q;
			q.push(i);
			used[i] = 1;
			while (!q.empty()) {
				ll u = q.front();
				q.pop();
				for (ll v : g[u]) {
					if (used[v]) continue;
					d[v] = d[u] + 1;
					q.push(v);
					used[v] = 1;
				}
			}
			if (d.count(j)) {
				ans = min(ans, d[j] + 1);
			}
			g[i].insert(j);
			g[j].insert(i);
		}
	}
	if (ans == maxn) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}