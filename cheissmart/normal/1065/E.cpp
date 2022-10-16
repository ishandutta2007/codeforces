#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 998244353;

int b[200005];

ll pw(int a, int b) {
	if(b == 0) return 1 % M;
	ll t = pw(a, b/2);
	if(b & 1) return t * t % M * a % M;
	else return t * t % M;
}

int main()
{
	IO_OP;
	
	int n, m, a;
	ll ans = 1;
	cin >> n >> m >> a;
	for(int i=1;i<=m;i++)
		cin >> b[i];
	sort(b+1, b+m+1);
	int inv2 = pw(2, M - 2);
	for(int i=1;i<=m;i++) {
		int p = pw(a, b[i] - b[i-1]);
		ans *= ((pw(a, (b[i] - b[i-1]) * 2) - p + M) % M * inv2 % M + p) % M;
		ans %= M;
	}
	ans *= pw(a, n - 2*b[m]);
	ans %= M;
	cout << ans << endl;
}