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

const int INF = 1e9 + 7;
const int N = 1e5 + 7, K = 22;

int dp[N][K], cnt[N], a[N];

int L = 1, R = 1, cur = 0;

int cost(int l, int r) {
	while(L > l) cur += cnt[a[--L]]++;
	while(R < r) cur += cnt[a[++R]]++;
	while(L < l) cur -= --cnt[a[L++]];
	while(R > r) cur -= --cnt[a[R--]];
	return cur;
}

void go(int l, int r, int ql, int qr, int j) {
	if(l >= r) return;
	int m = (l + r) / 2;
	int qm = ql;
	for(int i=ql;i<min(qr, m);i++)
		if(dp[m][j] > dp[i][j-1] + cost(i+1, m))
			qm = i, dp[m][j] = dp[i][j-1] + cost(i+1, m);
	go(l, m, ql, qm+1, j);
	go(m+1, r, qm, qr, j);
}

signed main()
{
	IO_OP;
	
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	memset(dp, 0x3f, sizeof dp);
	cnt[a[1]]++;
	for(int i=1;i<=n;i++) dp[i][1] = cost(1, i); 
	for(int j=2;j<=k;j++) go(1, n+1, 1, n+1, j);
	cout << dp[n][k] << endl;	
}