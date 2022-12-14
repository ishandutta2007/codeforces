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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi a, b;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(t & 1) b.PB(t);
		else a.PB(t);
	}
	sort(ALL(a)), sort(ALL(b));
	int r = min(a.size(), b.size()) + 1;
	int ans = 0;
	for(int i=0;i<(int)a.size()-r;i++)
		ans += a[i];
	for(int i=0;i<(int)b.size()-r;i++)
		ans += b[i];
	cout << ans << endl;
	
}