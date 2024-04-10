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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int a, b, n, s;
		cin >> a >> b >> n >> s;
		int aa = min(a, s/n);
		s -= aa * n;
		if(s <= b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
}