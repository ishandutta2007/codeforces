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

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int32_t main()
{
	IO_OP;
	
	int a1, a2, k1, k2, n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if(k1 > k2) swap(k1, k2), swap(a1, a2);
	int mx = 0, mn;
	mn = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1));
	int r = min(a1, n / k1);
	mx += r;
	n -= r * k1;
	mx += n / k2;
	cout << mn << " " << mx << endl;
}