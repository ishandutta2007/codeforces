#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 2e5 + 7;

int a[N];
int layer[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	int depth = 0;
	layer[0] = 1;
	for(int i = 1; i < n; i++) {
		int j = i;
		while(i + 1 < n && a[i + 1] > a[i]) i++;
		int cnt = i - j + 1;
		layer[depth]--;
		layer[depth + 1] += cnt;
		if(layer[depth] == 0 || i == n - 1) depth++;
	}
	cout << depth << endl;
	for(int i = 0; i <= depth ; i++) layer[i] = 0;
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) solve();

}