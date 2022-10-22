//And I will wander till the end of time..

#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

const int MAXN = 5e5 + 10;

int n, m, col[MAXN], h, t, sec[MAXN], g;
bool vis[MAXN];
set<pair<int, int>>	st;
set<int>	rem;
vector<int>	vec[MAXN];

pair<int, int>	get(int a, int b){return a<b?make_pair(a, b):make_pair(b, a);}

void dfs(int v){
	col[v] = g;
	vis[v] = 1;
	int tt = t;
	for (auto u:rem)
		if (!st.count(get(u, v)))	sec[t++] = u;
	while (tt < t)
		rem.erase(sec[tt++]);
	while (h < t)
		dfs(sec[h++]);
}

int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b;	scanf("%d %d", &a, &b);	a--, b--;
		st.insert(get(a, b));
	}
	for (int i = 0; i < n; i++)	rem.insert(i);
	for (int i = 0; i < n; i++){
		if (!vis[i])	rem.erase(i), dfs(i), g++;
		vec[col[i]].push_back(i);
	}

	printf("%d\n", g);
	for (int i = 0; i < g; i++){
		printf("%d ", (int)vec[i].size());
		for (auto v:vec[i])
			printf("%d ", v + 1);
		printf("\n");
	}
	return	0;
}