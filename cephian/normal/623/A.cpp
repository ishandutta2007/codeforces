#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

int n,m;
bool G[505][505];
int deg[505]={0};
int col[505];
bool vis[505]={0};

vector<int> a;
vector<int> c;

void fcc(int v, int c) {
	if(vis[v]) return;
	col[v] = c;
	vis[v] = 1;
	for(int i = 0; i < n; ++i) {
		if(!vis[i] && G[v][i] && i != v) {
			fcc( i,c);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j)
			G[i][j] = 0;
	}
	for(int i = 0; i < m; ++i) {
		int u,v;
		cin >> u >> v;
		--u;
		--v;
		++G[v][u];
		++G[u][v];
		++deg[u];
		++deg[v];
	}
	for(int i = 0; i < n; ++i) {
		if(deg[i] == n-1) {
			col[i] = 'b';
			vis[i] = 1;
		}
	}

	for(int i = 0; i < n; ++i) {
		if(col[i] == 0) {
			fcc(i,'a');
			break;
		}
	}

	for(int i = 0; i < n; ++i) {
		if(col[i] == 0) {
			fcc(i,'c');
			break;
		}
	}
	for(int i = 0; i < n; ++i) {
		if(col[i] == 'a') a.push_back(i);
		else if(col[i] == 'c') c.push_back(i);
		else if(col[i] != 'b'){
			cout << "No\n";
			return 0;
		}
	}

	for(int i = 0; i < a.size(); ++i) {
		for(int j = i+1; j < a.size(); ++j) {
			if(G[a[i]][a[j]] == 0) {
				cout << "No\n";
				return 0;
			}
		}
	}
	for(int i = 0; i < c.size(); ++i) {
		for(int j = i+1; j < c.size(); ++j) {
			if(G[c[i]][c[j]] == 0) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
	for(int i = 0; i < n; ++i) {
		cout << char(col[i]);
	}
	cout << "\n";
	return 0;
}