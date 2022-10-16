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

const int M = 1e9 + 7, N = 1e5 + 7;

V<pi> qs[N];
int basis[33], ans[N], pw[N], a[N];
int cnt;
void add(int x) {
	while(x) {
		int hb = __lg(x);
		if(basis[hb] == 0) {
			basis[hb] = x;
			cnt++;
		} else {
			x ^= basis[hb];
		}
	}
}

signed main()
{
	IO_OP;
	pw[0] = 1;
	for(int i=1;i<N;i++)
		pw[i] = pw[i-1] * 2 % M;

	int n, q;
	cin >> n >> q;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<q;i++) {
		int l, x;
		cin >> l >> x;
		qs[l-1].EB(x, i);
	}
	for(int i=0;i<n;i++) {
		add(a[i]);
		for(pi p:qs[i]) {
			int x = p.F;
			for(int j=29;j>=0;j--) {
				if(x>>j&1) {
					x ^= basis[j];
				}
			}
			ans[p.S] = x ? 0 : pw[i+1-cnt];
		}
	}
	for(int i=0;i<q;i++) cout << ans[i] << endl;

}