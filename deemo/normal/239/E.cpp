#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 3e3 + 10;

int n;
vector<int>	adj[MAXN], sadj[MAXN];
int d[MAXN], save[MAXN];

int dfs(int v, int p, int dir, int de = 0){
	if (dir == 1)
		save[v] = save[p];
	else
		save[v] = save[p] + 1;
	save[v] = min(save[v], d[p]);

	d[v] = d[p] + dir;

	int cnt = 0;
	for (int u:adj[v])
		if (u != p)
			cnt += dfs(u, v, 0, de + 1);

	for (int u:sadj[v])
		if (u != p){
			cnt += dfs(u, v, 1, de + 1) + 1;
		}
	return	cnt;
}

int get(int v){
	fill(d, d + MAXN, 0);
	fill(save, save + MAXN, 0);
	int cnt = 0;
	for (int u:adj[v])
		cnt += dfs(u, v, 0);
	for (int u:sadj[v])
		cnt += dfs(u, v, 1) + 1;

	int ret = cnt;
	for (int i = 0; i < n; i++)
		if (i != v)
			ret = min(ret, cnt - d[i] + save[i]);
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++){
		int a, b;	cin >> a >> b;	a--, b--;
		adj[a].push_back(b);
		sadj[b].push_back(a);
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++)
		ans = min(ans, get(i));
	cout << ans << endl;
	return 0;
}