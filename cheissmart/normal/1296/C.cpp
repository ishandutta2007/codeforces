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

const int INF = 1e9 + 7, N = 2e5 + 7;

int x[N], y[N];

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		s = ' ' + s;
		for(int i=1;i<=n;i++) {
			x[i] = x[i-1];
			y[i] = y[i-1];
			if(s[i] == 'U') y[i]++;
			if(s[i] == 'D') y[i]--;
			if(s[i] == 'R') x[i]++;
			if(s[i] == 'L') x[i]--;			
		}
		map<pi, int> lst, vis;
		int l, r, mn = INF;
		for(int i=0;i<=n;i++) {
			if(vis[MP(x[i], y[i])]) {
				if(i - lst[MP(x[i], y[i])] < mn) {
					mn = i - lst[MP(x[i], y[i])];
					l = lst[MP(x[i], y[i])];
					r = i;
				}
			}
			vis[MP(x[i], y[i])] = 1;
			lst[MP(x[i], y[i])] = i;
		}
		if(mn == INF) cout << -1 << endl;
		else cout << l + 1 << " " << r << endl;
	}	

	
}