#include <bits/stdc++.h>
using namespace std;
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;

vector<int> off, inter, speed;

const ll M = 998244353;

const int N = 505;
// 0 --> 1
// 1 --> prime
// 2 --> square
// 3 --> cube
// 4 --> quat
// 5 --> pq
int state[N] = {};
ll A[N];
ll sqt[N] = {};


set<ll> known;

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

ll root(ll a, ll v) {
	ll lo = 0;
	ll hi = pow(4 * 1e18 + 100, 1.0/v);
	ll ans = -1;
	while(lo <= hi) {
		ll md = (lo+hi)/2;
		ll m = 1;
		for(int i = 0; i < v; ++i)
			m *= md;
		if(m == a) {
			return md;
			break;
		} else if(m < a)
			lo = md+1;
		else hi = md-1;
	}
	return 0;
}

int main() {
	fio;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		A[i] = a;

		state[i] = 5;
		for(int p = 4; p >= 2; --p) {
			ll r = root(a, p);
			if(r != 0) {
				known.insert(r);
				state[i] = p;
				break;
			}
		}

	}
	map<ll, int> mult;
	map<ll, int> type;
	for(int i = 0; i < n; ++i) {
		++mult[A[i]];
		type[A[i]] = state[i];
		for(int j = i+1; j < n; ++j) {
			if(state[i] != 5 && state[j] != 5) continue;
			if(A[i] == A[j]) continue;
			ll g = gcd(A[i], A[j]);
			if(g != 1) {
				known.insert(g);
				if(state[i] == 5)
					known.insert(A[i]/g);
				if(state[j] == 5)
					known.insert(A[j]/g);
			}
		}
	}
	ll ans = 1;

	for(ll p : known) {
		ll counts = 0;
		map<ll, int> m2;
		map<ll, int> s2;
		int amt = 0;
		for(auto x : mult) {
			ll k = x.first;
			ll pw = 0;
			while(k % p == 0) {
				k /= p;
				++pw;
			}
			if(k == 1)
				amt += pw * x.second;
			else if(pw > 0) {
				amt += x.second;
				m2[k] += x.second;
				s2[k] = 1;
			} else {
				m2[k] = x.second;
				s2[k] = type[x.second];
			}
		}
		ans = ans * (amt + 1) % M;
		mult = m2;
		type = s2;
	}

	for(auto x : mult) {
		if(type[x.first] == 1) {
			ans = ans * x.second  % M * 2 % M;
		} else {
			ll tmp = x.second+1;
			ans = ans * tmp % M * tmp % M;
		}
	}

	cout << ans << "\n";
}