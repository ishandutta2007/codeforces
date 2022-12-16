#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

namespace sccs{
	const int N = 200100;
	int low[N],vis[N],scomp[N],scompNum,I;
	vector<int> adj[N]; stack<int> verts;
	void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
		for (int v : adj[u]) {
			if (!vis[v]) scc(v);
			if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
		if (vis[u] <= low[u]) { int v;
			do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
			++scompNum; }}
	void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
		scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
	////////////////////////////////////////////////////////////////////////////////
	// 2-SAT using SCC (previous version was TESTED F - SouthAmerica03)
	////////////////////////////////////////////////////////////////////////////////
	bool truth[N/2]; // N must be at least 2 times the number of variables
	// the clause a || b becomes !a => b and !b => a in the implication graph
	void add_clause(int a, int b) { adj[a^1].push_back(b); adj[b^1].push_back(a); }
	bool two_sat(int n) { get_scc(n);
		for (int i = 0; i < n; i += 2) { if (scomp[i] == scomp[i^1]) return false;
			truth[i/2] = (scomp[i] < scomp[i^1]); } return true; }
}

vector<vector<int>> v;

//  [lo, hi)
bool dfs(int lo, int hi, int dig) {
	////cerr << " on dig " << dig << " at " << lo << ", " << hi << endl;
	int firstOfType = -1;
	int type = -1;
	for(int i=lo;i<hi;++i) {
		int ttype = -1;
		if(v[i].size() > dig) {
			ttype = v[i][dig];
		}
		if(ttype != type) {
			if(type != -1) {
				if(!dfs(firstOfType, i, dig+1)) {
					return false;
				}
				if(ttype == -1) {
					return false;
				}

				// if this one is greater than the last one... that's good.
				if(type < ttype) {
					// if first one is capital, second one also has to be
					sccs::adj[type<<1|1].push_back(ttype<<1|1);
					// if second one is lowercase, first also has to 
					sccs::adj[ttype<<1].push_back(type<<1);
					//cerr << type << " -> " << ttype << endl;
				}
				if(type > ttype) {
					// big type = bad, small ttype = bad
					sccs::adj[type<<1|1].push_back(type<<1);
					//cerr << type << " -> !" << type << endl;
					sccs::adj[ttype<<1].push_back(ttype<<1|1);
					sccs::adj[ttype<<1].push_back(type<<1);
					sccs::adj[type<<1|1].push_back(type<<1|1);
					sccs::adj[ttype<<1|1].push_back(type<<1);
					//cerr << "!" << ttype << " -> " << ttype << endl;
					//sccs::adj[type<<1].push_back(ttype<<1|1);
					//sccs::adj[ttype<<1|1].push_back(type<<1);
					//cerr << "" << type << " -> !" << ttype << endl;
				}

			}
			if(type != -1 && ttype == -1) {
				return false;
			}

			type = ttype;
			firstOfType = i;
		}
	}
	if(firstOfType < hi && type != -1) {
		if(!dfs(firstOfType, hi, dig+1)) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	int N, M;
	cin >> N >> M;
	
	for(int i=0;i<N;++i) {
		int sz, vv;
		cin >> sz;
		v.push_back(vector<int>());
		for(int j=0;j<sz;++j){
			cin >> vv;
			v.back().push_back(vv);
		}
	}

	if(!dfs(0, N, 0)) {
		cout << "No\n";
		return 0;
	}

	if(!sccs::two_sat(M*2+2)) {
		cout << "No\n";
		return 0;
	}
	
	vector<int> truths;
	for(int i=1;i<=M;++i) {
		if(sccs::truth[i]) {
			truths.push_back(i);
		}
	}
	
	cout << "Yes\n" << truths.size() << endl;
	for(int vv : truths) {
		cout << vv << " ";
	}
	cout << endl;

	return 0;
}