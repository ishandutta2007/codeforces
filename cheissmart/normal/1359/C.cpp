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

void solve() {
	int h, c, t;
	cin >> h >> c >> t;
	if(t * 2 <= h + c) {
		cout << 2 << endl;
		return;
	}
	h -= c, t -= c;
	int lb = 1, rb = INF;
	while(lb <= rb) {
		int i = (lb + rb) / 2;
		if(i * h < t * (2 * i - 1)) rb = i - 1;
		else lb = i + 1;
	}
	int xx = 1, yy = 0, ans = 0;
	for(int i:vi{rb, lb}){
		if(i <= 0) continue;
		double a = abs(i * h - t * (2 * i - 1)), b = i * 2 - 1;
		if(a * yy < b * xx) {
			xx = a, yy = b;
			ans = i * 2 - 1;
		}
	}
	cout << ans << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();
		
}