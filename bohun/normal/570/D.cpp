#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)	
	
		
using namespace std;

const int nax = 5e5 + 111;

int n, q;
vector <int> v[nax];
int a, b;
char s[nax];
vector <pair<int, int>> query[nax];
map <int, int> *cnt[nax];
int h[nax];
int ans[nax];

void dfs(int u, int p) {
	h[u] = h[p] + 1;
	int siz = -1;
	int big = -1;
	for(auto it : v[u]) {
		dfs(it, u);
		if(ss((*cnt[it])) > siz) {
			siz = ss((*cnt[it]));
			big = it;
		}
	}
	if(siz == -1) {
		cnt[u] = new map<int, int>;
	}
	else {
		cnt[u] = cnt[big];
	}
	for(auto it : v[u]) { 
		if(it != big) {
			for(auto it : (*cnt[it]))
				(*cnt[u])[it.fi] ^= it.se;
		}
	}
	(*cnt[u])[h[u]] ^= (1 << (s[u] - 'a'));
	for(auto it : query[u]) {
		ans[it.se] = (__builtin_popcount((*cnt[u])[it.fi]) <= 1);
	}
}

int main() {	
	scanf("%d %d", &n, &q);
	FOR(i, 2, n) {
		scanf("%d", &a);
		v[a].pb(i);
	}
	scanf("%s", s + 1);
	FOR(i, 1, q) {
		scanf("%d %d", &a, &b);
		query[a].pb(mp(b, i));
	}
	dfs(1, 0);
	FOR(i, 1, q) {
		printf(ans[i] ? "Yes\n" : "No\n");
	}
		
	
	
	
			
	return 0;
}