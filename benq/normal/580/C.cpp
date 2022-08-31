#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define vi vector<int>

#define F0R(i, a) for (int i=0; i<a; i++)

int c[100000], n, m, ans;
vi edge[100000];

void dp(int node, int par, int count) {
	int ccount = count;
	if (c[node]) ccount++;
	else ccount = 0;
	if (ccount <= m) {
		bool x = false;
		for (int i: edge[node]) if (i != par) dp(i,node,ccount), x = true;
		if (!x) ans++;
	}
}

int main() {
	cin >> n >> m;
	F0R(i,n) cin >> c[i];
	F0R(i,n-1) {
		int x,y;
		cin >> x >> y;
		edge[x-1].pb(y-1), edge[y-1].pb(x-1);
	}
	dp(0,0,0);
	cout << ans;
	return 0;
}