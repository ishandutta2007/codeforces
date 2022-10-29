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

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;

str s;
int ans;

void bad(int x = 0) {
cout << x; exit(0);
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	vector<pair<char,int>> v;
	F0R(i,sz(s)) {
		if (sz(v) && v.back().f == s[i]) v.back().s ++;
		else v.pb({s[i],1});
	}
	// trav(t,v) cout << t.f << " " << t.s << "\n";
	if (sz(v)&1) {
		int ind = sz(v)/2;
		if (v[ind].s < 2) bad();
		while (ind) {
			ind --;
			if (v[ind].f != v[sz(v)-1-ind].f || v[ind].s+v[sz(v)-1-ind].s < 3) bad();
		}
		bad(v[sz(v)/2].s+1);
	}
	bad();
}