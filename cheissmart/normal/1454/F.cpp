#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) [&]() {
		int n;
		cin >> n;
		vi a(n);
		vi v;
		for(int i = 0; i < n; i++) cin >> a[i], v.PB(a[i]);
		sort(ALL(v));
		v.resize(unique(ALL(v)) - v.begin());
		V<vi> pos(n);
		for(int i = 0; i < n; i++) a[i] = lower_bound(ALL(v), a[i]) - v.begin(), pos[a[i]].PB(i);
		V<vi> st(n, vi(20));
		
		for(int i=0;i<n;i++)
	        st[i][0] = a[i];
	    
		for(int j=1;j<20;j++)
	        for(int i=0;i+(1<<j)-1 < n;i++)
	            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		auto qry = [&](int l, int r) {
			int d = r - l + 1;
			int k = 32 - __builtin_clz(d) - 1;
			return min(st[l][k], st[r-(1<<k)+1][k]);
		};
		int lb = 0, rb = n - 1;
		int mxl = a[0], mxr = a[n - 1]; 
		for(int i = min(mxl, mxr); i < n; i++) {
			while(lb + 1 < rb - 1) {
				if(a[lb + 1] < i) mxl = max(mxl, a[++lb]);
				else if(a[lb + 1] == i && mxl != i) mxl = max(mxl, a[++lb]);
				else break;
			}
			while(lb + 1 < rb - 1) {
				if(a[rb - 1] < i) mxr = max(mxr, a[--rb]);
				else if(a[rb - 1] == i && mxr != i) mxr = max(mxr, a[--rb]);
				else break;
			}
			if(mxl != i || mxr != i) continue;
			if(qry(lb + 1, rb - 1) == i) {
				cout << "YES" << endl;
				cout << lb + 1 << " " << n - (lb + 1) - (n - rb) << " " << n - rb << endl;
				return;
			}
			if(qry(lb + 1, rb - 1) > i) continue;
			while(lb + 1 < rb - 1)
				if(a[lb + 1] <= i) mxl = max(mxl, a[++lb]);
				else break;
			while(lb + 1 < rb - 1)
				if(a[rb - 1] <= i) mxr = max(mxr, a[--rb]);
				else break;
			if(qry(lb + 1, rb - 1) == i) {
				cout << "YES" << endl;
				cout << lb + 1 << " " << n - (lb + 1) - (n - rb) << " " << n - rb << endl;
				return;
			}
			if(qry(lb + 1, rb - 1) < i) continue;
			if(a[lb] == i && pos[i][0] < lb) {
				lb--;
				assert(qry(lb + 1, rb - 1) == i);
				cout << "YES" << endl;
				cout << lb + 1 << " " << n - (lb + 1) - (n - rb) << " " << n - rb << endl;
				return;
			} else if(a[rb] == i && pos[i].back() > rb) {
				rb++;
				assert(qry(lb + 1, rb - 1) == i);
				cout << "YES" << endl;
				cout << lb + 1 << " " << n - (lb + 1) - (n - rb) << " " << n - rb << endl;
				return;
			}
		}
		cout << "NO" << endl;
	}();

}