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

const int INF = 1e9 + 7;

char a[303][303];

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		V<pi> cnt[3] = {};
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
				if(a[i][j] == 'X') cnt[(i + j) % 3].EB(i, j);
				else if(a[i][j] == 'O') cnt[(i + j + 1) % 3].EB(i, j);
			}
		int tot = cnt[0].size() + cnt[1].size() + cnt[2].size();
		for(int k = 0; k < 3; k++) {
			if(cnt[k].size() <= tot / 3) {
				for(pi p:cnt[k]) {
					a[p.F][p.S] ^= 'O' ^ 'X';
				}
				break;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) cout << a[i][j];
			cout << endl;
		}
	}
	
}