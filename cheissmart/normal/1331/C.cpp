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
	
	int a;
	cin >> a;
	int ans = 0;
	ans += (a >> 5 & 1) << 5;
	ans += (a >> 0 & 1) << 4;
	ans += (a >> 2 & 1) << 3;
	ans += (a >> 3 & 1) << 2;
	ans += (a >> 1 & 1) << 1;
	ans += (a >> 4 & 1) << 0;
	cout << ans << endl;
}