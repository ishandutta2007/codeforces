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

const int INF = 1e9 + 7, N = 1000006;

int p[N], sz[N], a[N], l[N], r[N];

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

bool unite(int x, int y) {
	int rx = find(x), ry = find(y);
	if(rx == ry) return false;
	if(sz[rx] > sz[ry]) swap(rx, ry);
	p[rx] = ry, sz[ry] += sz[rx];
	return true;
}

signed main()
{
	IO_OP;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		p[i] = i;

	for(int i=1;i<=n;i++){
		cin >> l[i] >> r[i];
		a[l[i]] = i, a[r[i]] = -i;
	}
	int e = 0, ok = 1;
	set<pi> s;
	for(int i=1;i<=2*n;i++) {
		if(a[i] > 0) {
			for(pi p:s) {
				if(p.F < r[a[i]]) {
					if(!unite(a[i], p.S)) {
						ok = 0;
						break;
					}
					e++;
				} else {
					break;
				}
			}
			s.insert({r[a[i]], a[i]});
		} else {
			s.erase({r[-a[i]], -a[i]});
		}
		if(!ok) break;
	}
	if(ok && e == n - 1) cout << "YES" << endl;
	else cout << "NO" << endl;
}