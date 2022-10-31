#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define trav(a, x) for(auto& (a) : (x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ff first
#define ss second
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int S = int(2e5)+10;
const ll MOD = ll(1e9)+7;
const ll b = 113;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
pll comb(pll a, pll b) {
	return {(a.ff*b.ff)%MOD, (a.ff*b.ss + a.ss) % MOD};
}
 
pll t[4*S];
ll b1 = rng()%MOD, k1 = rng()%MOD, b2 = rng()%MOD;
string s;
 
void build(int v, int tl, int tr) {
	if(tr - tl == 1) {
		if(s[tl] == '0')
			t[v] = {k1, b1};
		else
			t[v] = {MOD-1, b2};
	} else {
		int tm = (tl+tr)/2;
		build(2*v+1, tl, tm);
		build(2*v+2, tm, tr);
		t[v] = comb(t[2*v+1], t[2*v+2]);
	}
}
 
pll get(int v, int tl, int tr, int l, int r) {
	if(l >= r)
		return {1,0};
	if(tl == l && tr == r)
		return t[v];
	int tm = (tl+tr)/2;
	return comb(get(2*v+1, tl, tm, l, min(tm, r)), get(2*v+2, tm, tr, max(l, tm), r));
}
 
int n, q;
 
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> n >> s >> q;
	build(0, 0, n);
	rep(i, 0, q) {
		int s1,s2,l;
		cin >> s1 >> s2 >> l;
		s1--;s2--;
		if(get(0, 0, n, s1, s1+l) == get(0, 0, n, s2, s2+l))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}