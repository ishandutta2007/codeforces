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

int n;

bool ok(int m) {
	int nn = n, cnt = 0;
	while(nn) {
		cnt += min(nn, m);
		nn -= min(nn, m);
		nn -= nn / 10;
	}
	return cnt >= (n + 1) / 2;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	int l = 1, r = n;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m - 1;
		else l = m + 1;
	}
	cout << l << endl;
	
}