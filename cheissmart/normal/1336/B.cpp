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

const int INF = 5e18 + 7, N = 1e5 + 7;

int a[N], b[N], c[N];

int go(int x, int y, int z) {
	return (x-y)*(x-y) + (x-z)*(x-z) + (y-z)*(y-z);
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int na, nb, nc;
		cin >> na >> nb >> nc;
		for(int i = 0; i < na; i++) cin >> a[i];
		for(int i = 0; i < nb; i++) cin >> b[i];
		for(int i = 0; i < nc; i++) cin >> c[i];
		sort(a, a+na);
		sort(b, b+nb);
		sort(c, c+nc);
		int ans = INF;
		for(int i = 0; i < na; i++) {
			int aa = a[i];
			vi bs, cs;
			{
				int bi = lower_bound(b, b+nb, aa) - b;
				if(bi < nb) bs.PB(b[bi]);
				bi = upper_bound(b, b+nb, aa) - b - 1;
				if(bi >= 0) bs.PB(b[bi]);
			}
			{
				int ci = lower_bound(c, c+nc, aa) - c;
				if(ci < nc) cs.PB(c[ci]);
				ci = upper_bound(c, c+nc, aa) - c - 1;
				if(ci >= 0) cs.PB(c[ci]);
			}
			for(int bb:bs) {
				int mid = (aa + bb) / 2;
				int ci = lower_bound(c, c+nc, mid) - c;
				if(ci < nc) cs.PB(c[ci]);
				ci = upper_bound(c, c+nc, mid) - c - 1;
				if(ci >= 0) cs.PB(c[ci]);
			}
			for(int cc:cs) {
				int mid = (aa + cc) / 2;
				int bi = lower_bound(b, b+nb, mid) - b;
				if(bi < nb) bs.PB(b[bi]);
				bi = upper_bound(b, b+nb, mid) - b - 1;
				if(bi >= 0) bs.PB(b[bi]);
			}
			for(int bb:bs)
				for(int cc:cs)
					ans = min(ans, go(aa, bb, cc));
		}
		cout << ans << '\n';
	}	
	
}