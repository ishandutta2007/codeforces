#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int M = 1e9 + 7;

int a[100005], ans;
vi G[100005];

void dfs(int u, int p = -1, map<int, int> m = map<int, int>()) {
	map<int, int> mm;
	for(pi p:m) mm[__gcd(p.F, a[u])] += p.S;
	mm[a[u]]++;
	for(pi p:mm) ans = (ans + p.F % M * p.S % M) % M;
	for(int v:G[u]) if(v != p)
		dfs(v, u, mm);
}

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs(1);
	cout << ans << endl;
	
}