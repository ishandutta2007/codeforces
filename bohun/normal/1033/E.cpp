#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;	

const int N = 611;

int n;
vector <int> g[N];
int color[N];

void addedge(int u, int v) {
	g[u].pb(v);
	g[v].pb(u);
}

int ask(vector <int> x, char c) {
	if (c == '?' && ss(x) <= 1)	 return 0;
	printf ("%c %d\n", c, ss(x));
	for (auto it : x) 
		printf ("%d ", it);
	printf ("\n");
	fflush(stdout);
	if (c == '?') {
		int a;
		scanf ("%d", &a);
		return a;
	}
	return -1;
}

int kto[N];
int dep[N];
bool vis[N];

void dfs(int v) {
	vis[v] = true;
	kto[dep[v]] = v;
	for (auto it : g[v]) {
		if (vis[it] && color[v] == color[it]) {
			vector <int> ans;
			rep(i, dep[it], dep[v])
				ans.pb(kto[i]);
			ask(ans, 'N');
			exit(0);
		}
		if (!vis[it]) {
			dep[it] = dep[v] + 1;
			dfs(it);
		}
	}
}
	
vector <int> nowi;

int szukaj(int v, vector <int> x) {
	vector <int> L, R;
	rep(i, 0, ss(x) - 1) {
		if (i & 1) L.pb(x[i]);
		else R.pb(x[i]);
	}
	
	int now = -ask(x, '?');
	x.pb(v);
	now += ask(x, '?');
	
	if (!now) return now;
	
	if (ss(x) == 2) {
		addedge(v, x[0]);
		if (color[v] == color[x[0]]) 
			dfs(v);
		nowi.pb(x[0]);
		color[x[0]] = color[v] ^ 1;
		return now;
	}
	
	int mam = 0;
	
	if (rand() % 2) swap(L, R);
	
	mam += szukaj(v, L);
	
	if (mam == now) return now;
	
	mam += szukaj(v, R);
	
	return now;
}
	

int main() {
	scanf ("%d", &n);
	rep(i, 1, n) color[i] = -1;
	queue <int> Q;
	Q.push(1);
	color[1] = 0;
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		vector <int> W;
		rep(i, 1, n)
			if (i != v && (color[i] == color[v] || color[i] == -1))
				W.pb(i);
		random_shuffle(all(W));
		nowi.clear();
		szukaj(v, W);
		for (auto it : nowi)
			Q.push(it);
	}
	
	vector <int> ans;
	rep(i, 1, n)
		if (!color[i])
			ans.pb(i);
	ask(ans, 'Y');
	
	return 0;
}