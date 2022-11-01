#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const int ma = 1024 * 1024;

int n;
//vector<pair<int, int> > d;

int ok[103][103], cc[103][103];
vector<pair<int, int> > pos;
string s[50];

bool okq(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= n || s[x][y] == 'o' || s[x][y] == 'x')
		re true;
	re false;
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	forn (i, n) {
		cin >> s[i];
	}
	int cnt = 0;
	forn (ik, n) {
		forn (jk, n) {
			if (s[ik][jk] == 'o') {
				cnt++;
				for (int i = -n; i <= n; i++) {
					for (int j = -n; j <= n; j++) {
						if (i == 0 && j == 0) continue;
						if (okq(ik + i, jk + j))
							ok[i + n][j + n]++;
					}
				}
				//pos.push_back(mp(i, j));
			}
		}
	}
	vector<pair<int, int> > ab;
	for (int i = -n; i <= n; i++) {
		for (int j = -n; j <= n; j++) {
				if (ok[i + n][j + n] == cnt) {
					ab.push_back(mp(i, j));
				}
	//		cout << ok[i + n][j + n] << " ";
		}
	//	cout << "\n";
	}
	forn (i, n) {
		forn (j, n) {
			if (s[i][j] == 'o') {
				for (auto v : ab) {
					if (i + v.fi >= 0 && j + v.se >= 0 && i + v.fi < n && j + v.se < n)
						cc[i + v.fi][j + v.se] = 1;			
				}
			}
		}
	}
	forn (i, n) {
		forn (j, n) {
			if ((cc[i][j] && s[i][j] == '.') || (cc[i][j] == 0 && s[i][j] == 'x')) {
				cout << "NO\n";
				re 0;
			}
		}
	}
	cout << "YES\n";
	for (int i = -n + 1; i < n; i++) {
		for (int j = -n + 1; j < n; j++) {
			if (ok[i + n][j + n] == cnt)
				cout << "x";
			else if (i == 0 && j == 0)
					cout << "o";
				else
					cout << ".";
		}
		cout << "\n";
	}
}