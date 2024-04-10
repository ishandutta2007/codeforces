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

int a[100005];

int32_t main()
{
	IO_OP;
	
	int n, m, k, mx;
	cin >> n >> m >> k;
	for(int i=0;i<m;i++)
		cin >> a[i];
	mx = k;
	int l = 0, ans = 0;
	while(l < m) {
		int d = upper_bound(a+l, a+m, mx) - (a+l);
		if(d <= 0) {
			int lo = 1, hi = 1e18/k+1;
			while(lo<=hi) {
				int mi = (lo + hi) / 2;
				if(mx+mi*k >= a[l]) hi = mi - 1;
				else lo = mi + 1;
			}
			mx += lo * k;
			continue;
		}
		l += d;
		mx += d;
		ans++;
	}
	cout << ans << endl;
}