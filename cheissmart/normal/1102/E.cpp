#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define ALL(c) c.begin(),c.end()
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int N = 2e5 + 55;
int a[N], b[N], mx[N], mn[N], c[N];

int main()
{
	IO_OP;

	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		mn[i] = INF;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		b[i] = a[i];
	sort(b, b+n);
	int m = unique(b, b+n) - b;
	for(int i=0;i<n;i++)
		a[i] = lower_bound(b, b+m, a[i]) - b;
	for(int i=0;i<n;i++)
		mn[a[i]] = min(mn[a[i]], i), mx[a[i]] = i;
	for(int i=0;i<m;i++) {
		c[mn[i]] = mx[i];
	}
	int ans = 1, cov = 0;
	for(int i=0;i<n;i++) {
		if(i > cov) {
			ans *= 2;
			ans %= 998244353;
		}
		cov = max(cov, c[i]);
	}
	cout << ans << endl;
}