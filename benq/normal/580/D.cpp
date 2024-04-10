#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

int n,m,sat[18],k,edge[18][18];
ll ans, r[18][262144];
bool done[18][262144];

ll dfs(int a, int b, int c) {
	if (done[a][b]) return r[a][b];
	int b1 = b | (1<<a);
	if (c < m) F0R(i,n) if ((b1 & (1<<i)) == 0) r[a][b] = max(r[a][b],edge[a][i]+dfs(i,b1,c+1));
	r[a][b] += sat[a], done[a][b] = 1;
	return r[a][b];
}

int main() {
	cin >> n >> m >> k;
	F0R(i,n) cin >> sat[i];
	F0R(i,k) {
		int x,y,c;
		cin >> x >> y >> c;
		edge[x-1][y-1] = c;
	}
	F0R(i,n) ans=max(ans,dfs(i,0,1));
	cout << ans;
}