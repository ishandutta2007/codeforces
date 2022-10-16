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
	
	int n, b, p;
	cin >> n >> b >> p;
	int x = 0, y = n * p;
	while(n != 1) {
		int k = 1 << (__lg(n) - 1);
		x += k * (b + b + 1);
		n -= k;
	}
	cout << x << " " << y << endl;
	
}