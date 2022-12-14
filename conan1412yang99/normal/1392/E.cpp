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

const int INF = 1e9 + 7, N = 30;

int a[N][N];

signed main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == 0 && j == 0) continue;
			if(i == n - 1 && j == n - 1) continue;
			int x = 1LL << (i + j - 1);
			if(i%2==0) a[i][j] = x;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while(q--) {
		int k;
		cin >> k;
		int x = 0, y = 0;
		cout << x + 1 << " " << y + 1 << endl;
		for(int i = 0; i < 2 * n - 2; i++) {
			if(x == n - 1) y++;
			else if(y == n - 1) x++;
			else {
				if((a[x+1][y] && (k & a[x+1][y]) == a[x+1][y]) || (a[x][y+1] && (k & a[x][y+1]) != a[x][y+1])) x++;
				else y++;
			}
			cout << x + 1 << " " << y + 1 << endl;
		}
	}

}