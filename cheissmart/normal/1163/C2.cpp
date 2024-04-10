#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int x[1005], y[1005];

int32_t main()
{
	IO_OP;
	
	int n, k = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> x[i] >> y[i];
	map<pi, int> m; 
	for(int i=0;i<n;i++) {
		map<pi, int> mm;
		for(int j=0;j<i;j++) {
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			int g = __gcd(dx, dy);
			dx /= g, dy /= g;
			if(dx < 0) dx = -dx, dy = -dy;
			if(dx == 0) dy = 1;
			mm[MP(dx, dy)]++;
		}
		for(auto p:mm)
			if(p.S == 1) m[p.F]++, k++;
	}
	int ans = k * (k - 1) / 2;
	for(auto p:m)
		ans -= p.S * (p.S - 1) / 2;
	cout << ans << endl;
}