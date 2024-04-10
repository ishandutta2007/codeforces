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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 0x3f3f3f3f;

int dp[100005], lm[100005], x[88], s[88];

int bit[100005]; // [1, n]
int n, m;

int lowbit(int x) {
	return x & -x;
}
void upd(int i, int d) {
	while(i <= m) {
		bit[i] = min(d, bit[i]);
		i += lowbit(i);
	}
}
int qry(int i) {
	int res = INF;
	while(i) {
		res = min(bit[i], res);
		i -= lowbit(i);
	}
	return res;
}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> x[i] >> s[i];
	memset(lm, 0x3f, sizeof lm);
	for(int i=0;i<=m;i++) {
		lm[i] = i;
		for(int j=0;j<n;j++) {
			if(x[j]+s[j] >= i && x[j]-s[j] <= i)
				lm[i] = min(lm[i], lm[x[j]-s[j]]);
		}
	}
	set<int> st;
	memset(dp, 0x3f, sizeof dp);
	memset(bit, 0x3f, sizeof bit);
	dp[0] = 0;
	for(int i=1;i<=m;i++) {
		for(int p=0;p<n;p++) {
			if(x[p] <= i) {
				int ra = max(s[p], i - x[p]);
				int cost = ra - s[p];
				if(x[p] - ra >= 1) {
					int l = lm[x[p] - ra];
					if(l >= 1)
						cost += l + min(qry(l - 1), -1);
				}
				dp[i] = min(dp[i], cost);
			}
		}
		upd(i, dp[i]-(i+1));
	}
	cout << dp[m] << endl;
}