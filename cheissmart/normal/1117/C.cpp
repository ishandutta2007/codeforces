#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

map<char, vector<int>> mv;
int sx[100005], sy[100005];
int x1, y1, x2, y2, n;

bool ok(int m) {
	int dx = (m / n) * sx[n-1] + (m % n ? sx[m % n - 1] : 0);
	int dy = (m / n) * sy[n-1] + (m % n ? sy[m % n - 1] : 0);
	int x = x1 + dx, y = y1 + dy;
	return abs(x-x2)+abs(y-y2) <= m;
}

signed main()
{
	IO_OP;
	
	mv['U'] = {0, 1};
	mv['D'] = {0, -1};
	mv['L'] = {-1, 0};
	mv['R'] = {1, 0};
	
	string s;
	cin >> x1 >> y1 >> x2 >> y2 >> n >> s;
	sx[0] = mv[s[0]][0], sy[0] = mv[s[0]][1];
	for(int i=1;i<n;i++) {
		sx[i] = sx[i-1] + mv[s[i]][0];
		sy[i] = sy[i-1] + mv[s[i]][1];
	}
	int l = 0, r = (1LL<<60);
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) {
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	if(l == (1LL<<60)+1) cout << -1 << endl;
	else cout << l << endl;
}