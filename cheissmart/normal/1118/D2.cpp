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

const int INF = 1e9 + 7;

int a[200005], n, m;

bool ok(int x) {
	int w = 0;
	for(int i=0;i<n;i++) {
		w += max(0ll, a[i] - i / x);
	}
	return w >= m;
}

int32_t main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);
	reverse(a, a+n);
	int l = 1, r = n;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m - 1;
		else l = m + 1;
	}
	if(l == n + 1) cout << -1 << endl;
	else cout << l << endl;
}