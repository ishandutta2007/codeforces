#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

ll n, m, a[25][25];
ll ans;
ll k;
map<ll, int> b[25][25];

void dfs(int i, int j, int s, ll t) {
	if(s == 0) {
		b[i][j][t]++;
		return;
	}
	if(i+1 <= n) dfs(i+1, j, s-1, t ^ (ll)a[i+1][j]);
	if(j+1 <= m) dfs(i, j+1, s-1, t ^ (ll)a[i][j+1]);
}

void dfs2(int i, int j, int s, ll t) {
	if(s == 0) {
		ans += (ll)b[i][j][k^t];
		return;
	}
	t ^= (ll)a[i][j];
	if(i-1 >= 1) dfs2(i-1, j, s-1, t);
	if(j-1 >= 1) dfs2(i, j-1, s-1, t);
}

int main()
{
	IO_OP;

	cin >> n >> m >> k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	int s = (n+m-2) / 2;
	dfs(1, 1, s, a[1][1]);
	dfs2(n, m, n+m-2-s, 0);
	cout << ans << endl;
}