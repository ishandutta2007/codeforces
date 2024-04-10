#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int side; cin >> side;
	vector<vector<ll>> grid(side, vector<ll>(side, 0));
	for (int i = 0; i < side; ++i) {
		for (int j = 0; j < side; ++j) {
			if ((i-j+side)&2LL) grid[i][j] = (1LL << (i+j));
			cout << grid[i][j] << " \n"[j==side-1];
		}
	}
	cout << flush;
	int nbQuery; cin >> nbQuery;
	for (int iQuery = 0; iQuery < nbQuery; ++iQuery) {
		ll sum; cin >> sum;
		cout << "1 1";
		int row = 0, col = 0;
		for (int diag = 0; diag < 2*side-2; ++diag) {
			ll should = sum&(1LL<<(diag+1));
			if (row+1<side && grid[row+1][col] == should) ++row;
			else ++col;
			cout << " " << row+1 << " " << col+1;
		}
		cout << endl << flush;
	}
}