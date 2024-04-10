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

const int INF = 1e9 + 7, P = 100005, M = 1000000009, Q = 998244353, R = 1000000007;

int h[200005], hh[200005];
vi G[100005];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		G[a].PB((b-a+n) % n);
		G[b].PB((a-b+n) % n);
	}
	for(int i=1;i<=n;i++) {
		sort(ALL(G[i]));
		int hash = 1;
		for(int j:G[i])
			hash = (hash * P + j) % M;
		h[i] = hash;
 	}
	for(int i=1;i<=n;i++)
		h[i+n] = h[i];
	for(int i=1;i<=2*n;i++)
		hh[i] = (hh[i-1] * Q + h[i]) % R;
	int pw = 1;
	for(int i=1;i<=n;i++) pw = pw * Q % R;
	for(int i=2;i<=n;i++) {
		int hash = (hh[i+n-1] - hh[i-1] * pw % R + R) % R;
		if(hash == hh[n]) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}