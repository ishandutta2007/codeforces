#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<utility>

using namespace std;

const int MAXN = 3e3 + 20;

int n, m, p[MAXN], xx;
bool vis[MAXN];
int col[MAXN], cnt[MAXN];
vector<pair<int, int>>	ans;

void dfs(int v, int g){
	if (vis[v])	return;
	col[v] = g;
	vis[v] = 1;
	cnt[g]++;
	dfs(p[v], g);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> p[i], p[i]--;
	cin >> m;	xx = n - m;
	
	bool working = 1;
	while (working){
		int g = 0;
		memset(vis, 0, sizeof(vis));
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0; i < n; i++)
			if (!vis[i])	dfs(i, g++);
		if (g == xx)	break;

		if (g > xx){
			for (int i = 1; i < n; i++)
				if (col[i] != col[0]){
					ans.push_back({0, i});
					swap(p[i], p[0]);
					break;
				}
			g--;
		}
		else{
			for (int i = 0; i < n; i++)
				if (cnt[col[i]] > 1){
					for (int j = i + 1; j < n; j++)
						if (col[i] == col[j]){
							ans.push_back({i, j});
							swap(p[i], p[j]);
							break;
						}
					break;
				}
			g++;
		}
		working = (g != xx);
	}
	cout << (int)ans.size() << "\n";
	for (pair<int, int>	v:ans)
		cout << v.first + 1 << " " << v.second + 1 << " ";
	cout << "\n";
	return	0;
}