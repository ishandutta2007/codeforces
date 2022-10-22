#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
	
		
using namespace std;

const int nax = 3e5 + 111;

int n, m;
int a, b;
	
int d[nax];

vector <pair<int, int>> v[nax];
vector <int> res;
vector <int> push[nax];

bool odw[nax];

int dfs(int u, int p) {
	odw[u] = 1;
	for(auto it : v[u]) {
		if(!odw[it.fi]) {
			if(dfs(it.fi, u)) {
				res.pb(it.se);
				if(d[u] >= 0)
					d[u] ^= 1;
			}
		}
	}
	if(d[u] == 1)
		return 1;
	return 0;
}

void solve(int u, int p) {
	odw[u] = 1;
	for(auto it : v[u]) {
		if(!odw[it.fi]) {
			solve(it.fi, u);
			for(auto i : push[it.fi])
				push[u].pb(i);
			if(ss(push[it.fi]))
				res.pb(it.se);
		}
	}
	if(d[u] == 1)
		push[u].pb(u);
	while(ss(push[u]) >= 2) {
		push[u].pop_back();
		push[u].pop_back();
	}
}
	


int main() {
	scanf("%d %d", &n, &m);
	int odd = 0;
	int root = -1;
	FOR(i, 1, n) {
		scanf("%d", d + i);
		odd += (d[i] % 2 == 1);
		if(d[i] == -1)
			root = i;
	}
	FOR(i, 1, m) {
		scanf("%d %d", &a, &b);
		v[a].pb(mp(b, i));
		v[b].pb(mp(a, i));
	}
	if(root != -1) {
		dfs(root, 0);
		printf("%d\n", ss(res));
		for(auto it : res)
			printf("%d ", it);
		return 0;
	}
	if(odd & 1) {
		printf("-1");
		return 0;
	}
	solve(1, 0);
	printf("%d\n", ss(res));
	for(auto it : res)
		printf("%d ", it);
	
	
	
	return 0;
}