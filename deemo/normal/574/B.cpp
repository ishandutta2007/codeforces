#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

#define pb(x) push_back(x)
const int max_n = 4000 + 30;

int n, m;
vector<int>	vec[max_n], sec;
bool adj[max_n][max_n];
bool mark[max_n];
int ans = 1e9 + 7;

int main(){
	scanf("%d%d", &n, &m);
	for (int i =0; i < m; i++){
		int a, b;	scanf("%d%d", &a, &b);	a--, b--;
		vec[a].pb(b);
		vec[b].pb(a);
		adj[a][b] = adj[b][a] = 1;
	}
	
	for (int i = 0 ; i < n; i++){
		sec.clear();
		for (int j = 0; j < vec[i].size(); j++){
			if (mark[vec[i][j]])	continue;
			sec.pb(vec[i][j]);
		}
		for (int j = 0; j < sec.size(); j++)
			for (int k = j + 1;k < sec.size(); k++){
				if (!adj[sec[j]][sec[k]])	continue;
				ans = min(ans, int(vec[i].size() + vec[sec[j]].size() + vec[sec[k]].size() - 6));
			}
		mark[i] = 1;
	}
	if (ans == 1e9 + 7)	printf("-1\n");
	else	printf("%d\n", ans);
	return	0;
}