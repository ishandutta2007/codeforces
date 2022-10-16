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
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 8;

int a[N], st[N][30], mxx[N];
pi s[N];

	int n, m;

int killed = 0, ans = 0;
void build() {
    for(int i=0;i<n;i++)
        st[i][0] = a[i];
    for(int j=1;j<20;j++)
        for(int i=0;i+(1<<j)-1 < n;i++)
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}
int qry(int l, int r) {
	int d = r - l + 1;
	int k = 32 - __builtin_clz(d) - 1;
	return max(st[l][k], st[r-(1<<k)+1][k]);
}
bool ok(int mm) {
	if(mm == 0) return true;
	int maxp = qry(killed, killed + mm - 1);
	int f = lower_bound(s, s+m, MP(maxp, -INF)) - s;
	if(f == m) return false;
	return mxx[f] >= mm;
}

void solve() {
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	build();
	cin >> m;
	for(int i=0;i<m;i++) 
		cin >> s[i].F >> s[i].S;
	sort(s, s+m);
	mxx[m-1] = s[m-1].S;
	for(int i=m-2;i>=0;i--)
		mxx[i] = max(mxx[i+1], s[i].S);
	killed = 0, ans = 0;
	while(killed < n) {
		int l = 0, r = n - killed;
		while(l <= r) {
			int m = (l + r) / 2;
			if(ok(m)) l = m + 1;
			else r = m - 1;
		}
		if(r == 0) {
			cout << -1 << endl;
			return;
		}
		killed += r;
		ans++;
	}
	cout << ans << endl;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}	
	
}