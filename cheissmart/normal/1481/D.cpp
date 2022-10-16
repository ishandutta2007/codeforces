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

char a[1003][1003];

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	if(m & 1) {
		cout << "YES\n";
		for(int i = 0; i < m + 1; i++) {
			if(i & 1) cout << 2 << " ";
			else cout << 1 << " ";
		}
		cout << '\n';
	} else {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < i; j++) {
				if(a[i][j] == a[j][i]) {
					cout << "YES\n";
					for(int k = 0; k < m + 1; k++) {
						if(k & 1) cout << i + 1 << " ";
						else cout << j + 1 << " ";
					}
					cout << '\n';
					return;
				}
			}
		}
		if(n == 2) {
			assert(a[0][1] != a[1][0]);
			cout << "NO\n";
			return;
		} else {
			vi p({0, 1, 2});
			int x = 0, y = 1, z = 2;
			do {
				if(a[p[0]][p[1]] == a[p[1]][p[2]]) {
					x = p[0], y = p[1], z = p[2];
					break;
				}
			} while(next_permutation(ALL(p)));
			assert(a[x][y] == a[y][z]);
			int more = (m - 2) / 2;
			deque<int> ans({x, y, z});
			for(int i = 0; i < more; i++)
				ans.push_front(x ^ z ^ ans[0]);
			for(int i = 0; i < more; i++)
				ans.push_back(x ^ z ^ ans.back());
			assert(ans.size() == m + 1);
			cout << "YES\n";
			for(int i:ans) cout << i + 1 << " ";
			cout << '\n';
		}
	}
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	
}