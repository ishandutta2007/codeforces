#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, K = 13, N = 1003;

int orz[K]; // or of all numbers whose i-th bit is 0
int mp[N];

int qry(vi v) {
	if(v.empty()) return 0;
	cout << "? " << v.size();
	for(int i:v) cout << " " << i + 1; // 1-indexed
	cout << endl;
	int res;
	cin >> res;
	return res;
}

signed main()
{
	// IO_OP;
	
	int n;
	cin >> n;
	for(int i = 0, j = 0; j < n && i < (1 << K); i++) {
		if(__builtin_popcount(i) != K / 2) continue;
		mp[j++] = i;
	}
	for(int j = 0; j < K; j++) {
		vi v;
		for(int i = 0; i < n; i++)
			if((mp[i] >> j & 1) == 0) v.PB(i);
		orz[j] = qry(v);
	}

	vi ans;
	for(int i = 0; i < n; i++) {
		int tt = 0;
		for(int j = 0; j < K; j++) {
			if(mp[i] >> j & 1) {
				tt |= orz[j];
			}
		}
		ans.PB(tt);
	}

	cout << "!";
	for(int i:ans) cout << " " << i;
	cout << endl;
}