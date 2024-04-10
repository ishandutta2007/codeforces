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

const int INF = 1e9 + 7, N = 1e6 + 7;

signed main()
{
	IO_OP;
	
	int t, mx = 0; cin >> t;
	vi cnt(t);
	for(int i = 0; i < t; i++) {
		int x; cin >> x;
		cnt[x]++;
		mx = max(mx, x);
	}
	auto nono = [](){
		cout << -1 << endl;
		exit(0);
	};
	if(cnt[0] != 1) nono();
	int tt;
	for(tt = 1; cnt[tt] == tt * 4; tt++);
	auto ok = [&](int n, int m) -> bool {
		int row = tt, col = n - row + m - mx;
		if(row < 1 || row > n || col < 1 || col > m) return false;
		vi cntt(t);
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				cntt[abs(i-row)+abs(j-col)]++;
		if(cnt != cntt) return false;
		cout << n << " " << m << "\n" << row << " " << col << endl;
		return true;
	};
	for(int i = 1; i * i <= t; i++)
		if(t % i == 0)
			if(ok(i, t / i) || ok(t / i, i)) return 0;
	nono();

}