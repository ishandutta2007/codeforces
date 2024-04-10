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

const int INF = 2e9 + 7;

int a[200005], p[200005], n, k;

bool ok(int m) {
	int x = lower_bound(a, a+n, m) - a;
	if(x <= n / 2) return true;
	if(m * (x - n / 2) - (p[x-1] - p[n/2-1]) <= k) return true;
	return false;
}

int32_t main()
{
	IO_OP;

	cin >> n >> k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	if(n == 1) {
		cout << a[0] + k << endl;
		return 0;
	}
	sort(a, a+n);
	p[0] = a[0];
	for(int i=1;i<n;i++)
		p[i] = p[i-1] + a[i];
	int l = 0, r = INF;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << r << endl;
}