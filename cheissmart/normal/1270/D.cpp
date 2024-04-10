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

const int INF = 1e9 + 7, M = 1000000007, P = 55531;

int a[505];
signed main()
{
	int n, k;
	cin >> n >> k;
	if(k == 1) {
		cout << "! 1" << endl;
		return 0;
	}
	set<int> s;
	for(int i=1;i<=n;i++)
		s.insert(i);
	V<pi> can;
	while(s.size() >= k) {
		vi v;
		for(int i:s) {
			if(v.size() == k) break;
			v.PB(i);
		}
		cout << "? ";
		for(int i=0;i<k;i++)
			cout << v[i] << " ";
		cout << endl;
		int pos, val;
		cin >> pos >> val;
		can.EB(val, pos);
		s.erase(pos);
	}
	sort(ALL(can));
	assert(can.size() >= 2);
	int x = can[0].S, y = can[1].S;
	int ans = 1;
	for(int i:s) {
		cout << "? ";
		for(int j:s) if(j != i) cout << j << " ";
		cout << x << " " << y << endl;
		int pos, val;
		cin >> pos >> val;
		if(pos == y) ans++;
	}
	cout << "! " << ans << endl;
}