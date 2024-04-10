#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[1000006], dp[2][1000006], dpp[2][1000006], bit[1000006];
vi m[1000006];

int lowbit(int x) {
	return x & -x;
}
void add(int x, int v) {
	while(x < 1000006) {
		bit[x] += v;
		x += lowbit(x);
	}
}
int qry(int x) {
	int ans = 0;
	while(x) {
		ans += bit[x];
		x -= lowbit(x);
	}
	return ans;
}

int32_t main()
{
	IO_OP;
	
	int n, x;
	cin >> n >> x;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		m[a[i]].PB(i);
	}
	dp[0][0] = true;
	dp[1][0] = 0;
	for(int i=1;i<=x;i++) {
		if (m[i].empty()) {
			dp[0][i] = dp[0][i-1];
			dp[1][i] = dp[1][i-1];
		} else {
			if (m[i][0] < dp[1][i-1])
				break;
			dp[0][i] = true;
			dp[1][i] = m[i].back();
		}
	}
	dpp[0][x+1] = true;
	dpp[1][x+1] = n+1;
	for(int i=x;i>=1;i--) {
		if (m[i].empty()) {
			dpp[0][i] = dpp[0][i+1];
			dpp[1][i] = dpp[1][i+1];
		} else {
			if (m[i].back() > dpp[1][i+1])
				break;
			dpp[0][i] = true;
			dpp[1][i] = m[i][0];
		}
	}
	int ans = 0;
	for(int i=x-1;i>=0;i--) {
		if(dpp[0][i+2])
			add(dpp[1][i+2], 1);
		if(!dp[0][i]) continue;
		ans += qry(n+1) - qry(dp[1][i]);
	}
	cout << ans << endl;
}