#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

vi G[N];

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		for(int i = 0; i < n; i++) G[i].PB(-1);
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x--;
			G[x].PB(i);
		}
		for(int i = 0; i < n; i++) G[i].PB(n);
		int mn = INF;
		for(int i = 0; i < n; i++) {
			if(G[i].size() > 2) {
				int cnt = 0;
				for(int j = 0; j < G[i].size() - 1; j++)
					if(G[i][j] + 1 != G[i][j + 1])
						cnt++;
				mn = min(mn, cnt);				
			}
		}
		cout << mn << endl;
		for(int i = 0; i < n; i++) G[i].clear();
	}
	
}