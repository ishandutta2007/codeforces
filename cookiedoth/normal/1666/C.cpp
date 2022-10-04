#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second
#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define each(a, x) for(auto& a: x)

const int MOD = 1e9+7;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
	return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
	return a < b ? a = b, 1 : 0;
}


int x[3], y[3];
int parent[10];


int findset(int a) {
	if (a == parent[a]) {
		return a;
	}
	return parent[a] = findset(parent[a]);
}


int main(){
	cin.tie(0)->sync_with_stdio(0);
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	vector<int> stx, sty;
	for (int i = 0; i < 3; i++) {
		stx.pb(x[i]);
		sty.pb(y[i]);
	}
	sort(all(stx));
	stx.resize(distance(stx.begin(), unique(all(stx))));
	sort(all(sty));
	sty.resize(distance(sty.begin(), unique(all(sty))));
	vector<pair<int, int> >  p;
	for (auto x: stx) {
		for (auto y: sty) {
			p.pb(mp(x, y));
		}
	}
	vector<int> sk;
	for (int i = 0; i < sz(p); i++) {
		for (int t = 0; t < 3; t++) {
			if (p[i] == mp(x[t], y[t])) {
				sk.pb(i);
			}
		}
	}
	vector<pair<int, int> > kek;
	for (int i = 0; i < sz(p); i++) {
		for (int j = i + 1; j < sz(p); j++) {
			if (p[i].first == p[j].first || p[i].second == p[j].second) {
				kek.pb(mp(i, j));
			}
		}
	}
	ll opt = 1e18;
	int mask;
	for (int i = 0; i < (1 << sz(kek)); i++) {
		ll score = 0;
		for (int i = 0; i < sz(p); i++) {
			parent[i] = i;
		}
		for (int j = 0; j < sz(kek); j++) {
			if (i & (1 << j)) {
				score += abs(p[kek[j].first].first - p[kek[j].second].first) + abs(p[kek[j].first].second - p[kek[j].second].second);
				parent[findset(kek[j].first)] = findset(kek[j].second);
			}
		}
		if (findset(sk[0]) == findset(sk[1]) && findset(sk[0]) == findset(sk[2])) {
			if (score < opt) {
				opt = score;
				mask = i;
			}
		}
	}
	int cnt = 0;
	for (int j = 0; j < sz(kek); j++) {
		if (mask & (1 << j)) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (int j = 0; j < sz(kek); j++) {
		if (mask & (1 << j)) {
			cout << p[kek[j].first].first << ' ' << p[kek[j].first].second << ' ' << p[kek[j].second].first << ' ' << p[kek[j].second].second << '\n';
		}
	}
}