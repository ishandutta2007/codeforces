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

const int INF = 1e9 + 7;

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a+3);
		int r = a[0], g = a[1], b = a[2];
		b -= g;
		if(b > r + 1) cout << "No" << endl;
		else cout << "Yes" << endl;
	}	
	
}