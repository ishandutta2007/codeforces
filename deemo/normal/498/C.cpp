//Just a little bit of your heart..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<cstring>

using namespace std;

typedef long long ll;

const int INF = 1e9 + 5;
const int MAXN = 300 + 5;
const int MAXE = 200 * 200 * 10 + 5;

int n, m, ec;
int a[MAXN];
int from[2 * MAXE], to[2 * MAXE], cap[2 * MAXE], prv[2 * MAXE];
int head[MAXN];
vector<int>	vec[MAXN], sec;
map<int, int>	cnt[MAXN];
bool mark[MAXN];

void init(){
	for (int i = 0; i < n; i++){
		ll temp = a[i];
		for (ll j = 2; j * j <= temp; j++){
			while (temp % j == 0){
				temp /= j;
				vec[i].push_back(j);
				cnt[i][j]++;
				sec.push_back(j);
			}
		}
		if (temp > 1){
			vec[i].push_back(temp);
			cnt[i][temp]++;
			sec.push_back(temp);
		}
		sort(vec[i].begin(), vec[i].end());
		vec[i].resize(unique(vec[i].begin(), vec[i].end()) - vec[i].begin());
	}
	sort(sec.begin(), sec.end());
	sec.resize(unique(sec.begin(), sec.end()) - sec.begin());
}

void add_edge(int u, int v, int uv, int vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v];	head[v] = ec++;
}

int dfs(int v, int sink, int mini = INF){
	if (sink == v)	return	mini;
	if (mark[v])	return	0;
	mark[v] = 1;
	for (int e = head[v]; e != -1; e = prv[e])
		if (cap[e]){
			int x = dfs(to[e], sink, min(mini, cap[e]));
			if (x == 0)	continue;
			cap[e] -= x;
			cap[e ^ 1] += x;
			return	x;
		}
	return 0;
}

int max_flow(int root, int sink){
	memset(mark, 0, sizeof(mark));
	int ret = 0, x;
	while ((x = dfs(root, sink))){
		ret += x;
		memset(mark, 0, sizeof(mark));
	}
	return	ret;
}

vector<pair<int, int>>	ed;
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)	cin >> a[i];
	init();
	while (m--){
		int u, v;	cin >> u >> v;	u--, v--;
		if (u % 2 == 1)	swap(u, v);
		ed.push_back({u, v});
	}

	int ans = 0;
	for (int x:sec){
		memset(head, -1, sizeof(head));
		ec = 0;
		for (pair<int, int>	e:ed)
			if (cnt[e.first].count(x) && cnt[e.second].count(x))
				add_edge(e.first, e.second, min(cnt[e.first][x], cnt[e.second][x]));
		
		for (int i = 0; i < n; i += 2)
			if (cnt[i].count(x))
				add_edge(n, i, cnt[i][x]);
		for (int i = 1; i < n; i += 2)
			if (cnt[i].count(x))
				add_edge(i, n + 1, cnt[i][x]);
		ans += max_flow(n, n + 1);
	}
	cout << ans << endl;
	return 0;
}