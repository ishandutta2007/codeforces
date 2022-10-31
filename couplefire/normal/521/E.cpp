#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000+10;

int n,e;
int par[MAXN],f[MAXN],lo[MAXN],hi[MAXN],mark[MAXN];
vector<int> adj[MAXN];

vector<int> path (int a, int b){
	vector<int> ret;
	while (a != par[b]){
		ret.push_back(a);
		a = par[a];
	}
	return ret;
}

vector<int> path (int a, int b, int source, int sink){
	vector<int> p0 = path(a, source); reverse(p0.begin(), p0.end());
	vector<int> p1 = path(sink, b); reverse(p1.begin(), p1.end());
	for (int i=0; i<(int)p1.size(); i++)
		p0.push_back(p1[i]);
	return p0;
}

bool dfs (int v, int p){
	mark[v] = 1;
	par[v] = p;
	lo[v] = hi[v] = -1;
	vector < pair<int,int> > q;
	for (int i=0; i<(int)adj[v].size() && (int)q.size()<2; i++){
		int temp = adj[v][i];
		if (temp == p) continue;
		if (!mark[temp]){
			if (dfs(temp, v))
				return true;
			if (hi[temp]!=-1 && hi[temp]!=v)
				q.push_back(pair<int,int>(lo[temp],hi[temp]));
		}else if (mark[temp] == 1)
			q.push_back(pair<int,int>(v,temp));
	}
	if ((int)q.size() == 2){
		int a = q[0].first, b = q[0].second;
		int c = q[1].first, d = q[1].second;
		int source = -1, sink = -1;
		while (a != par[b]){ f[a]+= 1; a = par[a]; }
		while (c != par[d]){
			f[c]+= 2; 
			if (source==-1 && f[c]==3) source = c; 
			if (f[c]==3) sink = c; 
			c = par[c]; 
		}
		vector<int> p[3];
		p[0] = path(q[0].first, q[0].second, source, sink);
		p[1] = path(q[1].first, q[1].second, source, sink);
		p[2] = path(source, sink);
		puts("YES");
		for (int i=0; i<3; i++){
			printf("%d", (int)p[i].size());
			for (int j=0; j<(int)p[i].size(); j++)
				printf(" %d", p[i][j]+1);
			puts("");
		}
		return true;
	}else if (!q.empty())
		lo[v] = q[0].first, hi[v] = q[0].second;
	mark[v] = 2;
	return false;
}

int main(){
	scanf("%d%d", &n, &e);
	for (int i=0; i<e; i++){
		int e1,e2; scanf("%d%d", &e1, &e2);
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	for (int i=0; i<n; i++) if (!mark[i])
		if (dfs(i,-1))
			return 0;
	puts("NO");
	return 0;
}