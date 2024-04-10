#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;

int n, m, t;

long long dis[maxn];
vector <pair <int, int> > e[maxn];

int main(){
	int i, j;
	int x, y, w;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=m;i++){
		scanf("%d%d%d", &x, &y, &w);
		e[x].push_back({y, w});
		e[y].push_back({x, w});
		e[x + n].push_back({y + n, w});
		e[y + n].push_back({x + n, w});
		e[x + 2 * n].push_back({y + 2 * n, w});
		e[y + 2 * n].push_back({x + 2 * n, w});
		e[x + 3 * n].push_back({y + 3 * n, w});
		e[y + 3 * n].push_back({x + 3 * n, w});
		
		e[x].push_back({y + n, w * 2});
		e[y].push_back({x + n, w * 2});
		e[x].push_back({y + 2 * n, 0});
		e[y].push_back({x + 2 * n, 0});
		e[x + n].push_back({y + 3 * n, 0});
		e[y + n].push_back({x + 3 * n, 0});
		e[x + 2 * n].push_back({y + 3 * n, w * 2});
		e[y + 2 * n].push_back({x + 3 * n, w * 2});
	}
	
	memset(dis, 0x3f, sizeof(dis));
	priority_queue <pair <long long, int> > q;
	dis[1] = 0;
	q.push({0, 1});
	
	while(q.size()){
		x = q.top().second;
		if(dis[x] != -q.top().first){
			q.pop();
			continue;
		}
		q.pop();
		
		for(auto [y, w] : e[x]){
			if(dis[y] > dis[x] + w){
				dis[y] = dis[x] + w;
				q.push({-dis[y], y});
			}
		}
	}
	
	for(auto [y, w] : e[1]){
		dis[y + 3 * n] = min(dis[y + 3 * n], (long long)w);
	}
	
	for(i=2;i<=n;i++){
		printf("%lld ", dis[i + 3 * n]);
	}
	printf("\n");
	
	return 0;
}