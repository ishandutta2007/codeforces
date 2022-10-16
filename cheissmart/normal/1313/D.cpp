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

const int INF = 1e9 + 7, N = 1e5 + 7;

int dp[1 << 8];
int pos[N];

signed main()
{
	IO_OP;
	
	int n, k, m;
	cin >> n >> m >> k;
	map<int , vi> e;
	vi v;
	for(int i = 1; i <= n; i++) {
		int l, r;
		cin >> l >> r;
		v.PB(l), v.PB(r);
		e[l].PB(i);
		e[r].PB(-i);
	}
	sort(ALL(v));
	v.resize(unique(ALL(v))-v.begin());
	int pre = 0, ok = 0;
	for(int x : v) {
		for(int i = 0; i < (1 << 8); i++)
			if(!((~ok)&i) && (__builtin_popcount(i) & 1)) // i in ok
				dp[i] += (x - pre);
		vi q = e[x];
		sort(ALL(q), greater<int>());
		for(int i:q) {
			if(i < 0) {
				int j = pos[-i];
				for(int k=0;k<(1<<8);k++)
					if(k >> j & 1) {
						dp[k ^ (1 << j)] = max(dp[k], dp[k ^ (1 << j)]);
					}
				ok ^= 1 << j;
			} else {
				int j = 0;
				while(ok >> j & 1) j++;
				pos[i] = j;
				for(int k=0;k<(1<<8);k++) {
					if((k >> j & 1) && !((~ok)&(k ^ (1 << j)))) {
						dp[k] = dp[k ^ (1 << j)];
						if(__builtin_popcount(k)&1) dp[k]++;
						else dp[k]--;
					}
				}
				ok ^= 1 << j;
			}
		}
		pre = x;
		// for(int i=0;i<8;i++)
		// 	cout << i << ": " << dp[i] << "\t";
		// cout << endl;
	}
	cout << dp[0] << endl;
}