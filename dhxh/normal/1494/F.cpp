#include <bits/stdc++.h>

using namespace std;

const int maxn = 3000 + 5;

int n, m;

vector <pair <int, int> > e[maxn];
int enow[maxn];

bool vis[maxn * maxn];
bool d[maxn];
int ecnt[maxn];

vector <int> p[maxn];

int fa[maxn];

int find(int x){
	if(fa[x] != x){
		fa[x] = find(fa[x]);
	}
	return fa[x];
}

void join(int x, int y){
	int ra = find(x), rb = find(y);
	if(ra != rb){
		fa[ra] = rb;
	}
}

void dfs(int x, vector <int> &v){
	v.push_back(x);
	for(int &i=enow[x];i<e[x].size();i++){
		auto [y, j] = e[x][i];
		if(vis[j]) continue;
		vis[j] = true;
		dfs(y, v);
		break;
	}
}

vector <int> find(int u, int v){
	deque <int> q;
	vector <int> ans;
	dfs(u, p[u]);
	for(auto x : p[u]) q.push_back(x);
	p[u].clear();
	
	while(q.size()){
		int x = q.front();
		q.pop_front();
		dfs(x, p[x]);
		if(p[x].size() > 1){
			reverse(p[x].begin(), p[x].end());
			for(auto y : p[x]){
				q.push_front(y);
			}
		}else{
			ans.push_back(x);
		}
		p[x].clear();
	}
	
	return ans;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=m;i++){
		scanf("%d%d", &x, &y);
		e[x].push_back({y, i});
		e[y].push_back({x, i});
		ecnt[x]++;
		ecnt[y]++;
	}
	
	vector <int> v;
	
	for(i=1;i<=n;i++){
		if(ecnt[i] & 1) v.push_back(i);
	}
	
	vector <int> ans;
	
	if(v.size() == 0){
		ans = find(1, 1);
	}else if(v.size() == 2){
		ans = find(v[0], v[1]);
	}else{
		for(x=1;x<=n;x++){
			int ec = m;
			for(auto [y, j] : e[x]){
				if(ecnt[y] & 1){
					ecnt[y]--;
					ecnt[x]--;
					vis[j] = true;
					d[y] = true;
					ec--;
				}
			}
			
			vector <int> v;
		
			for(i=1;i<=n;i++){
				if(ecnt[i] & 1) v.push_back(i);
			}
			
			if(v.size() == 0){
				for(i=1;i<=n;i++) fa[i] = i;
				for(i=1;i<=n;i++){
					for(auto [y, j] : e[i]){
						if(!vis[j]) join(i, y);
					}
				}
				for(auto [y, j] : e[x]){
					if(ecnt[y] and find(x) != find(y)){
						v.push_back(x);
						v.push_back(y);
						ecnt[y]++;
						ecnt[x]++;
						vis[j] = false;
						d[y] = false;
						ec++;
						break;
					}
				}
				
				if(ecnt[x] == 0 and v.size() == 0){
					for(auto [y, j] : e[x]){
						if(ecnt[y]){
							v.push_back(x);
							v.push_back(y);
							ecnt[y]++;
							ecnt[x]++;
							vis[j] = false;
							d[y] = false;
							ec++;
							break;
						}
					}
				}
			}
			
			if(v.size() == 0){
				ans = find(x, x);
			
				if(ans.size() != ec + 1){
					ans.clear();
					
					for(auto [y, j] : e[x]){
						if(d[y]){
							vis[j] = false;
							d[y] = false;
							ecnt[y]++;
							ecnt[x]++;
						}
					}
					for(i=1;i<=n;i++){
						for(int &j=enow[i];j>0;j--){
							if(j > e[i].size()) continue;
							vis[e[i][j - 1].second] = false;
						}
					}
					continue;
				}
				ans.push_back(-1);
				for(auto [y, j] : e[x]){
					if(!d[y]) continue;
					ans.push_back(y);
					ans.push_back(x);
				}
				break;
			}else if(v.size() == 2){
				if(v[0] != x and v[1] != x){
					for(auto [y, j] : e[x]){
						if(d[y]){
							vis[j] = false;
							d[y] = false;
							ecnt[y]++;
							ecnt[x]++;
						}
					}
					continue;
				}
				
				ans = find(v[0] == x ? v[1] : v[0], x);
				
				if(ans.size() != ec + 1){
					ans.clear();
					
					for(auto [y, j] : e[x]){
						if(d[y]){
							vis[j] = false;
							d[y] = false;
							ecnt[y]++;
							ecnt[x]++;
						}
					}
					for(i=1;i<=n;i++){
						for(int &j=enow[i];j>0;j--){
							if(j > e[i].size()) continue;
							vis[e[i][j - 1].second] = false;
						}
					}
					continue;
				}
				
				ans.push_back(-1);
				for(auto [y, j] : e[x]){
					if(!d[y]) continue;
					ans.push_back(y);
					ans.push_back(x);
				}
				
				break;
			}else{
				for(auto [y, j] : e[x]){
					if(d[y]){
						vis[j] = false;
						d[y] = false;
						ecnt[y]++;
						ecnt[x]++;
					}
				}
			}
		}
	}
	
	printf("%d\n", ans.size());
	
	if(ans.size()){
		for(auto x : ans){
			printf("%d ", x);
		}
		printf("\n");
	}
	
	return 0;
}