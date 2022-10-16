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

signed main()
{
	IO_OP;

	int n, m, k;
	cin >> n >> m >> k;
	V<pi> v;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		v.EB(t, i);
	}
	sort(ALL(v), greater<pi>());
	vi vv;
	int ans = 0;
	for(int i=0;i<m*k;i++){
		vv.PB(v[i].S);
		ans += v[i].F;
	}
	cout << ans << endl;
	sort(ALL(vv));
	for(int i=m-1;i<m*k-1;i+=m)
		cout << vv[i]+1 << " ";
}