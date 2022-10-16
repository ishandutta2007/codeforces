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

const int INF = 1e9 + 7;

int ask(int l1, int r1, int l2, int r2) {
	cout << "? " << r1 - l1 + 1 << " " << r2 - l2 + 1 << '\n';
	for(int i = l1; i <= r1; i++) cout << i << " ";
	cout << '\n';
	for(int i = l2; i <= r2; i++) cout << i << " ";
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int magic = 0;

void solve() {
	magic++;

	int n;
	cin >> n;
	int i = 2;
	while(ask(1, i - 1, i, i) == 0) i++;
	// i is magnetized
	vi bad(n + 1);
	bad[i] = 1;
	for(int j = i + 1; j <= n; j++)
		if(ask(i, i, j, j))
			bad[j] = 1;
	int lb = 1, rb = i - 1;
	while(lb <= rb) {
		int mb = (lb + rb) / 2;
		if(ask(1, mb, i, i)) rb = mb - 1;
		else lb = mb + 1;
	}
	assert(lb < i);
	bad[lb] = 1;
	vi ans;
	for(int i = 1; i <= n; i++)
		if(!bad[i])
			ans.PB(i);
	cout << "! " << ans.size();
	for(int i:ans) cout << " " << i;
	cout << endl;
}


signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}