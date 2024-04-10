 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

ll solve(ll a) {
	ll ans = 0;
	if(a == 0) return 0;
	if(a == 1) return 1;
	if(a == 2) return 1;
	if(a == 4) return 3;
	if(a % 4 != 2) {
		ans++;
		a--;
		ans += a - solve(a);
	} else {
		ans += a/2;
		a /= 2;
		ans += a - solve(a);
	}
	return ans;
}


int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;
	cin >> t;
	while(t--) {
		ll a; cin >> a;
		cout << solve(a) << endl;
	}
}