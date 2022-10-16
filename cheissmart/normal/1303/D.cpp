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
 
int cnt[64], tmp[64];
 
signed main()
{
	IO_OP;
	
	int tt;
	cin >> tt;
	while(tt--) {
		memset(cnt, 0, sizeof cnt);
		int n, m, ssum = 0;
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			int t;
			cin >> t;
			ssum += t;
			int b = __lg(t);
			cnt[b]++;
		}
		if(ssum < n) {
			cout << -1 << endl;
			continue;
		}
		int ans = 0;
		for(int i = 0;i < 60;i++) {
			if(n >> i & 1) {
				if(!cnt[i]) {
					int k;
					ans++;
					for(int j = i + 1;j < 60;j++) {
						if(cnt[j]) {
							k = j;
							break;
						} else {
							ans++;
						}
					}
					while(k > i) {
						cnt[k]--;
						cnt[k-1] += 2;
						k--;
					}
					cnt[i]--;
				} else {
					cnt[i]--;
				cnt[i+1] += cnt[i] / 2;
				cnt[i] %= 2;
				}
			} else {
				cnt[i+1] += cnt[i] / 2;
				cnt[i] %= 2;
			}
		}
		cout << ans << endl;
	}
	
}