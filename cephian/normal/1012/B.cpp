#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef unsigned long long ll;

const int N = 2e5+5;
int uf[2*N];
int rsz[2*N];
int csz[2*N];

int id(int v) {
	if(uf[v] == v) return v;
	return uf[v] = id(uf[v]);
}

void merge(int u, int v) {
	u = id(u);
	v = id(v);
	rsz[v] += rsz[u];
	csz[v] += csz[u];
	uf[u] = v;
}

int main() {
	fio;
	int n,m,q;
	cin >> n >> m >> q;
	for(int i = 0; i < n + m; ++i) {
		uf[i] = i;
		if(i < n) {
			rsz[i] = 1;
			csz[i] = 0;
		} else {
			rsz[i] = 0;
			csz[i] = 1;
		}
	}

	for(int i = 0; i < q; ++i) {
		int r, c;
		cin >> r >> c;
		--r, --c;
		merge(r, n + c);
	}
	int cc = 0;

	for(int i = 0; i < n+m; ++i ) {
		cc += id(i) == i;
	}
	cout << cc-1 << "\n";
}