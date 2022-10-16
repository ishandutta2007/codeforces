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

const int M = 998244353;

int dp[1000006];

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	int x = 1;
	while(x <= n) {
		if(x == n || x + 1 == n) {
			cout << 1 << endl;
			return 0;
		}
		if(x % 2 == 0) x = x + 1 + x;
		else x = x + 1 + x + 1;
	}
	cout << 0 << endl;
	
}