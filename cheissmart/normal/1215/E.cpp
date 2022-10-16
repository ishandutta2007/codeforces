#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e15 + 7, N = 20, M = 1 << N;

int a[N][400005], d[N][N], dp[M];
vi G[N];

int32_t main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		t--;
		a[t][i]++;
		G[t].PB(i);
	}
	for(int i=0;i<N;i++)
		for(int j=1;j<n;j++)
			a[i][j] += a[i][j-1];
	for(int i=0;i<N;i++) {
		for(int j=0;j<N;j++) {
			if(i == j) continue;
			for(int k:G[i])
				d[i][j] += a[j][k];
		}
	}
	for(int i=1;i<M;i++) {
		dp[i] = INF;
		for(int j=0;j<N;j++) if(i>>j&1) {
			int w = 0;
			for(int k=0;k<N;k++) if(i>>k&1)
				w += d[j][k];
			dp[i] = min(dp[i], dp[i^(1<<j)] + w);
		}
	}
	cout << dp[M-1] << endl;
	
}