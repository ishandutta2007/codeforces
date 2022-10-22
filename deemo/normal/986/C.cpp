#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 22;

int n, m;
bool mark[1<<MAXN], vis[1<<MAXN], gd[1<<MAXN];
int tt = (1<<MAXN)-1;

void dfs(int v);

void go(int mask){
	if (gd[mask]) return;
	gd[mask] = true;

	if (mark[mask]) dfs(mask);
	for (int w = 0; w < MAXN; w++)
		if (mask>>w&1)
			go(mask^1<<w);
}

void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;

	go(tt^v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--){
		int x; cin >> x;
		mark[x] = 1;
	}

	int ans = 0;
	for (int i = 0; i < 1<<n; i++)
		if (mark[i] && !vis[i]){
			ans++;
			dfs(i);
		}
	cout << ans << "\n";
	return 0;
}