#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

vector<int> tree[2005];
set<int> look;

int dfs(int v, int p) {
	if(look.count(v)) return v;
	for(int u : tree[v]) {
		if(u == p) continue;
		int r = dfs(u, v);
		if(r != 0)
			return r;
	}
	return 0;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 1; i <= n; ++i)
			tree[i].clear();
		for(int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		int k1;
		cin >> k1;
		look.clear();
		for(int i = 0; i < k1; ++i) {
			int mine;
			cin >> mine;
			look.insert(mine);
		}

		int k2;
		cin >> k2;
		vector<int> his_t(k2);
		for(int i = 0; i < k2; ++i)
			cin >> his_t[i];

		// find out where one node in his tree is
		cout << "B " << his_t[0] << endl;
		int his_node;
		cin >> his_node;

		//find closest node in my nodes to his
		int closest = dfs(his_node, -1);

		// ask what his is
		cout << "A " << closest << endl;
		int which;
		cin >> which;

		//is it in his tree?? if so yes, if not no
		bool found = false;
		for(int x : his_t) {
			if(x == which) {
				cout << "C " << closest << endl;
				found = true;
				break;
			}
		}
		if(!found) cout << "C -1" << endl;


	}
}