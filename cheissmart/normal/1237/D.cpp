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

const int INF = 1e9 + 7, N = 100005;

int a[3*N], st[3*N][20], dp[3*N];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		a[i+n] = a[i+2*n] = a[i];
	}
	for(int i=0;i<3*n;i++)
		st[i][0] = a[i];
	for(int j=1;j<20;j++)
		for(int i=0;i+(1<<j)-1<3*n;i++)
			st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	V<pi> v;
	for(int i=3*n-1;i>=0;i--) {
		while(v.size() && a[i] >= v.back().F) v.pop_back();
		int nxt = INF;
		if(v.size()) nxt = v.back().S;
		v.EB(a[i], i);
		int k = i;
		for(int j=19;j>=0;j--)
			if(k+(1<<j) < 3*n && st[k+1][j]*2 >= a[i])
				k = k+(1<<j);
		if(k+1 < nxt) dp[i] = k;
		else dp[i] = dp[nxt];
	}
	for(int i=0;i<n;i++) {
		if(dp[i]-i+1 >= 2*n) cout << -1 << " ";
		else cout << dp[i]-i+1 << " ";
	}
	
}