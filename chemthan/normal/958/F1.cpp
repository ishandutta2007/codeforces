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

int n, m;
int light[N];
int k[N];
int cnt[N];

void solve() {
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> light[i];
		--light[i];
	}
	int sum = 0;
	rep(i, 0, m) {
		cin >> k[i];
		sum += k[i];
	}
	
	rep(i, 0, n - sum + 1) {
		rep(j, 0, m) cnt[j] = k[j];
		rep(j, 0, sum) cnt[light[i + j]]--;
		bool check = true;
		rep(j, 0, m) if (cnt[j] != 0) check = false;
		if (check) {
			puts("YES");
			return;
		}
	}
	puts("NO");
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