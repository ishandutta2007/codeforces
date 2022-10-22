#include<bits/stdc++.h>
#define ll long long
#define pii std::pair <int, int>

ll inline sqr(int n){return 1ll * n * n;}

const int N = 1010;
const double PI = acos(-1);

std::vector <int> e[N];
std::pair <int, pii> p[N];
int n;
bool vis[N];
ll ans = 0;

void dfs(int u, int dep){
	ans += !dep || dep & 1 ? sqr(p[u].first) : -sqr(p[u].first);
	for (auto v : e[u]){
		dfs(v, dep + 1);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 0, x, y, r; i < n; ++ i){
		scanf("%d%d%d", &x, &y, &r);
		p[i] = {r, {x, y}};
	}
	std::sort(p, p + n);
	for (int i = 0; i < n; ++ i){
		for (int j = i + 1; j < n; ++ j){
			if (sqr(p[i].second.second - p[j].second.second) + sqr(p[i].second.first - p[j].second.first) <= sqr(p[j].first - p[i].first)){
				e[j].push_back(i);
				vis[i] = true;
				break;
			}
		}
	}
	for (int i = 0; i < n; ++ i){
		if (!vis[i]){
			dfs(i, 0);
		}
	}
	return printf("%.10lf", ans * PI), 0;
}