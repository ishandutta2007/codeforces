#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'
#define int ll

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int q;
	cin >> q;
	while(q--) {
		int n, s = 0;
		cin >> n;
		for(int i=0;i<n;i++) {
			int t;
			cin >> t;
			if(t <= 2048)
				s += t;
		}
		if(s >= 2048) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	
	
}