#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const int N = 1e5+5;
vector<int> G[N];
int c[N];

int search(int v) {
	if(c[v] == -1) return 0x7fffffff;
	int cost = c[v];
	c[v] = -1;
	for(int u : G[v]) {
		cost = min(cost,search(u));
	}
	return cost;
}

int main() {	
	fio;
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i)
		cin >> c[i];
	while(m--) {
		int a,b;
		cin >> a >> b,--a,--b;
		G[a].pb(b);
		G[b].pb(a);
	}
	ll cost = 0;
	for(int i = 0; i < n; ++i) {
		if(c[i] == -1) continue;
		cost += search(i);
	}
	cout << cost << "\n";
}