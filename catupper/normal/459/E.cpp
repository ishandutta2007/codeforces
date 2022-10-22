#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef pair<int, int > P;
int ans[324000];
int tmp[324000];
vector<P> edge[324000];
int n, m, u, v, w;

int main(){
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> u >> v >> w;
		edge[w].push_back(P(u, v));
	}
	for(int i = 0;i < 324000;i++){
		for(int j = 0;j < edge[i].size();j++){
			u = edge[i][j].first;
			v = edge[i][j].second;
			tmp[v] = max(tmp[v], ans[u] + 1);
		}
		for(int j = 0;j < edge[i].size();j++){
			u = edge[i][j].first;
			v = edge[i][j].second;
			ans[v] = max(ans[v], tmp[v]);
			tmp[v] = 0;
		}
	}
	int res = 0;         
	for(int i = 0;i < 324000;i++)res = max(res, ans[i]);
	cout << res << endl;
	
	return 0;
}