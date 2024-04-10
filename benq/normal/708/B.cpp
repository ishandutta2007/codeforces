#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

pair<bool,ll> fi(ll x) {
	ll cur = 1;
	while (cur*(cur-1)/2<x) cur++;
	pair<bool,ll> h;
	h.s = cur;
	if (cur*(cur-1)/2 == x) h.f = 1;
	else h.f = 0;
	return h;
}

string j = "Impossible";

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	ll a,b,c,d; cin >> a >> b >> c >> d; 
	auto y = fi(a), z = fi(d), x = fi(a+b+c+d); 
	if (!x.f || !y.f || !z.f) {
		cout << j;
		return 0;
	}
	if (a == 0) {
		if (b || c) y.s = 1;
		else y.s = 0;
	}
	if (d == 0) {
		if (b || c) z.s = 1;
		else z.s = 0;
	}
	if (y.s+z.s == 0) {
		cout << 0; return 0;
	} else if (y.s == 0) {
		F0R(i,z.s) cout << 1; 
		return 0;
	} else if (z.s == 0) {
		F0R(i,y.s) cout << 0;
		return 0;
	}
	if (y.s+z.s != x.s) {
		cout << j;
		return 0;
	}
	ll q = b/y.s, q1 = b % y.s;
	F0R(i,z.s-q-1) cout << 1;
	F0R(i,q1) cout << 0;
	if (q != z.s) cout << 1;
	F0R(i,y.s-q1) cout << 0;
	F0R(i,q) cout << 1;
}