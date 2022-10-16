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

const int INF = 1e9 + 7, N = 2e5 + 7, M = 998244353;

int pw[N];
int a[N], b[N];

signed main()
{
	IO_OP;
	pw[0] = 1;
	for(int i=1;i<N;i++) pw[i] = pw[i-1] * 2 % M;

	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	ll ans = 0;
	for(int i = 0; i < n; i++)
		a[max(n, m) - n + i] = s[i] - '0';
	for(int i = 0; i < m; i++)
		b[max(n, m) - m + i] = t[i] - '0';
	int cnt = 0;
	for(int i = 0; i < max(n, m); i++) {
		cnt += b[i];
		ans += (ll)a[i] * cnt * pw[max(n, m)-i-1] % M;
	}
	ans %= M;
	cout << ans << endl;

	
}