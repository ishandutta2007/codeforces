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
const int N = 200000 + 7;
const int M = 30;
const int multipleTest = 0;
const double pi = acos(-1);

int n, m;
int light[N];
int k[N];
int cnt[N];

vector<int> show[N];
int pos[N];

void solve() {
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> light[i];
		--light[i];
		show[light[i]].push_back(i);
		pos[i] = sz(show[light[i]]);
	}
	int sum = 0;
	rep(i, 0, m) {
		cin >> k[i];
		sum += k[i];
	}
	
	
	set<int> all;
	
	rep(i, 0, m) if (!k[i]) all.insert(i + n + 1);
	
	int res = inf;
	
	for (int i = 0; i < n; ++i) {
		int x = light[i];
		if (k[x]) {
			if (pos[i] == k[x]) {
				all.insert(show[x][pos[i] - k[x]]);
			} else if (pos[i] > k[x]) {
				all.erase(show[x][pos[i] - k[x] - 1]);
				all.insert(show[x][pos[i] - k[x]]);
			}
		}
		
		if (all.size() == m) {
			res = min(res, (i - *all.begin() + 1) - sum);
		}
	}
	if (res == inf) res = -1;
	cout << res;
	

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