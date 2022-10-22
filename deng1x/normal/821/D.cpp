#include <bits/stdc++.h>

#define MAXN (100010)
#define ll long long

int n, m, k;
std::vector<std::pair<int, int> > vec[MAXN];
ll dis[MAXN];
std::map<std::pair<int, int>, int> map;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	
int idr(int r){
	return k + r;
}

int idc(int c){
	return k + n + c;
}

void Dijkstra(int s, int n){
	std::set<std::pair<ll, int> > set;
	for(int i = 1; i <= n; ++ i) dis[i] = (1ll << 60);
	dis[s] = 0;
	for(int i = 1; i <= n; ++ i) set.insert({dis[i], i});
	for(int i = 1; i <= n; ++ i){
		int u = set.begin() -> second;
		set.erase(set.begin());
		for(auto p : vec[u]){
			int v = p.first, w = p.second;
			if(dis[v] > dis[u] + w){
				set.erase({dis[v], v});
				dis[v] = dis[u] + w;
				set.insert({dis[v], v});
			}
		}
	}
}

void addedge(int u, int v, int w){
	vec[u].push_back({v, w});
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	bool mark = false;
	for(int i = 1; i <= k; ++ i){
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(i, idr(x), 1), addedge(idr(x), i, 0);
		addedge(i, idc(y), 1), addedge(idc(y), i, 0);
		if(x - 1 >= 1) addedge(i, idr(x - 1), 1), addedge(idr(x - 1), i, 0);
		if(x + 1 <= n) addedge(i, idr(x + 1), 1), addedge(idr(x + 1), i, 0);
		if(y - 1 >= 1) addedge(i, idc(y - 1), 1), addedge(idc(y - 1), i, 0);
		if(y + 1 <= m) addedge(i, idc(y + 1), 1), addedge(idc(y + 1), i, 0);
		
		for(int t = 0; t < 4; ++ t){
			int dx = x + dir[t][0];
			int dy = y + dir[t][1];
			if(!(1 <= dx && dx <= n && 1 <= dy && dy <= m)) continue;
			if(!map[{dx, dy}]) continue;
			int v = map[{dx, dy}];
			addedge(i, v, 0);
			addedge(v, i, 0);
		}
		
		map[{x, y}] = i;
	}
	Dijkstra(1, n + m + k);
	if(map[{n, m}]){
		ll ans = dis[map[{n, m}]];
		ans = ans == (1ll << 60) ? -1 : ans;
		printf("%I64d\n", ans);
	}
	else{
		ll ans = std::min(dis[idr(n)], dis[idc(m)]);
		ans = ans == (1ll << 60) ? -1 : ans;
		printf("%I64d\n", ans);
	}
	return 0;
}