#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef long double ld;

ll egcd(ll a, ll b, ll& x, ll& y) {
	x = 1; y = 0;
	ll r = 0, s = 1;
	while (b != 0) {
		ll c = a % b, quot = a / b;
		a = b; b = c;
		ll new_r = x - quot * r, new_s = y - quot * s;
		x = r; y = s;
		r = new_r; s = new_s;
	}
	return a;
}
// General solution of a*x + b*y = c:
// // int x0, y0; int g = egcd(a, b, x0, y0);
// // if (c % g != 0) no solution;
// // else, all the solutions are of the form:
// // x = (c/g)*x0 + (b/g)*t, y = (c/g)*y0 - (a/g)*t;


bool fes(ll a, ll b, ll x, ll y, ll t) {
	ll s = 0;
	while (x or y) {
		if (x and s + a <= t) {
			s += a;
			--x;
		} else if (y and s >= b) {
			s -= b;
			--y;
		} else return false;
	}
	return true;
}

ll calc(ll a, ll b, ll x, ll y) {
	ll exa = 0;
	ll exb = a*x;
	while (exa + 1 < exb) {
		ll exc = (exa+exb)/2;
		if (fes(a,b,x,y,exc)) exb = exc;
		else exa = exc;
	}
	return exb;
}

ll sum1(ll a, ll b, ll n) {
	if (n == 0) return 0;
	vi V(n,0);
	V[0] = 1;
	ll res = 1;
	ll val = 1;
	for (int i = 1; i < n; ++i) {
		if (i >= a and V[i-a] == 1) {
			V[i] = 1;
			++val;
			queue<int> Q;
			Q.push(i);
			while (!Q.empty()) {
				int x = Q.front();
				Q.pop();
				if (x + a <= i and V[x+a] == 0) {
					++val;
					V[x+a] = 1;
					Q.push(x+a);
				}
				if (x - b >= 0 and V[x-b] == 0) {
					++val;
					V[x-b] = 1;
					Q.push(x-b);
				}
			}
		}
		res += val;
	}
	return res;
}

ll sum2(ll d, ll n1, ll n2) {
	ll res = 0;
	for (ll i = n1; (i/d) == (n1/d) and i <= n2; ++i) {
		res += (n1/d)+1;
	}
	for (ll i = n2; (i/d) == (n2/d) and (i/d) != (n1/d) and i >= n1; --i) {
		res += (n2/d)+1;
	}
	ll k1 = 2 + (n1/d);
	ll k2 = (n2/d);
	if (k1 <= k2) {
		res += d*(k2*(k2+1)/2 - k1*(k1-1)/2);
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll m, a, b;
	cin >> m >> a >> b;
	ll x0,y0;
	ll g = egcd(a,b,x0,y0);
	ll x = x0;
	ll y = y0;
	while (x < 0 or y > 0) {
		x += (b/g);
		y -= (a/g);
	}
	y = abs(y);
	ll extrem = a - 2*g + calc(a,b,x,y);
	ll res = sum1(a,b,min(extrem,m+1)) + sum2(g,min(extrem,m+1),m);
	cout << res << '\n';
}