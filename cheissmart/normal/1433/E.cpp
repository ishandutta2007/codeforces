#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << (x) << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int fact(int n) {
	if(n == 0) return 1;
	return n * fact(n - 1);
}

int C(int n, int k) {
	return fact(n) / fact(k) / fact(n - k);
}

signed main()
{
	IO_OP;

	int n;
	cin >> n;
	int ans = C(n, n / 2) / 2 * fact(n / 2 - 1) * fact(n / 2 - 1);
	cout << ans << endl;

}