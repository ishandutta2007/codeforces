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

const int INF = 1e9 + 7, N = 1e5 + 7;

map<string, int> mp;

int a[N], g[N], mn[N];

signed main()
{
	IO_OP;
	memset(mn, 0x3f, sizeof mn);
	int n, k,m;
	cin >> n >> k >> m;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		mp[s] = i + 1;
	}	
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<k;i++) {
		int x;
		cin >> x;
		for(int j=0;j<x;j++) {
			int t;
			cin >> t;
			g[t] = i;
			mn[i] = min(mn[i], a[t]);
		}
	}
	int ans = 0;
	while(m--) {
		string s;
		cin >> s;
		int i = mp[s];
		ans += mn[g[i]];
	}
	cout << ans << endl;
}