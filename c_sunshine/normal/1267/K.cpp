#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ook order_of_key
#define fbo find_by_order

using namespace std;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define f first
#define s second
#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;

int t;
ll k;

ll comb(int a, int b) {
	ll res = 1;
	F0R(i,b) {
		res *= a-i;
		res /= i+1;
	}
	return res;
}

ll tot;

void tri(vi v) {
	int used = 0;
	ll ans = 1;
	for (int i = 0; i < sz(v); ) {
		int I = i; while (i < sz(v) && v[i] == v[I]) i ++;
		int mx = 1+sz(v); mx -= v[I]+used;
		if (v[I] == 0) mx --;
		// cout << "?? " << mx << " " << i-I << " " << v[I] << "\n";
		ans *= comb(mx,i-I);
		used += i-I;
	}
	/*trav(t,v) cout << t << " ";
	cout << "\n";
	cout << ans << "\n";*/
	tot += ans;
}

void solve() {
	cin >> k;
	vi v;
	for (int i = 2; k; ++i) {
		v.pb(k%i);
		k /= i;
	}
	sort(v.rbegin(),v.rend());
	tot = 0;
	F0R(i,sz(v)) {
		if ((i == 0 || v[i] != v[i-1]) && v[i]) {
			vi lef;
			F0R(j,i) lef.pb(v[j]);
			FOR(j,i+1,sz(v)) lef.pb(v[j]);
			tri(lef);
		}
	}
	/**/
	/*sort(all(v));
	int tot = 0;
	do {
		bool ok = 1;
		F0R(i,sz(v)) {
			if (v[i] >= i+2) ok = 0;
		}
		if (v.back() == 0) ok = 0;
		tot += ok;
	} while (next_permutation(all(v)));*/
	cout << tot-1 << "\n";
}
	
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	F0R(i,t) solve();
}