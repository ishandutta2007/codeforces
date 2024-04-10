#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 2e5+5;
vector<int> T[N];

int order[N];

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}

	for(int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		order[a] = i;
	}

	queue<pii> Q;
	Q.emplace(1, -1);
	int ctr = 0;
	bool ok = true;
	while(!Q.empty()) {
		pii p = Q.front();
		if(order[p.first] != ctr++)
			ok = false;
		Q.pop();
		vector<pii> nxt;
		for(int c : T[p.first]) {
			if(c == p.second) continue;
			nxt.emplace_back(order[c], c);
		}
		sort(nxt.begin(), nxt.end());
		for(pii c : nxt)
			Q.emplace(c.second, p.first);
	}

	if(ok) cout << "Yes\n";
	else cout << "No\n";



}