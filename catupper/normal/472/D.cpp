#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define INF (1LL << 60)
typedef long long Int;
Int dist[2160][2160];
Int ans[2160][2160];
Int d[2160];
Int dep[2160];
Int last[2160];
bool used[2160];
vector<Int> edge[2160];
vector<Int> dfs(Int x, Int last = -1){
	vector<Int> tmp, res;
	res.push_back(x);
	for(Int i = 0;i < edge[x].size();i++){
		Int to = edge[x][i];
		if(to == last)continue;
		dep[to] = dep[x] + dist[x][to];
		tmp = dfs(to, x);
		for(Int j = 0;j < res.size();j++){
			for(Int k = 0;k < tmp.size();k++){
				Int a = res[j], b = tmp[k];
				ans[b][a] = ans[a][b] = dep[a] + dep[b] - 2 * dep[x];
			}
		}
		for(Int k = 0;k < tmp.size();k++){
			res.push_back(tmp[k]);
		}
	}
	return res;
}

int main(){
	Int n;
	scanf("%lld", &n);
	for(Int i = 0;i < n;i++){
		for(Int j = 0;j < n;j++){
			scanf("%lld", &dist[i][j]);
			if(i == j && dist[i][j] != 0){
				cout << "NO" << endl;
				return 0;
			}
			if(i != j && dist[i][j] == 0){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	for(Int i = 0;i < n;i++){
		d[i] = INF;
		               
	}
	d[0] = 0;
	fill(last, last + 2160, -1);
	for(Int j = 0;j < n;j++){
		Int next = -1;
		for(int i = 0;i < n;i++){
			if(used[i])continue;
			if(next == -1 || d[i] < d[next])next = i;
		}
		used[next] = true;
		if(last[next] != -1){
			edge[next].push_back(last[next]);
			edge[last[next]].push_back(next);
		}
		for(int i = 0;i < n;i++){
			if(dist[next][i] < d[i]){
				last[i] = next;
				d[i] = dist[next][i];
			}
		}
	}
	dfs(0);
	
	for(Int i = 0;i < n;i++){
		for(Int j = 0;j < n;j++){
			if(ans[i][j] != dist[i][j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}