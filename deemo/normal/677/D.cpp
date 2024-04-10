#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>

using namespace std;

#define F first
#define S second

const int MAXN = 300 + 5;

int n, m, p, c[MAXN][MAXN], d[MAXN][MAXN], lv[MAXN][MAXN];
vector<pair<int, int>>	vec[MAXN * MAXN], dir;
pair<int, int> q[MAXN * MAXN], sec[MAXN * MAXN];
bool vis[MAXN][MAXN];

bool cmp(pair<int, int> a, pair<int, int> b){return lv[a.F][a.S] < lv[b.F][b.S];}
bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m;}

void go(int id){
	while (id){
		int sz = vec[id].size();
		if (sz < n){
			for (auto x:vec[id])
				for (auto y:vec[id - 1])
					d[y.F][y.S] = min(d[y.F][y.S], d[x.F][x.S] + abs(x.F - y.F) + abs(x.S - y.S));
		}
		else{
			memset(lv, 63, sizeof(lv));
			memset(vis, 0, sizeof(vis));
			int h = 0, t = 0, cur = 0;	sz = 0;
			for (auto x:vec[id]){
				lv[x.F][x.S] = d[x.F][x.S];
				sec[sz++] = x;
			}
			sort(sec, sec + sz, cmp);
			while (cur < sz && lv[sec[cur].F][sec[cur].S] == lv[sec[0].F][sec[0].S])	q[t++] = sec[cur++];
			while (h < t){
				auto v = q[h++];
				for (auto g:dir)
					if (fit(v.F + g.F, v.S + g.S) && lv[v.F + g.F][v.S + g.S] > lv[v.F][v.S] + 1){
						vis[v.F + g.F][v.S + g.S] = 1;
						lv[v.F + g.F][v.S + g.S] = lv[v.F][v.S] + 1;
						q[t++] = {v.F + g.F, v.S + g.S};
						int xx = lv[v.F + g.F][v.S + g.S];
						while (cur < sz && (vis[sec[cur].F][sec[cur].S] || lv[sec[cur].F][sec[cur].S] == xx)){
							if (!vis[sec[cur].F][sec[cur].S])
								q[t++] = sec[cur];
							cur++;
						}
					}
			}
			for (auto y:vec[id - 1])
				d[y.F][y.S] = lv[y.F][y.S];
		}
		id--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	dir.push_back({-1, 0});
	dir.push_back({1, 0});
	dir.push_back({0, 1});
	dir.push_back({0, -1});
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j], c[i][j]--, vec[c[i][j]].push_back({i, j});
	memset(d, 63, sizeof(d));
	d[vec[p - 1].back().F][vec[p - 1].back().S] = 0;
	go(p-1);

	int ans = 1e9;
	for (auto x:vec[0])
		ans = min(ans, d[x.F][x.S] + x.F + x.S);
	cout << ans << endl;
	return 0;
}