#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;

int n, m, k, q;

vector <int> e[maxn];
vector <long long> w[maxn];

long long dis[maxn];
int fr[maxn];
bool vis[maxn];
int dep[maxn];

struct ex {
	int x, y;
	long long w;
};

int fa[maxn];
int f[maxn][21];
long long g[maxn][21];

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

int join(int x, int y){
	int ra = find(x);
	int rb = find(y);
	if(ra != rb){
		fa[rb] = ra;
	}
	return 0;
}

int dij(){
	int i, j;
	int x, y;
	long long z;
	
	priority_queue <pair <long long, int> > q;
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	
	for(i=1;i<=k;i++){
		dis[i] = 0;
		q.push(make_pair(0, i));
		fr[i] = i;
	}
	
	while(!q.empty()){
		x = q.top().second;
		q.pop();
		if(vis[x])continue;
		vis[x] = true;
		
		for(i=0;i<e[x].size();i++){
			y = e[x][i];
			z = w[x][i];
			if(dis[x] + z < dis[y]){
				dis[y] = dis[x] + z;
				q.push(make_pair(-dis[y], y));
				fr[y] = fr[x];
			}
		}
	}
	
	return 0;
}

bool cmp(ex x, ex y){
	return x.w < y.w;
}

int dfs(int x){
	int y;
	long long z;
	
	for(int i=0;f[x][i];i++){
		f[x][i + 1] = f[f[x][i]][i];
		g[x][i + 1] = max(g[x][i], g[f[x][i]][i]);
	}
	
	for(int i=0;i<e[x].size();i++){
		y = e[x][i];
		z = w[x][i];
		if(y == f[x][0])continue;
		
		f[y][0] = x;
		g[y][0] = z;
		dep[y] = dep[x] + 1;
		dfs(y);
	}
	
	return 0;
}

long long getans(int x, int y){
	long long ret = 0;
	int i, j;
	
	if(dep[x] < dep[y])swap(x, y);
	if(dep[x] > dep[y]){
		for(i=20;i>=0;i--){
			if(dep[x] - dep[y] >= (1 << i)){
				ret = max(ret, g[x][i]);
				x = f[x][i];
			}
		}
	}
	
	if(x == y)return ret;
	
	for(int i=20;i>=0;i--){
		if(f[x][i] != f[y][i]){
			ret = max(ret, max(g[x][i], g[y][i]));
			x = f[x][i];
			y = f[y][i];
		}
	}
	
	ret = max(ret, max(g[x][0], g[y][0]));
	
	return ret;
}

int main(){
	int i, j;
	int x, y;
	long long z;
	
	scanf("%d%d%d%d", &n, &m, &k, &q);
	
	for(i=1;i<=m;i++){
		scanf("%d%d%lld", &x, &y, &z);
		e[x].push_back(y);
		e[y].push_back(x);
		w[x].push_back(z);
		w[y].push_back(z);
	}
	for(i=1;i<=n;i++){
		fa[i] = i;
	}
	
	dij();
	
	vector <ex> vec;
	
	for(i=1;i<=n;i++){
		for(j=0;j<e[i].size();j++){
			y = e[i][j];
			z = w[i][j];
			vec.push_back({fr[i], fr[y], z + dis[i] + dis[y]});
			vec.push_back({fr[y], fr[i], z + dis[i] + dis[y]});
		}
	}
	
	sort(vec.begin(), vec.end(), cmp);
	
	for(i=1;i<=n;i++){
		e[i].clear();
		w[i].clear();
	}
	
	for(ex tmp : vec){
		if(find(tmp.x) != find(tmp.y)){
			e[tmp.x].push_back(tmp.y);
			e[tmp.y].push_back(tmp.x);
			w[tmp.x].push_back(tmp.w);
			w[tmp.y].push_back(tmp.w);
			join(tmp.x, tmp.y);
		}
	}
	
	dep[x] = 1;
	dfs(1);
	
	while(q--){
		scanf("%d%d", &x, &y);
		printf("%lld\n", getans(x, y));
	}
	
	return 0;
}