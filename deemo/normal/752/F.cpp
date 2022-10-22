//asdf
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, k, cc[MAXN], x[MAXN];
bool mark[MAXN];
vector<int>	adj[MAXN];
int gg;
vector<int>	vec[MAXN];
set<pair<int, int>>	st;

void plant(int v, int p = -1){
	cc[v] = mark[v];
	for (int u:adj[v])
		if (u^p)
			plant(u, v), cc[v] += cc[u];
}

int get(){
	int v = 0, p = -1;
	bool changed = 1;
	while (changed){
		changed = 0;
		for (int u:adj[v])
			if (u^p && cc[u]>k){
				p = v;
				v = u;
				changed = 1;
				break;
			}
	}
	return v;
}

void add(int v, int p){
	if (mark[v])
		vec[gg].push_back(v);
	for (int u:adj[v])
		if (u^p)
			add(u, v);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << "1\n";
	cin >> n >> k;
	for (int i = 0; i < n - 1; i ++){
		int a, b;	cin >> a >> b, a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < k+k; i++)
		cin >> x[i], x[i]--, mark[x[i]] = 1;
	plant(0);
	int v = get();
	cout << v+1 << "\n";
	for (int u:adj[v]){
		add(u, v);
		if (vec[gg].size())
			st.insert({vec[gg].size(), gg});
		gg++;
	}
	if (mark[v]){
		vec[gg].push_back(v);
		st.insert({vec[gg].size(), gg});
		gg++;
	}
	while (st.size()){
		auto it = st.end();	it--;
		auto a = *it;	it--;
		auto b = *it;
		st.erase(a);
		st.erase(b);

		cout << vec[a.S].back()+1 << " " << vec[b.S].back()+1 << " " << v+1 << "\n";
		vec[a.S].pop_back();
		vec[b.S].pop_back();
		if (vec[a.S].size())
			st.insert({vec[a.S].size(), a.S});
		if (vec[b.S].size())
			st.insert({vec[b.S].size(), b.S});
	}
	return 0;
}