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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int a[200005];
vi G[200005];

int solve() {
	int n;
	cin >> n;
	for(int i=0;i<=n;i++) G[i].clear();
	for(int i=0;i<n;i++) cin >> a[i], G[a[i]].PB(i);
	if(n == 1) return -1;
	int mn = INF;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<(int)G[i].size()-1;j++){
			mn = min(mn, G[i][j+1]-G[i][j]+1);
		}
	}
	if(mn == INF) return -1;
	return mn;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) cout << solve() << endl;	
	
}