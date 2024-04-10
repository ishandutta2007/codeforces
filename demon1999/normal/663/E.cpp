#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 256 * 1024;

int n, m, ans;
int nm = 1;
int go[2][1024 * 1024 * 2], cnt[1024 * 1024 * 2][21]; 
string s[20];


void dfs(int nu) {
	forn (j, 2) {
		if (go[j][nu] != -1) {
			dfs(go[j][nu]);
			forn (i, n + 1)
				if (i >= j) cnt[nu][i] += cnt[go[j][nu]][i - j];
		}
	}
}

int kk = 0;
void dfs1(int nu, int h) {
	if (h == kk) {
		swap(go[0][nu], go[1][nu]);
	}
	if (h < kk) {
		forn (j, 2)
			if (go[j][nu] != -1)
				dfs1(go[j][nu], h + 1);
	}
	forn (i, n - h + 1)
		cnt[nu][i] = 0;
	forn (j, 2) {
		if (go[j][nu] != -1) {
			if (j) {
				for (int i = 1; i <= n - h; i++) {
					cnt[nu][i] += cnt[go[j][nu]][i - 1];
				}
			} else
				for (int i = 0; i <= n - h; i++) {
					cnt[nu][i] += cnt[go[j][nu]][i];
				}
		}	
	}
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
//	cin >> n >> m;
	scanf("%d%d", &n, &m);
	forn (i, n) {
		char c = getchar();
		while (c < '0' || c > '1')
			c = getchar();
		while (c >= '0' && c <= '1') {
			s[i] += c;
			c = getchar();
		}
	}
	go[0][0] = go[1][0] = -1;
	forn (j, m) {
		int q = 0;
		for (int i = 0; i < n; i++) {
			if (go[s[i][j] - '0'][q] == -1) {
				go[s[i][j] - '0'][q] = nm;
				go[0][nm] = go[1][nm] = -1;
				nm++;
			}
			q = go[s[i][j] - '0'][q];
		}
		cnt[q][0]++;
	}
	dfs(0);
	ans = n * m;
	forn (i, (1 << n)) {
		int ann = 0;
		forn (j, n + 1) {
	//		cout << cnt[j][0] << " ";
			ann += cnt[0][j] * min(n - j, j);
		}
	//	cout << "\n";
		ans = min(ans, ann);
		int k = i + 1, c = 0;
		while (k) {
			if (k % 2) break;
			c++;
			k /= 2;
		}
		if (i + 1 == (1 << n)) break;
		kk = c;
		//cout << c << " ";
		dfs1(0, 0);
		//cout << ans << " ";
	}
	cout << ans;
}