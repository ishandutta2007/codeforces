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

vi a[20];
int sum[20], first_give[1<<15], dp[1<<15], c[20], p[20], k, each;
bool vis[20], can_cyc[1<<15];

unordered_map<int, int> where;

void go(int t) {
	assert(can_cyc[t]);
	int cur = where[first_give[t]], give = first_give[t];
	for(int i=0;i<__builtin_popcount(t);i++) {
		int sm = sum[cur] - give, req = each - sm;
		int nxt = where[req];
		c[nxt] = req, p[nxt] = cur;
		cur = nxt, give = req;
	}
}

signed main()
{
	IO_OP;
	
	int tot = 0;
	cin >> k;
	for(int i=0;i<k;i++) {
		int n;
		cin >> n;
		a[i].resize(n);
		for(int j=0;j<n;j++) cin >> a[i][j], sum[i] += a[i][j], where[a[i][j]] = i;
		tot += sum[i];
	}
	if(tot % k) return cout << "No" << endl, 0;
	each = tot / k;
	for(int start =0;start < k;start++) {
		for(int start_give:a[start]) {
			memset(vis, 0, sizeof vis);
			int cur = start, give = start_give, i = 0;
			for(int j=0;j<k;j++) {
				i |= 1 << cur;
				vis[cur] = true;
				int sm = sum[cur] - give, req = each - sm;
				if(!where.count(req)) break;
				if(vis[where[req]]) {
					if(where[req] == start && req == start_give) {
						can_cyc[i] = true;
						first_give[i] = start_give;
					}
					break;
				}
				int nxt = where[req];
				cur = nxt, give = req;
			}
		}
	}
	for(int i=1;i<(1<<k);i++) {
		if(can_cyc[i]) {
			dp[i] = i;
			continue;
		}
		for(int j=(i-1)&i;j;j=(j-1)&i) {
			int k = i ^ j;
			if(dp[k] && can_cyc[j]) {
				dp[i] = j;
				break;
			}
		}
	}
	if(dp[(1<<k)-1]) {
		cout << "Yes" << endl;
		int s = (1 << k) - 1;
		while(s) {
			int t = dp[s];
			go(t);
			s ^= t;
		}
		for(int i=0;i<k;i++) cout << c[i] << " " << p[i]+1 << endl;
	} else {
		cout << "No" << endl;
	}
}