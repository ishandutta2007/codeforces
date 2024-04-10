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

pair<pi, int> a[100005];

int bit[200005];

int lowbit(int x) {
	return x & -x;
}

int qry(int x) {
	int ans = 0;
	while(x) {
		ans = max(ans, bit[x]);
		x -= lowbit(x);
	}
	return ans;
}

void upd(int x, int val) {
	while(x < 200005) {
		bit[x] = max(bit[x], val);
		x += lowbit(x);
	}
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	vi v;
	for(int i=0;i<n;i++) {
		cin >> a[i].F.S >> a[i].F.F >> a[i].S;
		v.PB(a[i].F.S);
		v.PB(a[i].F.F);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++) {
		a[i].F.F = lower_bound(v.begin(), v.end(), a[i].F.F) - v.begin() + 1;
		a[i].F.S = lower_bound(v.begin(), v.end(), a[i].F.S) - v.begin() + 1;
	}
	sort(a, a+n, greater<pair<pi, int>>());
	int ans = 0;
	for(int i=0;i<n;i++) {
		int x = a[i].F.F, y = a[i].F.S, h = a[i].S;
		int cans = qry(x-1) + h;
		upd(y, cans);
		ans = max(ans, cans);
	}
	cout << ans << endl;
}