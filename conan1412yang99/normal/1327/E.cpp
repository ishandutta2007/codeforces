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

const int INF = 1e9 + 7, N = 2e5 + 7, M = 998244353;

int pw[N];

signed main()
{
	IO_OP;
	pw[0] = 1;
	for(int i=1;i<N;i++) pw[i] = pw[i-1] * 10 % M;

	int n;
	cin >> n;
	for(int i=1;i<n;i++) {
		int ans = 0;
		ans += (pw[n-i-1] * 9 * 9) % M * (n - i - 1) % M;
		ans += pw[n-i] * 18 % M;
		ans %= M;
		cout << ans << " ";
	}
	cout << 10 << endl;
}