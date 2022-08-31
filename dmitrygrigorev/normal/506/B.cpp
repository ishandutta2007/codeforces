using namespace std;
#include <bits/stdc++.h>
vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;
 
void dfs1 (int v) {
	used[v] = true;
	for (size_t i=0; i<g[v].size(); ++i)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) {
	used[v] = true;
	component.push_back (v);
	for (size_t i=0; i<gr[v].size(); ++i)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}
vector<bool> bad;
vector<bool> zap;
int ans=0;
void dfs3(int vertex){
    zap[vertex] = true, bad[vertex] = true;
    ans++;
    for (int i=0;i<g[vertex].size();i++){
        int to = g[vertex][i];
        if (zap[to]) continue;
        dfs3(to);
    }
    for (int i=0;i<gr[vertex].size();i++){
        int to = gr[vertex][i];
        if (zap[to]) continue;
        dfs3(to);
    }
}
int main() {
	int n, m;
	cin >> n >> m;
	g.resize(n), gr.resize(n);
	for (int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		a--,b--;
		g[a].push_back (b);
		gr[b].push_back (a);
	}
 
	used.assign (n, false);
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs1 (i);
	used.assign (n, false);
	bad.resize(n, false);
	for (int i=0; i<n; ++i) {
		int v = order[n-1-i];
		if (!used[v]) {
			dfs2 (v);
			//for (int j=0;j<component.size();j++) cout << component[j] << " ";
			//cout << endl;
			if (component.size() > 1){
			    for (int j=0;j<component.size();j++) bad[component[j]] = true;
			}
			component.clear();
		}
	}
	zap.resize(n, false);
	for (int i=0;i<n;i++) if (!zap[i] && bad[i]) dfs3(i);
	for (int i=0;i<n;i++) if (!zap[i]){
	    dfs3(i);
	    ans--;
	}
	cout << ans;
}