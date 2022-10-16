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

const int INF = 1e9 + 7, N = 200005;

int x[N], v[N], a[N];

struct BIT{
	int bit[N]; // [1, n]
	BIT() {
		memset(bit, 0, sizeof bit);
	}
	int lowbit(int x) {
		return x & -x;
	}
	void add(int i, int d = 1) {
		while(i < N) {
			bit[i] += d;
			i += lowbit(i);
		}
	}
	int qry(int i) {
		int res = 0;
		while(i) {
			res += bit[i];
			i -= lowbit(i);
		}
		return res;
	}
} sum, cnt;

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> x[i];
	vi u;
	for(int i=0;i<n;i++) {
		cin >> v[i];
		u.PB(v[i]);
	}
	sort(ALL(u));
	u.resize(unique(ALL(u))-u.begin());
	for(int i=0;i<n;i++)
		v[i] = lower_bound(ALL(u), v[i]) - u.begin() + 1;
	iota(a, a+n, 0);
	sort(a, a+n, [](int i, int j) {
		return x[i] < x[j];
	});
	int ans = 0;
	for(int i=0;i<n;i++) {
		ans += cnt.qry(v[a[i]]) * x[a[i]] - sum.qry(v[a[i]]);
		sum.add(v[a[i]], x[a[i]]);
		cnt.add(v[a[i]], 1);
	}
	cout << ans << endl;
}