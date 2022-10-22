#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 10;

int n, p[MAXN];
bool mark[MAXN];
int ans = 0;
bool vis[MAXN];

void dfs(int v){
	if (vis[v])	return;
	vis[v] = 1;
	dfs(p[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;
	int cnt = 0;
	for (int i = 0; i < n; i++)	cin >> mark[i], cnt += mark[i];
	if (cnt % 2 == 0) ans++;
	cnt = 0;
	for (int i = 0; i < n; i++)
		if (!vis[i]){
			cnt++;
			dfs(i);
		}
	if (cnt > 1)
		ans += cnt;
	cout << ans << "\n";
	return 0;
}