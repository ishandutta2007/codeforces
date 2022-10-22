#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6 + 10;

int n, par[MAXN], d[MAXN];
vector<pair<int, int>>	mx[MAXN];
int ans = 1;

void add(int u){
	d[u] = 1;
	int v = u;
	
	while (par[u] != 0){
		if (mx[par[u]].size() < 2){
			if (mx[par[u]].empty() || mx[par[u]].back().second != u)
				mx[par[u]].push_back({d[u], u});
			else
				mx[par[u]][0] = make_pair(d[u], u);

			if (mx[par[u]].size() == 2 && mx[par[u]][0].first < mx[par[u]][1].first)
				swap(mx[par[u]][0], mx[par[u]][1]);
		}
		else if (mx[par[u]][1].first < d[u]){
			if (mx[par[u]][0].second == u)
				mx[par[u]][0] = make_pair(d[u], u);
			else 
				mx[par[u]][1] = make_pair(d[u], u);

			if (mx[par[u]][0].first < mx[par[u]][1].first)	
				swap(mx[par[u]][0], mx[par[u]][1]);
		}

		int z = d[par[u]];
		if (mx[par[u]].size() == 2)
			d[par[u]] = max(mx[par[u]][0].first, mx[par[u]][1].first + 1);
		else
			d[par[u]] = mx[par[u]][0].first;

		if (d[par[u]] == z)	break;
		u = par[u];
		if (par[u] == 0)	ans = max(ans, d[u]);
	}
}

int main(){
	scanf("%d", &n);	n++;
	par[0] = -1;
	for (int i = 1; i < n; i++){
		scanf("%d", &par[i]);	par[i]--;
		add(i);
		printf("%d ", ans);
	}
	printf("\n");
	return	0;	
}