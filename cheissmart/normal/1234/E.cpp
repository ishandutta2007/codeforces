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

const int INF = 1e9 + 7, N = 2e5 + 87;

int x[N], pos[N], ans;

vi adj[N];

void change(int i, int pp) {
	for(int e:adj[i]) {
		ans -= abs(pos[i]-pos[e]);
		ans += abs(pp-pos[e]);
	}
	pos[i] = pp;
}

int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		cin >> x[i];
	}
	for(int i=1;i<=n;i++)
		pos[i] = i;
	for(int i=1;i<m;i++) {
		if(x[i] == x[i+1]) continue;
		adj[x[i]].PB(x[i+1]);
		adj[x[i+1]].PB(x[i]);
	}
	for(int i=1;i<m;i++)
		ans += abs(pos[x[i]] - pos[x[i+1]]);
	cout << ans << " ";
	for(int i=2;i<=n;i++) {
		change(i-1, i);
		change(i, 1);
		cout << ans << " ";
	}
}