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
vector<int> T[N];
int d1[N];
int d2[N];

void dist(int* d, int v, int p, int ds) {
	d[v] = ds;
	for(int u : T[v]) {
		if(u == p) continue;
		dist(d, u, v, ds+1);
	}
}

bool check(int v, int p, int k) {
	if(k == 0) return T[v].size() == 1;
	bool ok = (p == -1) ? T[v].size() >= 3 : T[v].size() >= 4;
	for(int u : T[v]) {
		if(u == p) continue;
		ok &= check(u, v, k-1);
	}
	return ok;
}


int main() {	
	int n, k;
	cin >> n >> k;
	if(n < 4) {
		cout << "No\n";
		return 0;
	}
	for(int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	int u = 1;
	while(T[u].size() > 1) ++u;

	dist(d1, u, -1, 0);
	int v = 1;
	for(int i = 2; i <= n; ++i) {
		if(d1[i] > d1[v]) v = i;
	}

	dist(d2, v, -1, 0);

	int rt = 1;
	for(int i = 1; i <= n; ++i) {
		if(d1[i] == k && d2[i] == k)
			rt = i;
	}

	if(check(rt, -1, k)) cout << "Yes\n";
	else cout << "No\n";



}