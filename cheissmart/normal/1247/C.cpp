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

bool ok(int n, int k, int p) {
	int d = n - k * p;
	if(d <= 0) return false;
	int c = __builtin_popcount(d);
	if(d < k) return false;
	if(c <= k) return true;
	return false;
}

signed main()
{
	IO_OP;
	
	int n, p;
	cin >> n >> p;	
	for(int i=1;i<=100000;i++) {
		if(ok(n, i, p)) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}