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

const int inf = 1e9 + 7;
const ll linf  = 1ll * inf * inf;
const int N = 100000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);


string s[N];
string x[N];

int n;

void rotate() {
	string t[N];
	rep(i, 0, n) {
		t[i] = "";
		rep(j, 0, n) t[i] += '0';
	}
	rep(i, 0, n) rep(j, 0, n) //swap(s[i][j], s[j][n - 1 - i]);
	t[i][j] = s[j][n - 1 - i];
	rep(i, 0, n) s[i] = t[i];
}

void flip() {
	rep(i, 0, n) rep(j, i + 1, n) swap(s[i][j], s[j][i]);
}

void solve() {
	cin >> n;
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) cin >> x[i];
	
	rep(t, 0, 4) {
		bool check = true;
		rep(i, 0, n) if (s[i] != x[i]) check = false;
		if (check) {
			puts("Yes");
			return;
		}
		::rotate();
	}
	
	::flip();
	
	rep(t, 0, 4) {
		bool check = true;
		rep(i, 0, n) if (s[i] != x[i]) check = false;
		if (check) {
			puts("Yes");
			return;
		}
		::rotate();
	}
	puts("No");
	
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