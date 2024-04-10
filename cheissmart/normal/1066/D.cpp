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

const int INF = 1e9 + 7, N = 2e5 + 7;

int n, m, k;
int a[N];

bool ok(int st) {
	int cnt = 0, rem = 0;
	for(int i = st; i < n; i++) {
		if(a[i] > rem) {
			cnt++;
			rem = k - a[i];
		} else {
			rem -= a[i];
		}
	}
	return cnt <= m;
}

signed main()
{
	IO_OP;
	
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> a[i];	
	int l = 0, r = n - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m - 1;
		else l = m + 1;
	}
	cout << n - l << endl;

}