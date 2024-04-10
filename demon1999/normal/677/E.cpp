//batch scheduling 2002
#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#include <deque>
#include <iostream>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)
typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef vector<ll> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll cnn = 800, sz_g = 200000, pq = 100000000, md = 1000000007, inf = 1000000000LL, mod2 = 5000000, /*mod = inf + 7, */ma = 128 * 1024;

int n, mx[4001], ans[2000], cc[2000];

int qq[4][1002][1002][4];

string s[2000];

ll kk(ld p, ll o) {
 	ld k = log(2.000000) / log(3.00000);
 	if (p * k > o) re true;
 	re false;
}

int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("sum.in", "r", stdin);
	//freopen("game24.out", "w", stdout);
	cin >> n;
	forn (i, 4001) mx[i] = -1;
	bool ok = false;
	forn (i, n) {
		cin >> s[i];
		forn (j, n) {
			forn (pp, 4)
				qq[0][i + 1][j + 1][pp] = qq[0][i + 1][j][pp],
				qq[1][i + 1][j + 1][pp] = qq[1][i][j + 1][pp],
				qq[2][i + 1][j + 1][pp] = qq[2][i][j][pp],
				qq[3][i + 1][j + 1][pp] = qq[3][i][j + 2][pp];
			qq[0][i + 1][j + 1][s[i][j] - '0']++;
			qq[1][i + 1][j + 1][s[i][j] - '0']++;
			qq[2][i + 1][j + 1][s[i][j] - '0']++;
			qq[3][i + 1][j + 1][s[i][j] - '0']++;
			if (s[i][j] > '0') ok = true;
			//cout << qq[3][i + 1][j + 1][2] << " ";
		}
		//cout << endl;
	}
	if (!ok) {
		cout << 0;
		re 0;
	}
	forn (i, n) {
		forn (j, n) {
			//if (s[i][j] == '0') continue;
			int ld = 0, rd = min(min(i + 1, j + 1), min(n - i, n - j)) + 1;
			while (rd - ld > 1) {
				int mid = (ld + rd) / 2;
				if (qq[1][i + mid][j + 1][0] - qq[1][i - mid + 1][j + 1][0] || 
					qq[0][i + 1][j + mid][0] - qq[0][i + 1][j - mid + 1][0]) rd = mid;
				else ld = mid;
			}
			//cout << ld << " ";
			int a1 = qq[1][i + ld][j + 1][2] - qq[1][i - ld + 1][j + 1][2] + 
					qq[0][i + 1][j + ld][2] - qq[0][i + 1][j - ld + 1][2],
			   b1 = qq[1][i + ld][j + 1][3] - qq[1][i - ld + 1][j + 1][3] + 
					qq[0][i + 1][j + ld][3] - qq[0][i + 1][j - ld + 1][3];
			if (s[i][j] == '2') a1--;
			if (s[i][j] == '3') b1--;
			mx[a1] = max(mx[a1], b1);
			ld = 0; 
			rd = min(min(i + 1, j + 1), min(n - i, n - j)) + 1;
			//cout << ld << " " << rd << " " << i << " " << j << endl;
			while (rd - ld > 1) {
				int mid = (ld + rd) / 2;
				//cout << mid << " " << qq[2][i + mid][j + mid][0] - qq[2][i - mid + 1][j - mid + 1][0] << " " << 
					//qq[3][i + mid][j - mid + 1][0] << " " << qq[3][i - mid + 1][j + mid][0] << endl;
				if (qq[2][i + mid][j + mid][0] - qq[2][i - mid + 1][j - mid + 1][0] || 
					qq[3][i + mid][j - mid + 2][0] - qq[3][i - mid + 1][j + mid + 1][0]) rd = mid;
				else ld = mid;
			}
			a1 = qq[2][i + ld][j + ld][2] - qq[2][i - ld + 1][j - ld + 1][2] + 
				 qq[3][i + ld][j - ld + 2][2] - qq[3][i - ld + 1][j + ld + 1][2],
			b1 = qq[2][i + ld][j + ld][3] - qq[2][i - ld + 1][j - ld + 1][3] + 
				 qq[3][i + ld][j - ld + 2][3] - qq[3][i - ld + 1][j + ld + 1][3];
			if (s[i][j] == '2') a1--;
			if (s[i][j] == '3') b1--;
			mx[a1] = max(mx[a1], b1);
			//cout << i << " " << j << " " << a1 << " " << b1 << " " << " " << ld << endl;
		}
	}
 	ll a1 = 0, a2 = 0;
	forn (i, 4 * n) {
		if (mx[i] > -1) {
			if (mx[i] >= a2) {
				a1 = i;
				a2 = mx[i];
			} 
			else {
				if (kk(i - a1, a2 - mx[i])) {
					a1 = i;
					a2 = mx[i];
				}
			}
		}
		//cout << a1 << " " << a2 << endl;
	}
	ll ans = 1;
	forn (i, a1)
		ans = (ans * 2LL) % md;
	forn (i, a2)
		ans = (ans * 3LL) % md;
	cout << ans;
	re 0;
}