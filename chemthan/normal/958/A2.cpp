#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define sz(a) (int)(a).size()
#define rep(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define frep(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int inf = 129349823;
const ll linf  = 1ll * inf * inf;
const int N = 2000 + 7;
const int M = 1000000;
const int multipleTest = 0;
const double pi = acos(-1);


ll F[M];
ll base = rand() % inf;

int n, m;

string s[N];
long long hash_row[N];
ll block_hash_row[N];

ll hash_col[N];
ll block_hash_col[N];

ll get_next(ll prev_hash, ll cur, int len = 1) {
	return (prev_hash * F[len] + cur) % inf;
}

void solve() {
	F[0] = 1;
	rep(i, 1, M) F[i] = F[i - 1] * base % inf;
	
	
	cin >> n >> m;
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) {
		hash_row[i] = 0;
		for (char c : s[i]) hash_row[i] = get_next(hash_row[i], c);
	}
	
	rep(i, 0, n - m + 1) {
		if (i == 0) {
			rep(j, 0, m) block_hash_row[i] = get_next(block_hash_row[i], hash_row[i + j], m);
		} else {
			block_hash_row[i] = get_next(block_hash_row[i - 1], hash_row[i + m - 1], m);
			block_hash_row[i] = (block_hash_row[i] - hash_row[i - 1] * F[m * m] % inf + inf) % inf;
		}
	}
	
	
	rep(i, 0, m) {
		cin >> s[i];
		rep(j, 0, n - m + 1) {
			if (j == 0) {
				hash_col[j] = 0;
				rep(t, 0, m) {
					hash_col[j] = get_next(hash_col[j], s[i][j + t]);
					
				}
			} else {
				hash_col[j] = get_next(hash_col[j - 1], s[i][j + m - 1]);
				hash_col[j] = (hash_col[j] - s[i][j - 1] * F[m] % inf + inf) % inf;
			}
			block_hash_col[j] = get_next(block_hash_col[j], hash_col[j], m);
		}
	}
	
	rep(i, 0, n - m + 1) rep(j, 0, n - m + 1) if (block_hash_row[i] == block_hash_col[j]) {
		cout << i + 1 << ' ' << j + 1;
		return;
	}
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin);
	//    freopen("out.txt", "w", stdout);
#endif
	int Test = 1;
	if (multipleTest) {
		cin >> Test;
	}
	for(int i = 0; i < Test; ++i) {
		//		printf("Case #%d: ", i + 1);
		solve();
	}
#ifdef _LOCAL_
	cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "\n";
#endif
}