#include<bits/stdc++.h>
#include<ctime>
#include<random>
using namespace std;

int bipartiteMatching(const vector<vector<int> > &g) {  //g: left side
	int nleft = g.size(), nright = 0;
	for (auto es = g.begin(); es != g.end(); es++) if (!es->empty()) nright = max(nright, *max_element(es->begin(), es->end()) + 1);
	vector<int> matchL(nleft, -1), matchR(nright, -1), prev(nleft), seen(nleft, -1);
	for (int i = 0; i < nleft; i++) {
		vector<int> stk; stk.push_back(i);
		seen[i] = i; prev[i] = -1;
		while (!stk.empty()) {
			int v = stk.back(); stk.pop_back();
			for (auto ui = g[v].begin(); ui != g[v].end(); ui++) {
				int u = *ui;
				int j = matchR[u];
				if (j == -1) {
					while (v != -1) {
						matchR[u] = v;
						swap(u, matchL[v]);
						v = prev[v];
					}
					goto break_;
				}
				else if (seen[j] < i) {
					seen[j] = i; prev[j] = v;
					stk.push_back(j);
				}
			}
		}
	break_:;
	}
	return (int)matchL.size() - count(matchL.begin(), matchL.end(), -1);
}

int v;
int e;
int n;
int k;

vector<int> star;

long long int dist[602][602];

#define MAX 602


vector<pair<int, int> > vv[MAX];
void bfs(int b){
	for (int i = 0; i < v; i++){
		dist[b][i] = INT_MAX;
	}
	dist[b][b] = 0;
	queue<int> q;
	q.push(b);
	while (!q.empty()){
		int f = q.front();
		q.pop();
		for (int i = 0; i < vv[f].size(); i++){
			int go = vv[f][i].first;
			int tim = vv[f][i].second;
			if (dist[b][go] > dist[b][f] + tim){
				dist[b][go] = dist[b][f] + tim;
				q.push(go);
			}
		}
	}
}

vector<vector<int> > v2;
bool ok(int mid){
	v2.assign(n, vector<int>());
	for (int i = 0; i < n; i++){
		for (int j = 0; j < v; j++){
			if (dist[star[i]][j] <= mid){
				v2[i].push_back(j);
			}
		}
	}
	return bipartiteMatching(v2) >= k;
}
int main(){
	cin >> v >> e >> n>>k;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		a--;
		star.push_back(a);
	}
	for (int i = 0; i < e; i++){
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		a--;
		b--;
		vv[a].push_back(make_pair(b, t));
		vv[b].push_back(make_pair(a, t));
	}
	for (int i = 0; i < v; i++){
		bfs(i);
	}
	int mint = 0;
	int maxt = 1731311;
	if (!ok(maxt)){
		puts("-1");
		return 0;
	}
	while (mint + 1 < maxt){
		int mid = (mint + maxt) >> 1;
		if (ok(mid)){
			maxt = mid;
		}
		else{
			mint = mid;
		}
	}
	if (mint!=maxt&&ok(mint)){
		cout << mint << endl;
	}
	else{
		cout << maxt << endl;
	}
	return 0;
}