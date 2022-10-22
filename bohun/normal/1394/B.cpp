#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
#define cat(x) cerr << #x << " = " << x << endl
#define ull unsigned long long
 
using namespace std;	

const int N = 2e5 + 101;

int n, m, k;
vector <pair<int, int>> G[N];
vector <int> nodes[10][10];
bool bad[10][10];
ull lol[10][10];

ull ran() {
	ull res = 0;
	rep(i, 0, 50)
		res = res * 2 + rand() % 2;
	return res;
}
ull w[N], all;
int out;

void brute(int x, ull hasz) {
	if (x == k + 1) {
		out += all == hasz;
		return;
	}
	rep(i, 1, x)
		brute(x + 1, hasz + lol[x][i]);
}
		

int main() {
	srand(2137);
	scanf ("%d%d%d", &n, &m, &k);
	rep(i, 1, m) {
		int u, v, w;
		scanf ("%d%d%d", &u, &v, &w);
		G[u].pb(mp(w, v));
	}
	rep(i, 1, n) {
		sort(all(G[i])), w[i] = ran();
		all += w[i];
		int sz = ss(G[i]);
		rep(j, 0, sz - 1) {
			nodes[sz][j + 1].pb(G[i][j].se);
		}
	}
	
	rep(i, 1, k)
		rep(j, 1, k) 
			for (auto x : nodes[i][j])
				lol[i][j] += w[x];
	
	brute(1, 0);
	printf ("%d\n", out);
	
	return 0;
}