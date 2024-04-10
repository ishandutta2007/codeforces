#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 998244353
#define forn(a, n) for(tint a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(tint a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long tint;
typedef vector<tint> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vvi> vvvi;
typedef vector<pair<tint,tint>> vp;
typedef vector<vp> vvp;
typedef tree<pair<tint, tint>,null_type,less<pair<tint, tint>>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

tint modexp(tint b, tint e) {
	if(e == 0) return 1;
	tint res = modexp(b, e/2);
	res = (res*res)%MOD;
	if(e%2) res = (res*b)%MOD;
	return res;
}

tint inv(tint b) {
	return modexp(b, MOD-2);
}

tint dfs(
	tint act, 
	tint p, 
	tint nact, 
	vector<vector<pair<tint,pair<tint,tint>>>>& grafo, 
	vector<unordered_map<tint, tint>>& fl, 
	unordered_map<tint, tint>& fact, 
	unordered_map<tint, tint>& mins
) {
	tint acc = nact;
	for(auto j: grafo[act]) if(j.first != p) {
		for(auto [p, e]: fl[j.second.second]) {
			fact[p] += e;
		}
		for(auto [p, e]: fl[j.second.first]) {
			fact[p] -= e;
			mins[p] = min(mins[p], fact[p]);
		}
		nact *= j.second.second;
		nact %= MOD;
		nact *= inv(j.second.first);
		nact %= MOD;
		acc += dfs(j.first, act, nact, grafo, fl, fact, mins);
		acc %= MOD;
		nact *= inv(j.second.second);
		nact %= MOD;
		nact *= j.second.first;
		nact %= MOD;
		for(auto [p, e]: fl[j.second.first]) {
			fact[p] += e;
		}
		for(auto [p, e]: fl[j.second.second]) {
			fact[p] -= e;
		}
	}
	return acc;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	
	const tint MAXN = 200010;
	vi fact(MAXN, -1);
	forsn(i, 2, MAXN) {
		if(fact[i] == -1) {
			for(int j = i; j < MAXN; j += i) {
				fact[j] = i;
			}
		}
	}
	vector<unordered_map<tint, tint>> fl(MAXN);
	forsn(i, 2, MAXN) {
		fl[i] = fl[i/fact[i]];
		fl[i][fact[i]]++;
	}
	
	forn(tc, T) {
		tint n;
		cin >> n;
		
		vector<vector<pair<tint, pair<tint, tint>>>> grafo(n);
		forn(i, n-1) {
			int a, b, x, y;
			cin >> a >> b >> x >> y;
			a--; b--;
			grafo[a].push_back({b, {x,y}});
			grafo[b].push_back({a, {y,x}});
		}
		unordered_map<tint, tint> mins, fact;
		tint ans = dfs(0, -1, 1, grafo, fl, fact, mins);
		for(auto& [p, e]: mins) {
			if(e < 0) {
				ans *= modexp(p, -e);
				ans %= MOD;
			}
		}
		cout << ans << endl;
	}
}