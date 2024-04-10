//my insides all turned to ash, so slow..

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>
#include<utility>

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 1e5 + 10;

int x, y, m, cc[2 * MAXN], ans;
vector<int>	adj[2 * MAXN];
int from[MAXM], to[MAXM], col[MAXM];
bool m1[MAXN], m2[MAXN];

void dfs(int v, int c, int d){
	for (auto e:adj[v])
		if (col[e] == c){
			int u = to[e];
			if (u == v)	u = from[e];
			dfs(u, d, c);
			col[e] = d;
			return;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y >> m;
	for (int i = 0; i < m; i++){
		cin >> from[i] >> to[i];	from[i]--, to[i]--;	to[i] += x;
		cc[from[i]]++, cc[to[i]]++;
		ans = max(ans, cc[from[i]]);
		ans = max(ans, cc[to[i]]);
	}	
	cout << ans << "\n";

	for (int i = 0; i < m; i++){
		int a = from[i], b = to[i];
		memset(m1, 0, sizeof(m1));
		memset(m2, 0, sizeof(m2));
		for (int e:adj[a])	m1[col[e]] = 1;
		for (int e:adj[b])	m2[col[e]] = 1;
	
		for (int j = 1; j <= ans; j++)
			if (!m1[j] && !m2[j]){
				col[i] = j;
				break;
			}

		if (col[i] == 0){
			int c = -1, d = -1;
			for (int j = 1; j <= ans; j++)
				if (m1[j] && !m2[j])	c = j;
				else if (!m1[j] && m2[j])	d = j;
			dfs(a, c, d);
			col[i] = c;
		}

		adj[a].push_back(i);
		adj[b].push_back(i);
	}
	for (int i = 0; i < m; i++)
		cout << col[i] << " ";
	cout << "\n";
	return	0;		
}