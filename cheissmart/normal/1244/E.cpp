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

int a[100005], p[100005], n, k, sm;
bool okk(int l, int r) {
	int req = 0;
	int j = lower_bound(a+1, a+n+1, l) - a - 1;
	if(j >= 1)
		req += l * j - p[j];
	j = upper_bound(a+1, a+n+1, r) - a;
	if(j <= n)
		req += (p[n] - p[j-1]) - r * (n - j + 1);
	return req <= k;
}
bool ok(int m) {
	for(int i=1;i<=n;i++)
		if(okk(a[i], a[i]+m) || okk(a[i]-m, a[i]))
			return true;
	return false;
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		sm += a[i];
	}

	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
		p[i] = a[i] + p[i-1];

	if(sm <= k) {
		cout << 0 << endl;
		return 0;
	}

	int l = 0, r = 1000000000;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m))
			r = m - 1;
		else
			l = m + 1;
	}
	cout << l << endl;

}