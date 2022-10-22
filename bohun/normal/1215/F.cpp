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
#define bignum vector <int>
 
 
using namespace std;
const int nax = 2e6 + 11;

int n, p, M, m, a, b;
vector <int> v[nax], rev[nax], Post;
bool odw[nax];
int com[nax];
int counter = 0;
int l, r;

void add(int x, int y) {
	v[(x ^ 1)].pb(y);
	v[(y ^ 1)].pb(x);
}

void dfs1(int u) {
	odw[u] = 1;
	for(auto it: v[u])
		if(!odw[it])
			dfs1(it);
	Post.pb(u);
}

void dfs2(int u) {
	com[u] = counter;
	odw[u] = 1;
	for(auto it: rev[u])
		if(!odw[it])
			dfs2(it);
}

int main() {
	cin >> p >> n >> M >> m;
	FOR(i, 1, p) {
		cin >> a >> b;
		add(2 * a, 2 * b);
	}
	int c = 2 * n;
	int MAX = M * 2 + 2 * n + 1;
	FOR(i, 1, M - 1) {
		add(c + 2 * i, c + 2 * (i + 1) + 1);
	}
	FOR(i, 1, n) {
		cin >> l >> r;
		add(2 * i + 1, c + 2 * l);
		add(2 * i + 1, c + 2 * (r + 1) + 1);
	}
	FOR(i, 1, m) {
		cin >> a >> b;
		add(2 * a + 1, 2 * b + 1);
	}
	
	FOR(i, 1, MAX) 
		if(!odw[i])
			dfs1(i);
	
	reverse(Post.begin(), Post.end());
	
	FOR(i, 1, MAX) {
		odw[i] = 0;
	}
	
	FOR(i, 1, MAX)
		for(auto it: v[i])
			rev[it].pb(i);
	
	for(auto it: Post) 
		if(!odw[it]) {
			counter += 1;
			dfs2(it);
		}
	
	
	int odp = 0;
	vector <int> res;
	FOR(i, 1, MAX) {
		if(com[i] == com[(i ^ 1)]) {
			cout << -1;
			return 0;
		}
		if(i <= 2 * n && i % 2 == 0 && com[i] > com[i + 1])
			res.pb(i);
		if(i > c && i % 2 == 0 && com[i] > com[i + 1])
			odp = max(odp, (i - c) / 2);
	}
	
	cout << ss(res) << " " << odp << endl;
	for(auto it: res)
		cout << it / 2 << " ";
		
			
		
		
	
	
	
		
	
	
	
	return 0;
}