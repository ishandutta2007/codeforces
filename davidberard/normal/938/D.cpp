#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

struct Node {
	ll first; int second;
	Node() {}
	Node(ll a, int b) : first(a), second(b) {}
	bool operator>(const Node& o) const {
		return first > o.first;
	}
};

vector<vector<Node>> edges;
vector<ll> cost;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N, M;
	cin >> N >> M;
	int vi,ui; 
	ll wi;
	edges.resize(N);
	cost.resize(N);
	for(int i=0;i<M;++i) {
		cin >> ui >> vi >> wi;
		--ui;--vi;
		edges[ui].push_back(Node(wi, vi));
		edges[vi].push_back(Node(wi, ui));
	}
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	for(int i=0;i<N;++i) {
		cin >> wi;
		cost[i] = wi;
		pq.push(Node(wi, i));
	}
	
	while(pq.size() > 0){
		Node state = pq.top();
		pq.pop();
		ll cst = state.first;
		int u = state.second;
		if(cost[u] != cst) continue;

		for(int i=0;i<edges[u].size();++i) {
			int v = edges[u][i].second;
			ll nc = cst + edges[u][i].first*2;
			if(nc < cost[v]) {
				cost[v] = nc;
				pq.push(Node(nc, v));
			}
		}
	}
	for(int i=0;i<N;++i) {
		cout << cost[i] << " ";
	}
	cout << endl;


	return 0;
}