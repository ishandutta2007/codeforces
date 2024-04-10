#include <bits/stdc++.h>
// https://codeforces.com/blog/entry/49793?#comment-337790
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int solve_min(vi a, int k) {
	vi cnt(k + 1);
	for(int i:a) if(i <= k)
		cnt[i]++;
	for(int i = 1; i <= k; i++) if(cnt[i]) {
		if(cnt[i] & 1) {
			if(i * 2 <= k) cnt[i * 2] += (cnt[i] - 1) / 2;
			cnt[i] = 1;
		} else {
			if(i * 2 <= k) cnt[i * 2] += (cnt[i] - 2) / 2;
			cnt[i] = 2;
		}
	}
	bitset<1000001> dp;
	dp[0] = 1;
	for(int i = 1; i <= k; i++) if(cnt[i])
		for(int j = 0; j < cnt[i]; j++)
			dp |= dp << i;
	if(dp[k]) return k;
	else return k + 1;
}


int solve_max(vi a, int k) {
	int can = 0, sum = 0;
	for(int i:a)
		can += i / 2, sum += i;
	if(can >= k) return k * 2;
	else return min(can * 2 + k - can, sum);
}

signed main()
{
	IO_OP;

	int n, k;
	cin >> n >> k;
	vi p(n), vis(n);
	for(int i = 0; i < n; i++) cin >> p[i], p[i]--;
	vi a;
	for(int i = 0; i < n; i++) if(!vis[i]) {
		int j = i, cnt = 0;
		while(!vis[j]) {
			cnt++;
			vis[j] = 1;
			j = p[j];
		}
		a.PB(cnt);
	}
	cout << solve_min(a, k) << " " << solve_max(a, k) << '\n';

}