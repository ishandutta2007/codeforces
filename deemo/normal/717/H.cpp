#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAXN = 5e4 + 10;
const int MAXE = 1e5 + 10;
const int MAXT = 1e6 + 10;

int n, m, from[MAXE], to[MAXE], T, deg[MAXN];
bool c[MAXT], col[MAXN];
vector<int>	adj[MAXN], vec[MAXN];
set<pair<int, int>>	st;

int main(){
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		cin >> from[i] >> to[i], from[i]--, to[i]--;
		adj[from[i]].push_back(i);
		adj[to[i]].push_back(i);
	}
	for (int i = 0; i < n; i++){
		int sz;	cin >> sz;
		vec[i].resize(sz);
		for (int j = 0; j < sz; j++)
			cin >> vec[i][j], T = max(T, vec[i][j]);
	}
	
	//asdf
	for (int i = 1; i <= T; i++)
		c[i] = rand() & 1;
	
	for (int i = 0; i < n; i++)
		col[i] = rand() & 1;

	int cur = 0;
	for (int i = 0; i < m; i++)
		if (col[from[i]] ^ col[to[i]]){
			cur++;
			deg[from[i]]++;
			deg[to[i]]++;
		}

	for (int i = 0; i < n; i++)
		st.insert({deg[i] - ((int)adj[i].size() - deg[i]), i});

	while (cur<<1 < m){
		auto v = *st.begin();
		st.erase(st.begin());

		for (int e:adj[v.S]){
			int u = from[e]^to[e]^v.S;
			st.erase({deg[u] - ((int)adj[u].size() - deg[u]), u});
			if (col[v.S] != col[u])
				deg[u]--;
			else
				deg[u]++;
			st.insert({deg[u] - ((int)adj[u].size() - deg[u]), u});
		}
		
		cur += -v.F;
		deg[v.S] += -v.F;
		col[v.S] = !col[v.S];
		st.insert({deg[v.S] - ((int)adj[v.S].size() - deg[v.S]), v.S});
	}

	for (int i = 0; i < n; i++){
		bool found = 0;
		for (int u:vec[i])
			if (col[i] == c[u]){
				cout << u << " ";
				found = 1;
				break;
			}
		assert(found);
	}
	cout << "\n";

	for (int i = 1; i <= T; i++)
		cout << (int)c[i] + 1 << " ";
	cout << "\n";
	return 0;
}