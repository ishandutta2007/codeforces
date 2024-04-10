#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int max_n = 2e5;

int n, m;
vector<pair<int, int>>	adj[max_n];
vector<int>	sec[max_n];
int save[max_n], first[max_n];
bool mark[max_n];
set<pair<int, int>>	st;

void move(int v, int x){
	first[v] = x;
	for (int i = 0; i < sec[v].size(); i++)
		if (sec[v][i] == x)	x++;
	save[v] = x;
}

void update(int v){
	mark[v] = 1;
	for (int i = 0; i < adj[v].size(); i++){
		int u = adj[v][i].first, w = adj[v][i].second;
		if (mark[u])	continue;
		if (save[u] == -1 || save[u] > save[v] + w){
			st.erase({save[u], u});
			save[u] = save[v] + w;
			st.insert({save[u], u});
		}
	}
}

int find_min(){
	pair<int, int>	temp = *st.begin();
	st.erase(st.begin());
	return	temp.second;
}

void dijk(int v){
	fill(save, save + n, -1);
	save[v] = 0;
	move(v, save[v]);
	update(v);
	int mini = v;

	while (st.size()){
		mini = find_min();
		move(mini, save[mini]);
		update(mini);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		int a, b, c;	scanf("%d%d%d", &a, &b, &c);	a--, b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	
	for (int i = 0; i < n; i++){
		int t;	scanf("%d", &t);
		while(t--){
			int x;	scanf("%d", &x);
			sec[i].push_back(x);
		}
		sort(sec[i].begin(), sec[i].end());
	}
	dijk(0);
	if (save[n - 1] == -1){
		printf("-1\n");
		return 0;
	}
	printf("%d\n", first[n - 1]);
	return 0;
}