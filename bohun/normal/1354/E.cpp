#include <bits/stdc++.h>
#define ll long long
#define ld long double
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
	
const int N = 5005;	
	
int n, m, n1, n2, n3, a, b;

vector <int> g[N];

int color[N];
int cnt[3];

int q;
int node[N];
int w[N];
int dod[N];

void dfs(int v) {
	cnt[color[v]]++;
	for (auto it : g[v]) {
		if (color[it] == 0) {
			color[it] = (color[v] == 1 ? 2 : 1);
			dfs(it);
		}
		if (color[it] == color[v]) {
			printf ("NO\n");
			exit(0);
		}
	}
}

bool dp[N][N];
bool biore[N][N];	

int ans[N];

void solve(int v, int k) {
	if (color[v] == k) ans[v] = 2;
	for (auto it : g[v]) {
		if (color[it] == 0) {
			color[it] = (color[v] == 1 ? 2 : 1);
			solve(it, k);
		}
	}
}
	

int main() {
	scanf ("%d%d%d%d%d", &n, &m, &n1, &n2, &n3);
	rep(i, 1, m) {
		scanf ("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	
	int S = 0;
	
	rep(i, 1, n) 
		if (color[i] == 0) {
			color[i] = 1;
			cnt[1] = cnt[2] = 0;
			dfs(i);
			++q;
			node[q] = i;
			dod[q] = max(cnt[1], cnt[2]) - min(cnt[1], cnt[2]);
			S += min(cnt[1], cnt[2]);
			w[q] = cnt[1] > cnt[2]; 
		}
	dp[0][0] = 1;
	rep(i, 1, q) {
		rep(j, 0, n) {
			if (dp[i - 1][j] == true) {
				biore[i][j] = false;
				dp[i][j] = true;
			}
			if (j >= dod[i] && dp[i - 1][j - dod[i]] == true) {
				biore[i][j] = true;
				dp[i][j] = true;
			}
		}
	}
	
	int need = n2 - S;
	if (need < 0 || dp[q][need] == false) {
		printf ("NO\n");
		return 0;
	}
	
	rep(i, 1, n) color[i] = 0;
	
	per(i, 1, q) {
		if (biore[i][need]) {
			color[node[i]] = 1;
			solve(node[i], (w[i] == 1 ? 1 : 2));
			need -= dod[i];
		}
		else {
			color[node[i]] = 1;
			solve(node[i], (w[i] == 1 ? 2 : 1));
		}
	}
	printf ("YES\n");
	rep(i, 1, n) {
		if (ans[i] == 2) 
			printf ("2");
		else {
			if (n1 > 0) {
				n1--;
				printf ("1");
			}
			else printf ("3");
		}
	}
			
	return 0;
}