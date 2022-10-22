#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
#define FOR(i, n) for(int i = 1; n >= i; ++i)

using namespace std;
using namespace __gnu_pbds;

const int nax = 200005, inf = 1e9 + 1, mod = 998244353;

int h[nax];
pair<int, int> best;
vector <int> v[nax];
int p[nax];

void go(int node, int par) {
	if(h[node] > best.fi) {
		best = mp(h[node], node);
	}
	for(auto it: v[node]) {
		if(it != par) {
			h[it] = h[node] + 1;
			p[it] = node;
			go(it, node);
		}
	}
}

int main() {
	
	//cin.tie(0);
	//ios_base::sync_with_stdio(0);
	
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	best = mp(-1, 0);
	go(1, -1);
	int X = best.se;
	best = mp(-1, 0);
	h[X] = 0;
	go(X, -1);
	int Y = best.se;
	vector <int> can;
	p[X] = 0;
	while(Y) {
		can.pb(Y);
		Y = p[Y];
	}
	if(ss(can) % 2 == 0 || ss(can) - 1 != 2 * k) {
		cout << "No\n";
		return 0;
	}
	int root = can[best.fi / 2];
	h[root] = 0;
	go(root, -1);
	for(int i = 1; i <= n; ++i) {
		if(ss(v[i]) == 1 && h[i] != k) {
			cout << "No";
			return 0;
		}
		if(ss(v[i]) == 2) {
			cout << "No";
			return 0;
		}
		if(root != i && ss(v[i]) == 3) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
			
	
	
				
	
	
    return 0;
}