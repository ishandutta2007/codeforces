/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

#define int long long

const int kMaxN = 500000;
const long long kInf = 1e18;

vector<pair<int, int>> G[kMaxN];
priority_queue<pair<long long, int>> Q;
long long D[kMaxN];
int n, m, k;

void Dijkstra() {
	while(!Q.empty()) {
		auto top = Q.top();
		Q.pop();

		int node = top.second;
		if(D[node] != -top.first) continue;

		for(auto e : G[node]) {
			int vec = e.first, cost = e.second;

			if(D[vec] > D[node] + cost) {
				D[vec] = D[node] + cost;
				Q.emplace(-D[vec], vec);
			}
		}
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		G[a].emplace_back(b, c);
		G[b].emplace_back(a, c);
	}

	for(int i = 1; i <= n; ++i)
		D[i] = kInf;

	if(k == 0) {
		cout << -1;
		return 0;
	}

	for(int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		D[x] = 0;
		Q.emplace(0, x);
	}

	Dijkstra();

	//arr_dump(D, n + 1);

	int choose = -1;
	long long now = kInf;

	for(int i = 1; i <= n; ++i) {
		if(D[i] != 0 && D[i] < now) {
			now = D[i];
			choose = i;
		}
	}

	if(choose == -1) {
		cout << -1 << endl;
	} else {
		cout << D[choose] << endl;
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/