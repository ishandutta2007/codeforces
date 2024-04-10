#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

int n, val[MAXN], sm, sub[MAXN];
vector<int> adj[MAXN];

void plant(int v){
	sub[v] = val[v];
	for (int u:adj[v])
		plant(u), sub[v] += sub[u];
}

int root = -1;
int go(int v, int id1 = -1, int id2 = -1){
	if (sub[v] == sm && id1 != -1){
		cout << v+1 << " " << id1+1 << "\n";
		exit(0);
	}
	if (sub[v] == sm && id2 != -1){
		cout << v+1 << " " << id2+1 << "\n";
		exit(0);
	}

	if (sub[v] == sm+sm && v != root) id1 = v;
	for (int u:adj[v])
		id2 = max(id2, go(u, id1, id2));
	if (sub[v] == sm && v != root)
		id2 = v;
	return id2;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		int p;	cin >> p >> val[i], p--;
		if (~p)
			adj[p].push_back(i);
		else
			root = i;
		sm += val[i];
	}
	if (sm % 3 != 0){
		cout << "-1\n";
		return 0;
	}
	sm /= 3;
	plant(root);
	go(root);
	cout << "-1\n";
	return 0;
}