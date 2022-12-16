#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> a, pfx;
int N, K;

bool hasPathSizeK(vector<vector<int>>& edges) {
	vector<int> indeg(N+1, 0);
	for(auto& v : edges) {
		for(auto& vv : v) {
			indeg[vv]++;
		}
	}
	queue<int> q;
	for(int i=0;i<N;++i) {
		if(indeg[i] == 0) q.push(i);
	}
	vector<bitset<60>> plens(N+1);
	plens[0].set(0);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		//cerr << "For u = " << u << ", " << plens[u].to_string() << endl;
		for(int& v : edges[u]) {
			plens[v] = (plens[u]<<1) | plens[v];
			//cerr << "Now for v = " << v << ", " << plens[v].to_string() << endl;
			if(--indeg[v] == 0) {
				q.push(v);
			}
		}
	}
	return (plens[N].test(K));
}


bool possible(ll goal) {
	vector<vector<int>> edges(N+1);
	for(int i=0;i<N;++i) {
		for(int j=i+1;j<=N;++j) {
			if(((pfx[j]-pfx[i])&goal) == goal) {
				//cerr << " " << i << " -> " << j << " : " << pfx[j]-pfx[i] << endl;
				edges[i].push_back(j);
			}
		}
	}
	return hasPathSizeK(edges);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	cin >> K;
	a = vector<ll>(N), pfx = vector<ll>(N+1);

	for(ll& ii : a) cin >> ii;
	pfx[0] = 0;
	for(int i=1;i<=N;++i) {
		pfx[i] = pfx[i-1]+a[i-1];
	}

	ll top = 1LL<<57;
	ll bot = 0;

	//possible(24);
	//cerr << "!! " << endl;

	while(bot < top-1) {
		ll mid = (top+bot)/2;
		//cerr << bot << " " << mid << " " << top << endl;
		if(possible(mid)) {
			bot = mid;
		} else {
			top = mid;
		}
	}

	if(possible(top)) {
		cout << top << endl;
	} else {
		cout << bot << endl;
	}


	return 0;
}