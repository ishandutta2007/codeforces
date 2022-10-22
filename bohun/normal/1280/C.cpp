#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

const int nax = 2e5 + 111;

int n;
vector <pair<int,int>> v[nax];
int a, b, c;

int siz[nax];

void dfs(int u, int p) {
	siz[u] = 1;
	for(auto it : v[u]) 
		if(it.fi != p) {
			dfs(it.fi, u);
			siz[u] += siz[it.fi];
		}
}

int daj(int u, int p) {
	for(auto it : v[u]) 
		if(it.fi != p && siz[it.fi] * 2 >= n)
			return daj(it.fi, u);
	return u;
}

ll c1, c2;

void go(int u, int p, ll h = 0) {
	c2 += h;
	for(auto it : v[u])
		if(it.fi != p)
			go(it.fi, u, h + it.se);
}

int be[nax];

void solve(int u, int p) {
	int ile = 1;
	for(auto it : v[u]) 
		if(it.fi != p) {
			solve(it.fi, u);
			if(be[it.fi]) {
				c1 += it.se;
				ile++;
			}
		}
	ile %= 2;
	if(ile) {
		be[u] = 1;
	}
}
	

void go() {
	c1 = c2 = 0;
	scanf("%d", &n);
	n *= 2;
	for(int i = 1; i <= n; ++i) {
		v[i].clear();
		be[i] = 0;
	}
	
	for(int i = 1; i < n; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].pb(mp(b, c));
		v[b].pb(mp(a, c));
	}
	
	dfs(1, 0);
	
	int centro = daj(1, 0);
	
	go(centro, 0);
	
	solve(1, 0);
	
	printf("%lld %lld\n", c1, c2);
}
	
	
	
	


int main() {
	int T;
	scanf("%d", &T);
	while(T--)
		go();
	
	return 0;
}