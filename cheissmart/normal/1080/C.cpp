#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

ll black(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	ll tot = 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
	if(tot & 1) {
		if((x1+y1) & 1)
			return tot/2+1;
		else
			return tot/2;
	} else {
		return tot/2;
	}
}

ll white(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) return 0;
	ll tot = 1LL * (x2 - x1 + 1) * (y2 - y1 + 1);
	return tot - black(x1, y1, x2, y2);
}

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		swap(n, m);
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		ll b = black(1, 1, n, m);
		b += white(x3, y3, x4, y4);
		int l, r, u, d;
		l = max(x1, x3);
		r = min(x2, x4);
		d = max(y1, y3);
		u = min(y2, y4);
		b -= black(x1, y1, x2, y2) - black(l, d, r, u);
		cout << 1LL * n*m - b << " " << b << endl;
	}
}