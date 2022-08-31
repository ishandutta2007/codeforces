#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> pii;

#define F0R(i, a) for (int i=0; i<a; i++)
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
 
const int MOD = 1000000007;

int n,m,L,s,t; 
set<pii> adj[1000];
vector<pii> edges;
vector<pair<pii,int>> totaledges;

void seta(int a, int b, int w) {
	adj[a].erase(adj[a].lb(mp(b,0)));
	adj[a].insert(mp(b,w));
	adj[b].erase(adj[b].lb(mp(a,0)));
	adj[b].insert(mp(a,w));
}

int shortest_path() {
	int shortest[1000];
	bool visit[1000];
	F0R(i,1000) shortest[i] = MOD, visit[i] = 0;
	
	priority_queue<pii> k;
	shortest[s] = 0;
	k.push(mp(0,s));
	
	while (visit[t] == 0 && k.size()) {
		auto a = k.top(); k.pop();
		a.f = -a.f;
		if (visit[a.s]) continue;
		for (pii edge: adj[a.s]) if (shortest[edge.f]>(shortest[a.s]+edge.s)) {
			shortest[edge.f] = shortest[a.s]+edge.s;
			k.push(mp(-shortest[edge.f],edge.f));
		}
		visit[a.s] = 1;
	}
	return shortest[t];
}

void prin() {
	cout << "YES\n";
	for (auto a: totaledges) {
		cout << a.f.f << " " << a.f.s << " ";
		if (a.s != 0) cout << a.s;
		else {
			pii k = *adj[a.f.f].lb(mp(a.f.s,0));
			cout << k.s;
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> L >> s >> t;
	F0R(i,m) {
		int u,v,w; cin >> u >> v >> w;
		if (w == 0) {
			adj[u].insert(mp(v,1));
			adj[v].insert(mp(u,1));
			edges.pb(mp(u,v));
		} else {
			adj[u].insert(mp(v,w));
			adj[v].insert(mp(u,w));
		}
		totaledges.pb(mp(mp(u,v),w));
	}
	if (shortest_path()>L) {
		cout << "NO";
		return 0;
	}
	for (auto a: edges) seta(a.f,a.s,MOD);
	if (shortest_path()<L) { 
		cout << "NO";
		return 0;
	}
	
	int low = 0, high = edges.size(), cur = 0;
	while (low<high) {
		int mid = (low+high+1)/2;
		while (cur<mid) {
			seta(edges[cur].f,edges[cur].s,1);
			cur++;
		}
		while (cur>mid) {
			cur--;
			seta(edges[cur].f,edges[cur].s,MOD);
		}
		if (shortest_path() < L) high = mid-1;
		else low = mid;
	}
	while (cur<low) {
		seta(edges[cur].f,edges[cur].s,1);
		cur++;
	}
	while (cur>low) {
		cur--;
		seta(edges[cur].f,edges[cur].s,MOD);
	}
	if (low == edges.size()) {
		prin();
		return 0;
	}
	low = 1, high = MOD;
	while (low<high) {
		int mid = (low+high+1)/2;
		seta(edges[cur].f,edges[cur].s,mid);
		if (shortest_path() <= L) low = mid;
		else high = mid-1;
	}
	seta(edges[cur].f,edges[cur].s,low);
	prin();
}