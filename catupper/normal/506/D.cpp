#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, int> T;

map<P, int> query;

vector<T> edges;
vector<P> edge[216000];
vector<P> color[216000];
int cnt[216000];
int res[216000];
int ans[216000];
int reach[216000];
bool done[216000];
int pp = 108000;
int a, b, n, m, c, ind, q;
void dfs(int x, int ind){
	if(done[x])return;
	done[x] = true;
	edges.push_back(T(P(ind, x), 105000));
	for(int i = 0;i < edge[x].size();i++){
		dfs(edge[x][i].first, ind);
	}
}

int main(){
	fill(reach, reach + 216000, -1);
	fill(done , done + 216000, true);
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> a >> b >> c;
		a--,b--,c--;
		color[c].push_back(P(a, b));
	}
	
	for(int i = 0;i < 216000;i++)done[i] = true;
	
	for(int i = 0;i < m;i++){
		for(int j = 0;j < color[i].size();j++){
			a = color[i][j].first;
			b = color[i][j].second;
			edge[a].push_back(P(b, 1));
			edge[b].push_back(P(a, 1));
			done[a] = false;
			done[b] = false;
		}
		for(int j = 0;j < color[i].size();j++){
			a = color[i][j].first;
			b = color[i][j].second;
			if(done[a])continue;
			dfs(a, ++pp);
		}
		for(int j = 0;j < color[i].size();j++){
			a = color[i][j].first;
			b = color[i][j].second;
			edge[a].clear();
			edge[b].clear();
		}
	}
	cin >> q;
	for(int i = 0;i < q;i++){
		cin >> a >> b;
		a--,b--;
		if(a > b)swap(a, b);
		if(query.count(P(a, b))){
			ans[i] = query[P(a, b)];
		}
		else{
			edges.push_back(T(P(a, b), i));
			ans[i] = i;
			query[P(a, b)] = i;
		}
	}
	
	for(int i = 0;i < edges.size();i++){
		a = edges[i].first.first;
		b = edges[i].first.second;
		cnt[a]++;
		cnt[b]++;
	}
		
	for(int i = 0;i < edges.size();i++){
		a = edges[i].first.first;
		b = edges[i].first.second;
		ind = edges[i].second;
		if(cnt[a] == cnt[b] && a > b)swap(a, b);
		if(cnt[a] > cnt[b])swap(a, b);
		edge[a].push_back(P(b, ind));
	}
	
	for(int i = 0;i < 216000;i++){
		for(int j = 0;j < edge[i].size();j++){
			int to = edge[i][j].first;
			int ind = edge[i][j].second;
			reach[to] = ind;
		}
		for(int j = 0;j < edge[i].size();j++){
			int to = edge[i][j].first;
			int tid = edge[i][j].second;
			for(int k = 0;k < edge[to].size();k++){
				int tt = edge[to][k].first;
				int ind = edge[to][k].second;
				if(reach[tt] != -1 && (i > 108000 || to > 108000 || tt > 108000)){
					res[ind]++;
					res[reach[tt]]++;
					res[tid]++;
				}
			}
		}                               
		for(int j = 0;j < edge[i].size();j++){
			int to = edge[i][j].first;
			int ind = edge[i][j].second;
			reach[to] = -1;
		}
	}
	for(int i = 0;i < q;i++){
		cout << res[ans[i]] << endl;
	}
	return 0;
}