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

const int INF = 1e9 + 7;

int p[200005], n, x, a, y, b, k;

bool ok(int m) {
	int t=0, tt=0, ttt=0;
	for(int i=0;i<m;i++) {
		int j = i + 1;
		if(j % a == 0 && j % b == 0) t++;
		else if(j % a == 0) tt++;
		else if(j % b == 0) ttt++;
	}
	int r = 0;
	for(int i=0;i<t;i++) r += p[i]/100*(x+y);
	for(int i=t;i<t+tt;i++) r += p[i]/100*x;
	for(int i=t+tt;i<t+tt+ttt;i++) r += p[i]/100*y;
	return r >= k;
}

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> p[i];
		sort(p, p+n);
		reverse(p, p+n);
		cin >> x >> a >> y >> b >> k;
		if(x < y) {
			swap(x, y);
			swap(a, b);
		}
		int l = 1, r = n;
		while(l <= r) {
			int m = (l + r) / 2;
			if(ok(m)) r = m - 1;
			else l = m + 1;
		}
		if(l <= n) cout << l << endl;
		else cout << -1 << endl;
	}
		
}