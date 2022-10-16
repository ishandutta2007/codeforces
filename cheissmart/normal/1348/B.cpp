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
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vi a(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		vi b = a;
		sort(ALL(b));
		b.resize(unique(ALL(b))-b.begin());
		if(b.size() > k) {
			cout << -1 << endl;
			continue;
		}
		cout << n * k << endl;
		for(int i = 1; i <= n; i++) {
			for(int j:b) cout << j << " ";
			for(int j=0;j<k-(int)b.size();j++) cout << 1 << " ";
		}
		cout << endl;
	}
	
}