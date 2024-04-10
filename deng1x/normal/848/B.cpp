#include <bits/stdc++.h>

#define MAXN (100010)

int n, w, h;

struct node{
	int g, x, y, t, id;
}dan[MAXN];

std::pair<int, int> ans[MAXN];

std::vector<node> vec[MAXN << 1];

bool cmpx(const node &a, const node &b){ return a.x > b.x; }
bool cmpy(const node &a, const node &b){ return a.y < b.y; }

void solve(std::vector<node> &vv){
	std::vector<node> vx;
	std::vector<node> vy;
	for(auto p : vv){
		if(p.g == 1) vx.push_back(p);
		else vy.push_back(p);
	}
	std::sort(vx.begin(), vx.end(), cmpx);
	std::sort(vy.begin(), vy.end(), cmpy);
	std::vector<std::pair<int, int> > tmp;
	for(auto p : vy){
		tmp.push_back({w, p.y});
	}
	for(auto p : vx){
		tmp.push_back({p.x, h});
	}
	int i = 0;
	for(auto p : vx){
		ans[p.id] = tmp[i ++];
	}
	for(auto p : vy){
		ans[p.id] = tmp[i ++];
	}
}

int main(){
	scanf("%d%d%d", &n, &w, &h);
	for(int i = 1; i <= n; ++ i){
		scanf("%d", &dan[i].g);
		dan[i].id = i;
		if(dan[i].g == 1){
			scanf("%d%d", &dan[i].x, &dan[i].t);
			vec[dan[i].x - dan[i].t + MAXN].push_back(dan[i]);
		}
		else{
			scanf("%d%d", &dan[i].y, &dan[i].t);
			vec[dan[i].y - dan[i].t + MAXN].push_back(dan[i]);
		}
	}
	
	for(int i = 0; i < MAXN + MAXN; ++ i){
		if(!vec[i].size()) continue;
		solve(vec[i]);
	}
	
	for(int i = 1; i <= n; ++ i){
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}