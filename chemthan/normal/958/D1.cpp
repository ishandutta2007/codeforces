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

int gcd(int u, int v) {
	return u == 0 ? v : gcd(v % u, u);
}

map<ii, int> all;
int n;

vector<ii> data;

void solve() {
	scanf("%d\n", &n);
	rep(i, 0, n) {
		int u, v, c;
		scanf("(%d+%d)/%d\n",&u,&v,&c);
		int d = gcd(u + v, c);
		ii cur = {(u + v) / d, c / d};
		all[cur]++;
		data.push_back(cur);
	}
	for (auto x : data) {
		cout << all[x] << ' ';
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