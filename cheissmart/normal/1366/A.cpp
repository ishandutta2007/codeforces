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
		int a, b;
		cin >> a >> b;
		int ans = 0;
		if(a > b) swap(a, b);
		int x = b - a;
		if(x >= a) {
			cout << a << endl;
		} else {
			a -= x;
			b -= 2 * x;
			cout << a / 3 * 2 + x + (a % 3 == 2 ? 1 : 0) << endl;			
		}
	}	
	
}