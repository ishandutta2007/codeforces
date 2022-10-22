#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define ld double
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)
#define DOW(i, n) for(int i = n - 1; 0 <= i; --i)
#define boost cin.tie(0), ios_base::sync_with_stdio(0);


using namespace std;

const int nax = 5e5 + 111;

struct dwasat {
	// 2 * i - normal
	// 2 * i + 1 negacja
	// numeracja od 0 
	vector <int> v[nax], rev[nax];
	vector <int> order;
	bool odw[nax];
	int com[nax];
	bool roz[nax];
	
	void add(int x, int y) { 
		v[x ^ 1].pb(y);
		rev[y].pb(x ^ 1);
		v[y ^ 1].pb(x);
		rev[x].pb(y ^ 1);
	}	
	
	void dfs1(int u) {
		odw[u] = 1;
		for (auto it : v[u])
			if (!odw[it]) dfs1(it);
		order.pb(u);
	}
	
	void dfs2(int u, int id) {
		com[u] = id;
		for (auto it : rev[u])
			if (com[it] == 0) dfs2(it, id);
	}
		
	bool solve(int n) { // daj liczbe zmiennych
		for (int i = 0; i < 2 * n; ++i) {
			odw[i] = 0;
			com[i] = 0;
		}
		order.clear();
		for (int i = 0; i < 2 * n; ++i) 
			if (!odw[i]) dfs1(i);
		for (int i = 0; i < 2 * n; ++i)
			if (!com[order[2 * n - i - 1]]) 
				dfs2(order[2 * n - i - 1], i + 1);
		
		for (int i = 0; i < 2 * n; i += 2) {
			if(com[i] == com[i ^ 1])
				return false;
			roz[i / 2] = (com[i + 1] < com[i]);
		}
		return true;
	}
} ja;
	
int n, m;
int a;
vector <int> x[nax];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a);
		for (int j = 1; j <= a; ++j) {
			int b;
			scanf("%d", &b);
			x[i].pb(b);
		}
	}
	
	for (int i = 0; i + 1 < n; ++i) {
		int j = 0;
		while(j < ss(x[i]) && j < ss(x[i + 1]) && x[i][j] == x[i + 1][j]) j++;
		
		if ((j == ss(x[i]) && j < ss(x[i + 1])) || (j == ss(x[i]) && j == ss(x[i + 1]))) 
			continue;
		if ((j == ss(x[i + 1]) && j < ss(x[i]))) {
			printf("No\n");
			return 0;
		}
		int y = x[i][j] - 1;
		int z = x[i + 1][j] - 1;
		
		if(y < z) 
			ja.add(2 * y, 2 * z + 1);
		else {
			ja.add(2 * y, 2 * y);
			ja.add(2 * z + 1, 2 * z + 1);
		}
	}
	
	if(ja.solve(m) == 0) {
		printf("No\n");
		return 0;
	}
	vector <int> r;
	for (int i = 0; i < m; ++i) 
		if (ja.roz[i] == 1) r.pb(i + 1);
	printf("Yes\n");
	printf("%d\n", ss(r));
	for (auto it : r)
		printf("%d ", it);
	
	
	return 0;
}