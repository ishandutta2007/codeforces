#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> T;
vector<int> edge[1080];
int dif[1080][1080];
bool used[1080];
int n, k, m, w, a, b;
vector<T> e;
char board[1080][11][11];
int r[1080];

int u(int x){
	if(r[x] == x)return x;
	return r[x] = u(r[x]);
}

void unite(int a, int b){
	a = u(a);
	b = u(b);
	r[a] = b;
}

void dfs(int x, int last = -1){
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i];
		if(to == last)continue;
		printf("%d %d\n", to + 1, x + 1);
		dfs(to, x);
	}
	used[x] = true;
}

int main(){
	for(int i = 0;i < 1080;i++)r[i] = i;
	scanf("%d%d%d%d", &n, &m, &k, &w);
	for(int i = 0;i < k;i++){
		for(int j = 0;j < n;j++){
			for(int l = 0;l < m;l++){
				scanf(" %c", &board[i][j][l]);
			}
		}
	}
	for(int i = 0;i < k;i++){
		for(int j = i + 1;j < k;j++){
			for(int l = 0;l < n;l++){
				for(int p = 0;p < m;p++){
					dif[i][j] += (board[i][l][p] != board[j][l][p]);
				}
			}
			e.push_back(T(dif[i][j], P(i, j)));
		}
	}

	sort(e.begin(), e.end());
	int res = n * m * k;
	for(int i = 0;i < e.size();i++){
		int a = e[i].second.first, b = e[i].second.second;
		int dist = e[i].first;
		if(dist * w >= n * m)break; 
		if(u(a) == u(b))continue;
		unite(a, b);
		res -= n * m;
		res += dist * w;
		edge[a].push_back(b);
		edge[b].push_back(a);		
	}	
	printf("%d\n", res);
	for(int i = 0;i < k;i++){
		if(used[i])continue;
		printf("%d 0\n", i + 1);
		dfs(i);
	}	
	return 0;
}