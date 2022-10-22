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

const int nax = 2e5 + 5, pod = (1 << 17);

int n;
vector <int> v[nax];
int a, b;
int alive[nax];
int siz[nax];
int nn;
int h[nax];
int p[nax];
			
void licz(int node, int par) {
	++nn;
	siz[node] = 1;
	for(auto it: v[node]) {
		if(!alive[it] || it == par)
			continue;
		licz(it, node);
		siz[node] += siz[it];
	}
}

int daj(int node, int par) {
	for(auto it: v[node]) {
		if(alive[it] && it != par && siz[it] > nn / 2)
			return daj(it, node);
	}
	return node;
}

int q(int type, int x) {
	cout << (type == 1 ? "d" : "s");
	cout.flush();
	cout << " " << x << endl;
	cout.flush();
	int y;
	cin >> y;
	return y;
}

void ans(int x) {
	cout << "! " << x << endl;
	cout.flush();
	exit(0);
}

void dfs(int node, int par) {
	for(auto it: v[node]) {
		if(it != par) {
			h[it] = h[node] + 1;
			p[it] = node;
			dfs(it, node);
		}
	}
}

int main() {
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n - 1; ++i) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		alive[a] = alive[b] = 1;
	}
	
	dfs(1, 0);
	int node = 1;
	int H = q(1, 1);
	if(H == 0) {
		ans(1);
	}
	while(true) {
		nn = 0;
		licz(node, 0);
		int c = daj(node, 0);
		alive[c] = 0;
		int d = q(1, c);
		if(!d) {
			ans(c);
		}
		if(h[c] + d == H) {
			node = q(2, c);
		}
		else {
			node = p[c];
		}
	}
		
	
	
	
	
		
	
    return 0;
}