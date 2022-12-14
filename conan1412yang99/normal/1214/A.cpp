#include <bits/stdc++.h>
#define F first
#define S second
#define ALL(v) (v).begin(), (v).end()
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef long long ll;

const int INF = 1e9 + 7;

int32_t main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n, d, e;
	cin >> n >> d >> e;
	int ans = INF;
	for(int i=0;i*d<=n;i++) {
		int r = n - i * d;
		r %= e * 5;
		ans = min(ans, r);
	}
	cout << ans << endl;
	
}