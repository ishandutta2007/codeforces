#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 1e5 + 87;

vi G[N];
int ok[N],n, m;

int main()
{
	IO_OP;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	priority_queue<int, vi, greater<int>> pq;
	for(int u:G[1]) {
		if(!ok[u])
			pq.push(u);
	}
	ok[1] = 1;
	vi ans;
	ans.PB(1);
	while(pq.size()) {
		int u = pq.top(); pq.pop();
		if(ok[u]) continue;
		ans.PB(u);
		ok[u] = 1;
		for(int v:G[u]) {	
			if(!ok[v])
				pq.push(v);
			}
	}
	for(int i:ans) cout << i << " ";
}