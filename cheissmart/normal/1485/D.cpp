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

const int INF = 1e9 + 7, N = 505;

int a[N][N];

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((i + j) & 1) {
				cout << 720720 - a[i][j] * a[i][j] * a[i][j] * a[i][j] << " ";
			} else {
				cout << 720720 << " ";
			}
		}
		cout << '\n';
	}

}