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
 
int ans[100001], c1,n,m,q;
vector<pair<pii,pii>> child[100001];
bitset<1000> c2[1000], ones;

void dfs(int x) {
	ans[x] = c1;
	for (auto a: child[x]) {
		if (a.f.s == 1) {
			if (!c2[a.s.f][a.s.s]) {
				c2[a.s.f][a.s.s] = 1; c1++;
				dfs(a.f.f);
				c2[a.s.f][a.s.s] = 0; c1--;
			} else dfs(a.f.f);
		} else if (a.f.s == 2) {
			if (c2[a.s.f][a.s.s]) {
				c2[a.s.f][a.s.s] = 0; c1--;
				dfs(a.f.f);
				c2[a.s.f][a.s.s] = 1; c1++;
			} else dfs(a.f.f);
		} else if (a.f.s == 3) {
			c2[a.s.f] ^= ones;
			c1 += (2*c2[a.s.f].count()-m);
			dfs(a.f.f);
			c2[a.s.f] ^= ones;
			c1 += (2*c2[a.s.f].count()-m);
		} else dfs(a.f.f);
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> q;
	F0R(i,m) ones[i] = 1;
	FOR(z,1,q+1) {
		pair<pii,pii> h; h.f.f = z; 
		cin >> h.f.s;
		if (h.f.s <= 2) {
			cin >> h.s.f >> h.s.s; h.s.f--, h.s.s--;
			child[z-1].pb(h);
		} else if (h.f.s == 3) {
			cin >> h.s.f; h.s.f--;
			child[z-1].pb(h);
		} else {
			int x; cin >> x;
			child[x].pb(h);
		}
	}
	dfs(0);
	FOR(i,1,q+1) cout << ans[i] << "\n";
}