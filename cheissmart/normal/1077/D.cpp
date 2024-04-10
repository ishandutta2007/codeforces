#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[200005], n, k;

bool ok(int m) {
	int ct = 0;
	for(int i=0;i<200005;i++)
		ct += a[i]/m;
	return ct >= k;
}

int main()
{
	IO_OP;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		a[t]++;
	}
	vector<pi> v;
	for(int i=0;i<200005;i++){
		if(a[i]) {
			v.PB({a[i], i});
		}
	}
	int l = 1, r = n;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) l = m + 1;
		else r = m - 1;
	}
	int ct = 0;
	for(int i=0;i<200005;i++) {
		while(a[i] >= r) {
			cout << i << " ";
			a[i] -= r;
			ct++;
			if(ct == k) return 0;
		}
	}
}