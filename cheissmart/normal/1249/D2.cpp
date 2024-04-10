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

const int INF = 1e9 + 7;

struct DS{
	int bit[200005], n;
	int lowbit(int x) {
		return x & -x;
	}
	void add(int i, int d) {
		while(i <= n) {
			bit[i] += d;
			i += lowbit(i);
		}
	}
	void add(int l, int r, int d) {
		add(l, d);
		add(r+1, -d);
	}
	int qry(int i) {
		int res = 0;
		while(i) {
			res += bit[i];
			i -= lowbit(i);
		}
		return res;
	}
} p;

pair<pi, int> a[200005];

int32_t main()
{
	IO_OP;
	p.n = 200004;
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n;i++) {
		cin >> a[i].F.F >> a[i].F.S;
		a[i].S = i + 1;
	}
	sort(a, a+n);
	set<pair<pi, int>> st; // (y, x)
	for(int i=0;i<n;i++)
		p.add(a[i].F.F, a[i].F.S, 1);
	vi ans;
	for(int i=1, j=0;i<200005;i++) {
		while(j < n && a[j].F.F == i) {
			st.insert({{a[j].F.S, a[j].F.F}, a[j].S});
			j++;
		}
		if(p.qry(i) > k) {
			int d = p.qry(i) - k;
			while(d--) {
				auto it = st.rbegin();
				int l = it -> F . S, r = it -> F . F;
				ans.PB(it -> S);
				p.add(l, r, -1);
				st.erase(*st.rbegin());
			}
		}
	}
	cout << ans.size() << endl;
	for(int e:ans) cout << e << " ";
}