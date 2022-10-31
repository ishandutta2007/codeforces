#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define ll long long int
#define vi vector<int>
#define vii vector<vector<int> >
 
vii graph(100005,vi());
 
bool was[100005];
int goal[100005];
int invgoal[100005];
int cost = 0;
 
void dfs(int v) {
	was[v] = true;
	vector<int> tomove;
	for(int u : graph[v]) {
		if(!was[u]) {
			dfs(u);
			if(goal[u] == 0) {
				tomove.push_back(u);
			}
		}
	}
	if(tomove.size()) {
		cost+= tomove.size()*2;
		for(int i = 1; i < tomove.size(); i++) {
			goal[tomove[i-1]] = tomove[i];
			invgoal[tomove[i]] = tomove[i-1];
		}
		goal[tomove[tomove.size()-1]] = v;
		invgoal[v] = tomove[tomove.size()-1];
		goal[v] = tomove[0];
		invgoal[tomove[0]] = v;
	} else if(v == 1) {
		goal[1] = graph[1][0];
		goal[invgoal[graph[1][0]]] = 1;
		cost+= 2;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i < n; i++) {
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	cout << cost << "\n";
	for(int i = 1; i <= n; i++) {
		cout << goal[i] << " ";
	}
	return 0;
}