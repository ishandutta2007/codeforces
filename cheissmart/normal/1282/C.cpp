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

pi q[N];

signed main()
{
	IO_OP;
	
	int m;
	cin >> m;
	while(m--) {
		int n, T, a, b, ez = 0, hd = 0;
		cin >> n >> T >> a >> b;
		for(int i=0;i<n;i++) {
			cin >> q[i].S;
			if(q[i].S == 0) ez++;
			else hd++;
		}
		for(int i=0;i<n;i++) cin >> q[i].F;
		sort(q, q+n);
		q[n].F = T + 1;
		int ans = 0;
		int t = 0;
		if(q[0].F > 0){
			int more = q[0].F - 1;
			int cans = 0;
			int eztake = min(more / a, ez);
			cans += eztake;
			more -= eztake * a;
			int hdtake = min(more / b, hd);
			cans += hdtake;
			ans = max(ans, cans);
		}
		for(int i=0;i<n;i++) {
			if(q[i].S) t += b, hd--;
			else t += a, ez--;
			int tt = q[i].F;
			if(t >= q[i+1].F || tt == q[i+1].F) continue;
			int more = q[i+1].F - 1 - t;
			int cans = i + 1;
			int eztake = min(more / a, ez);
			cans += eztake;
			more -= eztake * a;
			int hdtake = min(more / b, hd);
			cans += hdtake;
			ans = max(ans, cans);
		}
		cout << ans << '\n';
	}	
	
}