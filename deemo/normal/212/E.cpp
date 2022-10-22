//Has no one told you she's not breathing?
//Hello, I'm your mind giving you someone to talk to..
//Hello..

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

const int MAXN = 5e3 + 10;

int n, sz[MAXN], sec[3 * MAXN];
bool c[2][3 * MAXN], d[3 * MAXN];
vector<int>	adj[MAXN];

int dfs(int v, int p = -1){
	sz[v] = 1;
	for (int u:adj[v])
		if (u ^ p)
			sz[v] += dfs(u, v);
	return sz[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i < n; i++){
		memset(c, 0, sizeof(c));
		int t = 0;
		for (int u:adj[i])
			if (sz[u] < sz[i])
				sec[t++] = sz[u];
			else
				sec[t++] = n - sz[i];
		bool x = 0;
		c[x][MAXN] = 1;
		for (int j = 0; j < t; j++){
			fill(c[!x], c[!x] + 3 * MAXN, 0);
			for (int w = 0; w < 2 * MAXN; w++)
				if (c[x][w])
					c[!x][w + sec[j]] = c[!x][w - sec[j]] = 1;
			x = !x;
		}
		for (int w = 0; w < 2 * MAXN; w++)
			d[w] |= c[x][w];
	}
	int cnt = 0;
	for (int i = 0; i < 2 * MAXN; i++)
		if (d[i] && abs(i - MAXN) < n - 1)	cnt++;
	cout << cnt << "\n";
	for (int i = 0; i < 2 * MAXN; i++)
		if (d[i] && abs(i - MAXN) < n - 1){
			int temp = i - MAXN;
			int a = (n-1+temp)/2;
			int b = n - 1 - a;
			cout << a << " " << b << "\n";
		}

	return 0;
}