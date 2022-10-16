#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	int n, T;
	cin >> n >> T;
	V<pi> v;
	for(int i=1;i<=n;i++) {
		int t;
		cin >> t;
		int l = max(t-i, 0ll), r = T-i-1;
		if(l <= r) {
			v.EB(l, 0);
			v.EB(r, 1);
		}
	}
	sort(ALL(v));
	int c = 0, ans = 0;
	for(int i=0;i<v.size();i++) {
		if(v[i].S == 0) c++;
		else c--;
		ans = max(ans, c);
	}
	cout << ans << endl;
}